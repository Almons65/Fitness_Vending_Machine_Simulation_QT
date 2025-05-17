#include "secwindow.h"
#include "ui_secwindow.h"
#include "collectionbwindow.h"
#include <QSqlQuery>
#include <QDebug>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QMenu>
#include <QMessageBox>

secwindow::secwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secwindow)
{
    ui->setupUi(this);
    this->setFixedSize(1110, 990);
    this->setWindowTitle("UserMode");

    // Set up the database connection
    db.setDatabaseName("vending.db");
    if (!db.open()) {
        qDebug() << "Error: Could not open database:" << db.lastError().text();
    } else {
        qDebug() << "Database connection established!";
        initializeDatabase();
        populateList();
    }

    // Enable scrolling in the scroll area
    ui->scrollArea_2->setWidgetResizable(true);

    // Connect custom context menu signal to the handler
    ui->scrollArea_2->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->scrollArea_2, &QWidget::customContextMenuRequested,
            this, &secwindow::on_scrollArea_2_customContextMenuRequested);
}

secwindow::~secwindow()
{
    db.close();
    delete ui;
}

void secwindow::initializeDatabase()
{
    QSqlQuery query(db);
    QString createTableQuery = R"(
        CREATE TABLE IF NOT EXISTS STOCK_67011073 (
            id INTEGER PRIMARY KEY,
            product_name TEXT,
            price INTEGER,
            stock INTEGER
        )
    )";

    if (!query.exec(createTableQuery)) {
        qDebug() << "Error creating table:" << query.lastError().text();
    }

    struct Product {
        int id;
        const char* name;
        int price;
        int stock;
    };

    Product products[] = {
        {1, "Protein Shake", 80, 20}, {2, "Protein Bar", 30, 20},
        {3, "Energy Drink", 30, 20}, {4, "Beef Jerky", 70, 20},
        {5, "Protein Cookies", 65, 20}, {6, "Roasted Nuts", 50, 20},
        {7, "Hard Boiled Eggs", 40, 20}, {8, "Protein Chips", 60, 20},
        {9, "Plant-Based Protein Shake", 85, 20}, {10, "Greek Yogurt Drink", 60, 20},
        {11, "Caffeine Gum", 40, 20}, {12, "Rice Cake", 35, 20},
        {13, "Oatmeal Cup", 50, 20}, {14, "Banana Chips", 40, 20},
        {15, "Chocolate Milk", 55, 20}, {16, "Dark Chocolate", 50, 20},
        {17, "Protein Pudding", 70, 20}, {18, "Coconut Water", 50, 20},
        {19, "Matcha Green Tea", 60, 20}, {20, "Seaweed Snack", 40, 20}
    };

    for (const auto &prod : products) {
        query.prepare("INSERT INTO STOCK_67011073 (id, product_name, price, stock) VALUES (?, ?, ?, ?)");
        query.addBindValue(prod.id);
        query.addBindValue(QString(prod.name));
        query.addBindValue(prod.price);
        query.addBindValue(prod.stock);
        query.exec();
    }
}

void secwindow::populateList()
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


void secwindow::createProductWidget(QWidget *parent, int id, const QString &name, int price, int stock, int row, int col)
{
    // Create the button and labels
    QPushButton *button = new QPushButton(QString::number(id), parent);
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
    button->setFixedSize(60, 35);

    // Create a vertical layout to arrange the labels and button
    QVBoxLayout *productLayout = new QVBoxLayout();
    productLayout->addWidget(nameLabel, 0, Qt::AlignCenter);
    productLayout->addWidget(priceLabel, 0, Qt::AlignCenter);
    productLayout->addWidget(stockLabel, 0, Qt::AlignCenter);
    productLayout->addWidget(button, 0, Qt::AlignCenter);

    // Connect button click to update the label2 with the id
    connect(button, &QPushButton::clicked, this, [this, id, name, price](){
        ui->label_2->setText(QString::number(id));
        ui->label_2->setAlignment(Qt::AlignCenter);
        ui->label_3->setText(name);
        ui->label_3->setAlignment(Qt::AlignCenter);
        ui->label_4->setText(QString::number(price) + " ฿");
        ui->label_4->setAlignment(Qt::AlignCenter);

        remainingBalance = price;
    });

    // Add the vertical layout to the grid layout at the specified row and column
    QGridLayout *gridLayout = qobject_cast<QGridLayout*>(parent->layout());
    if (gridLayout) {
        gridLayout->addLayout(productLayout, row, col);
    }
}


void secwindow::on_scrollArea_2_customContextMenuRequested(const QPoint &pos)
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

void secwindow::on_pushButton_13_clicked()
{
    ui->label_2->clear();
    ui->label_3->clear();
    ui->label_4->clear();
}



