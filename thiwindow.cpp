#include "thiwindow.h"
#include "ui_thiwindow.h"
#include "collectionbwindow.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QMenu>
#include <QMessageBox>

thiwindow::thiwindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::thiwindow)
{
    ui->setupUi(this);
    collectionBox = nullptr;
    this->setFixedSize(1350, 1000);
    this->setWindowTitle("Stock");

    db.setDatabaseName("vending.db");
    if (!db.open()) {
        qDebug() << "Error: Could not open database:" << db.lastError().text();
    } else {
        qDebug() << "Database connection established!";
        populateList();
        initializeDatabaseForChangeBox();
        initializeDatabaseForPurchaseHistory();
        populateListChange();
    }

    // Enable scrolling in the scroll area
    ui->scrollArea_2->setWidgetResizable(true);

    // Connect custom context menu signal to the handler
    ui->scrollArea_2->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->scrollArea_2, &QWidget::customContextMenuRequested,
            this, &thiwindow::on_scrollArea_2_customContextMenuRequested);
}


thiwindow::~thiwindow()
{
    if (db.isOpen()) {
        db.close();
    }
    delete ui;
}



void thiwindow::populateList()
{
    QSqlQuery query("SELECT id, product_name, price, stock FROM STOCK_67011073", db);
    if (!query.exec()) {
        qDebug() << "Error fetching data:" << query.lastError().text();
        return;
    }

    QWidget *containerWidget = new QWidget();
    QGridLayout *layout = new QGridLayout(containerWidget);


    layout->setHorizontalSpacing(20); // Set horizontal spacing between columns
    layout->setVerticalSpacing(80);

    int row = 0, col = 0;
    while (query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        int price = query.value(2).toInt();
        int stock = query.value(3).toInt();

        createProductWidget(containerWidget, id, name, price, stock, row, col);

        col++;
        if (col > 3) { // 4 columns per row
            col = 0;
            row++;
        }
    }

    // Replace any existing widget in the scroll area and set this new container widget
    if (ui->scrollArea_2->widget()) {
        delete ui->scrollArea_2->widget();
    }

    ui->scrollArea_2->setWidget(containerWidget);
    ui->scrollArea_2->setWidgetResizable(true);
}


void thiwindow::createProductWidget(QWidget *parent, int id, const QString &name, int price, int stock, int row, int col)
{
    // Create the button and labels
    QPushButton *button = new QPushButton("Refill Max", parent);
    QLabel *nameLabel = new QLabel(name, parent);
    QLabel *priceLabel = new QLabel(QString::number(price) + " ฿", parent);
    QLabel *stockLabel = new QLabel("Stock: " + QString::number(stock), parent);


    // Set the style for the labels and button
    QString style = "font: 700 12pt;";
    nameLabel->setStyleSheet(style);
    priceLabel->setStyleSheet(style);
    stockLabel->setStyleSheet(style);
    button->setStyleSheet(style);

    // Set the fixed size for the button
    button->setFixedSize(100, 45);

    connect(button, &QPushButton::clicked, this, [=]() {
        refillStock(id);
 });
    // Create a vertical layout to arrange the labels and button
    QVBoxLayout *productLayout = new QVBoxLayout();
    productLayout->addWidget(nameLabel, 0, Qt::AlignCenter);
    productLayout->addWidget(priceLabel, 0, Qt::AlignCenter);
    productLayout->addWidget(stockLabel, 0, Qt::AlignCenter);
    productLayout->addWidget(button, 0, Qt::AlignCenter);


    QGridLayout *gridLayout = qobject_cast<QGridLayout*>(parent->layout());
    if (gridLayout) {
        gridLayout->addLayout(productLayout, row, col);
    }
}


void thiwindow::on_scrollArea_2_customContextMenuRequested(const QPoint &pos)
{
    QMenu *menu = new QMenu(this);
    QAction *action1 = menu->addAction("Action 1");
    QAction *action2 = menu->addAction("Action 2");

    connect(action1, &QAction::triggered, this, [](){
        qDebug() << "Action 1 triggered!";
    });
    connect(action2, &QAction::triggered, this, [](){
        qDebug() << "Action 2 triggered!";
    });

    menu->exec(ui->scrollArea_2->mapToGlobal(pos));
}



