#include "collectionbwindow.h"
#include "ui_collectionbwindow.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QLabel>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QMenu>


collectionbwindow::collectionbwindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::collectionbwindow)
{
    ui->setupUi(this);
    this->setFixedSize(740, 790);
    this->setWindowTitle("CollectionBox");

    // Open the database connection
    db.setDatabaseName("vending.db");
    if (!db.open()) {
        qDebug() << "Error: Could not open database:" << db.lastError().text();
    } else {
        qDebug() << "Database connection established!";
    }

    // Enable scrolling in the scroll area
    ui->scrollArea->setWidgetResizable(true);

    // Ensure the scroll area is properly set up initially
    if (ui->scrollArea->widget()) {
        delete ui->scrollArea->widget();
    }
    QWidget *containerWidget = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(containerWidget);
    ui->scrollArea->setWidget(containerWidget);
    ui->scrollArea->setWidgetResizable(true);

    // Connect custom context menu signal to the handler
    ui->scrollArea->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->scrollArea, &QWidget::customContextMenuRequested,
            this, &collectionbwindow::on_scrollArea_customContextMenuRequested);
}

collectionbwindow::~collectionbwindow()
{
    db.close();
    emit collectionClosed();
    delete ui;
}

void collectionbwindow::loadPurchaseHistory()
{
    qDebug() << "Loading purchase history...";

    // Check if the database connection is valid
    if (!db.isOpen()) {
        qDebug() << "Database connection is not open!";
        return;
    }

    // Query to fetch purchase history
    QSqlQuery query("SELECT product_name, price, timestamp FROM PURCHASE_HISTORY", db);
    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    // Clear previous content in scroll area
    if (ui->scrollArea->widget()) {
        delete ui->scrollArea->widget();
    }

    QWidget *containerWidget = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(containerWidget);

    // Check if there are records
    bool hasRecords = false;

    while (query.next()) {
        hasRecords = true;
        QString product = query.value(0).toString();
        QString price = QString::number(query.value(1).toInt()) + " ฿";
        QString timestamp = query.value(2).toString();

        QLabel *historyLabel = new QLabel(product + " - " + price + " - " + timestamp, containerWidget);
        historyLabel->setStyleSheet("font: 12pt; padding: 5px; border-bottom: 1px solid gray;");
        layout->addWidget(historyLabel);
    }

    if (!hasRecords) {
        QLabel *emptyLabel = new QLabel("No purchase history available", containerWidget);
        layout->addWidget(emptyLabel);
    }

    // Set layout and add to the scroll area
    containerWidget->setLayout(layout);
    ui->scrollArea->setWidget(containerWidget);
    ui->scrollArea->setWidgetResizable(true);
}


void collectionbwindow::on_pushButton_13_clicked()
{
    QSqlQuery query(db);
    if (!query.exec("DELETE FROM PURCHASE_HISTORY")) {
        qDebug() << "Error clearing purchase history:" << query.lastError().text();
        return;
    }

    // Show the message box
    QMessageBox::information(this, "Money Collected", "MONEY HAS BEEN COLLECTED!");

    // Reload the purchase history (which should now be empty)
    loadPurchaseHistory();
}

void collectionbwindow::on_pushButton_14_clicked()
{
    this->close();   // Close the window properly
    emit collectionClosed();
}

void collectionbwindow::on_scrollArea_customContextMenuRequested(const QPoint &pos)
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

    menu->exec(ui->scrollArea->mapToGlobal(pos));
}