void secwindow::payment(int denomination)
{
    int productId = ui->label_2->text().toInt();
    if (productId > 0) {
        QSqlQuery checkStockQuery(db);
        checkStockQuery.prepare("SELECT product_name, price, stock FROM STOCK_67011073 WHERE id = ?");
        checkStockQuery.addBindValue(productId);
        if (checkStockQuery.exec() && checkStockQuery.next()) {
            QString productName = checkStockQuery.value(0).toString();
            int price = checkStockQuery.value(1).toInt();
            int stock = checkStockQuery.value(2).toInt();

            if (stock <= 0) {
                QMessageBox::warning(this, "Out of Stock", "OUT OF STOCK!");
                return;
            }

            if (!paymentCompleted) {
                remainingBalance -= denomination;

                // Update remaining balance in the UI
                if (remainingBalance > 0) {
                    ui->label_5->setText("Remaining: " + QString::number(remainingBalance) + " ฿");
                } else {
                    int change = -remainingBalance;  // Calculate change when balance is negative
                    remainingBalance = 0;  // Reset remaining balance to 0 after payment is complete

                    // Show remaining balance as 0
                    ui->label_5->setText("Remaining: 0 ฿");

                    // Show the calculated change
                    ui->label_8->setText("Change: " + QString::number(change) + " ฿");

                    // Call the function to update the change box
                    updateChangeBox(change);

                    // Notify user that payment is complete
                    ui->label_9->setText("Payment complete!");
                    paymentCompleted = true;

                    // Update stock
                    QSqlQuery query(db);
                    query.prepare("UPDATE STOCK_67011073 SET stock = stock - 1 WHERE id = ? AND stock > 0");
                    query.addBindValue(productId);
                    if (!query.exec()) {
                        qDebug() << "Error updating stock:" << query.lastError().text();
                    } else {
                        populateList();
                    }

                    // Insert purchase history
                    QSqlQuery historyQuery(db);
                    historyQuery.prepare("INSERT INTO PURCHASE_HISTORY (product_name, price, timestamp) VALUES (?, ?, datetime('now', 'localtime'))");
                    historyQuery.addBindValue(productName);
                    historyQuery.addBindValue(price);
                    if (!historyQuery.exec()) {
                        qDebug() << "Error inserting into purchase history:" << historyQuery.lastError().text();
                    } else {
                        // Do not open the collection window here, just insert data
                        qDebug() << "Purchase history inserted successfully.";
                    }
                }
            }
        }
    }
}






void secwindow::on_pushButton_9_clicked()
{
    payment(1);
}


void secwindow::on_pushButton_2_clicked()
{
    payment(2);
}


void secwindow::on_pushButton_4_clicked()
{
    payment(5);
}


void secwindow::on_pushButton_5_clicked()
{
    payment(10);
}


void secwindow::on_pushButton_10_clicked()
{
    payment(20);
}


void secwindow::on_pushButton_12_clicked()
{
    payment(50);
}


void secwindow::on_pushButton_11_clicked()
{
    payment(100);
}




void secwindow::updateChangeBox(int change)
{
    int denominations[] = {100, 50, 20, 10, 5, 2, 1}; // Available denominations
    for (int denom : denominations) {
        if (change <= 0) break;

        int needed = change / denom; // How many of this denomination are needed?
        qDebug() << "Trying to use denomination: " << denom << "฿, Needed: " << needed;

        QSqlQuery query(db);
        query.prepare("SELECT count FROM CHANGE_BOX WHERE denomination = ?");
        query.addBindValue(QString::number(denom) + "฿");

        if (query.exec() && query.next()) {
            int available = query.value(0).toInt();
            int toUse = qMin(available, needed);

            if (toUse > 0) {
                qDebug() << "Updating change box: Used " << toUse << " of " << denom << "฿";
                QSqlQuery updateQuery(db);
                updateQuery.prepare("UPDATE CHANGE_BOX SET count = count - ? WHERE denomination = ?");
                updateQuery.addBindValue(toUse);
                updateQuery.addBindValue(QString::number(denom) + "฿");
                if (!updateQuery.exec()) {
                    qDebug() << "Error updating change box:" << updateQuery.lastError().text();
                }
                change -= toUse * denom; // Decrease the change by the amount of coins used
            }
        }
    }

    // If any remaining change is left that can't be given exactly, show a warning
    if (change > 0) {
        qDebug() << "Unable to give the exact change, remaining change: " << change;
    }
}




void secwindow::on_pushButton_14_clicked()
{
    ui->label_2->clear();
    ui->label_3->clear();
    ui->label_4->clear();
    ui->label_5->clear();
    ui->label_8->clear();
    ui->label_9->clear();

    paymentCompleted = false;
}


void secwindow::on_pushButton_15_clicked()
{
    collectionbwindow *collectionWindow = new collectionbwindow(this);
    collectionWindow->loadPurchaseHistory();  // Load purchase history
    collectionWindow->show();
}