void thiwindow::initializeDatabaseForChangeBox()
{
    QSqlQuery query(db);
    QString createTableQuery = R"(
        CREATE TABLE IF NOT EXISTS CHANGE_BOX (
            denomination TEXT,
            count INTEGER
        )
    )";

    if (!query.exec(createTableQuery)) {
        qDebug() << "Error creating table:" << query.lastError().text();
        return;
    }

    // Check if data already exists
    query.prepare("SELECT COUNT(*) FROM CHANGE_BOX");
    if (query.exec() && query.next() && query.value(0).toInt() > 0) {
        qDebug() << "CHANGE_BOX table already populated.";
        return;
    }

    struct Change {
        const char* denomination;
        int count;
    };

    Change change[] = {
                       {"1฿", 40}, {"2฿", 40}, {"5฿", 40}, {"10฿", 30},
                       {"20฿", 30}, {"50฿", 20}, {"100฿", 20},
                       };

    for (const auto &cha : change) {
        query.prepare("INSERT INTO CHANGE_BOX (denomination, count) VALUES (?, ?)");
        query.addBindValue(QString(cha.denomination));
        query.addBindValue(cha.count);
        if (!query.exec()) {
            qDebug() << "Error inserting data:" << query.lastError().text();
        }
    }
}

void thiwindow::populateListChange()
{
    QSqlQuery query("SELECT denomination, count FROM CHANGE_BOX", db);
    if (!query.exec()) {
        qDebug() << "Error fetching data:" << query.lastError().text();
        return;
    }

    QWidget *containerWidget = new QWidget();
    QGridLayout *layout = new QGridLayout(containerWidget);


    layout->setHorizontalSpacing(10); // Adjust column spacing
    layout->setVerticalSpacing(5);

    int row = 0, col = 0;
    while (query.next()) {
        QString denomination = query.value(0).toString();
        int count = query.value(1).toInt();

        // Debug: Log fetched data
        qDebug() << "Denomination:" << denomination << ", Count:" << count;

        createProductWidgetChange(containerWidget, denomination, count, row, col);

        col++;
        if (col > 3) { // Two columns per row
            col = 0;
            row++;
        }
    }

    if (ui->scrollArea_3->widget()) {
        delete ui->scrollArea_3->widget();
    }

    ui->scrollArea_3->setWidget(containerWidget);
    ui->scrollArea_3->setWidgetResizable(true);

    // Debug: Confirm container widget was added
    qDebug() << "Container widget added to scrollArea_3.";
}

void thiwindow::createProductWidgetChange(QWidget *parent, const QString &denomination, int count, int row, int col)
{
    QPushButton *button = new QPushButton("Refill Max", parent);
    QLabel *denominationLabel = new QLabel(denomination, parent);
    QLabel *countLabel = new QLabel("Count: " + QString::number(count), parent);

    QString style = "font: 700 12pt; margin: 0; padding: 0;";
    denominationLabel->setStyleSheet(style);
    countLabel->setStyleSheet(style);
    button->setFixedSize(100, 45);
    button->setStyleSheet(style);

    connect(button, &QPushButton::clicked, this, [=]() {
        refillDenomination(denomination);
    });

    QVBoxLayout *denominationLayout = new QVBoxLayout();
    denominationLayout->addWidget(denominationLabel, 0, Qt::AlignCenter);
    denominationLayout->addWidget(countLabel, 0, Qt::AlignCenter);
    denominationLayout->addWidget(button, 0, Qt::AlignCenter);


    QGridLayout *gridLayout = qobject_cast<QGridLayout*>(parent->layout());
    if (gridLayout) {
        gridLayout->addLayout(denominationLayout, row, col);
        qDebug() << "Added widget to row:" << row << ", col:" << col;
    } else {
        qDebug() << "Error: Parent does not have a valid QGridLayout.";
    }
}

void thiwindow::on_pushButton_4_clicked()
{
    collectionbwindow collectionwin;
    collectionwin.setModal(true);
    collectionwin.exec();
}


void thiwindow::initializeDatabaseForPurchaseHistory()
{
    QSqlQuery query(db);
    QString createTableQuery = R"(
        CREATE TABLE IF NOT EXISTS PURCHASE_HISTORY (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            product_name TEXT,
            price INTEGER,
            timestamp DATETIME DEFAULT CURRENT_TIMESTAMP
        )
    )";

    if (!query.exec(createTableQuery)) {
        qDebug() << "Error creating PURCHASE_HISTORY table:" << query.lastError().text();
    } else {
        qDebug() << "PURCHASE_HISTORY table initialized successfully.";
    }
}


void thiwindow::refillStock(int id)
{
    // First, check the current stock level
    QSqlQuery query(db);
    query.prepare("SELECT stock FROM STOCK_67011073 WHERE id = ?");
    query.addBindValue(id);

    if (!query.exec()) {
        qDebug() << "Error fetching stock for ID" << id << ":" << query.lastError().text();
        return;
    }

    if (query.next()) {
        int currentStock = query.value(0).toInt();

        // Check if stock is already maxed out (20)
        if (currentStock >= 20) {
            QMessageBox::information(this, "Stock Update", "STOCK ALREADY MAXED OUT");
            return;
        }

        // Update stock to the max value (20)
        query.prepare("UPDATE STOCK_67011073 SET stock = 20 WHERE id = ?");
        query.addBindValue(id);

        if (!query.exec()) {
            qDebug() << "Error refilling stock for ID" << id << ":" << query.lastError().text();
            return;
        }

        qDebug() << "Stock refilled for ID:" << id;
        QMessageBox::information(this, "Stock Update", "Stock refilled to maximum!");

        // Refresh the UI
        populateList();
    }
}



void thiwindow::refillDenomination(const QString &denomination)
{
    int maxCount = getMaxCountForDenomination(denomination);
    if (maxCount == 0) {
        qDebug() << "Invalid denomination:" << denomination;
        return;
    }

    // Retrieve the current count from the database
    QSqlQuery query(db);
    query.prepare("SELECT count FROM CHANGE_BOX WHERE denomination = ?");
    query.addBindValue(denomination);

    if (!query.exec() || !query.next()) {
        qDebug() << "Error fetching data for denomination" << denomination << ":" << query.lastError().text();
        return;
    }

    int currentCount = query.value(0).toInt();

    // If count is already at max, show message and exit
    if (currentCount >= maxCount) {
        QMessageBox::information(this, "Denomination Update", "COUNT ALREADY MAXED OUT!");
        return;
    }

    // Update the count to the maximum allowed
    QSqlQuery updateQuery(db);
    updateQuery.prepare("UPDATE CHANGE_BOX SET count = ? WHERE denomination = ?");
    updateQuery.addBindValue(maxCount);
    updateQuery.addBindValue(denomination);

    if (!updateQuery.exec()) {
        qDebug() << "Error updating denomination for" << denomination << ":" << updateQuery.lastError().text();
        return;
    }

    QMessageBox::information(this, "Denomination Update", "Denomination stock refilled to max!");

    // Refresh the UI
    populateListChange();
}

// Optimized function using QMap
int thiwindow::getMaxCountForDenomination(const QString &denomination)
{
    static const QMap<QString, int> maxCounts {
        {"1฿", 40}, {"2฿", 40}, {"5฿", 40}, {"10฿", 30},
        {"20฿", 30}, {"50฿", 20}, {"100฿", 20}
    };

    return maxCounts.value(denomination, 0); // Default to 0 if not found
}


void thiwindow::on_openCollectionBox_clicked()
{
    if (!db.isOpen()) {
        qDebug() << "Database is closed. Cannot open collection box!";
        return;
    }

    if (!collectionBox) {
        collectionBox = new collectionbwindow(this);
        connect(collectionBox, &collectionbwindow::collectionClosed, this, &thiwindow::handleCollectionClosed);
    }

    collectionBox->show(); // Show the collection box
}

void thiwindow::handleCollectionClosed()
{
    qDebug() << "Collection Box closed. Re-enabling thiwindow.";
    this->setEnabled(true); // Ensure thiwindow regains focus


    populateList();
    populateListChange();

}


