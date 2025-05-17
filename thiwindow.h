#ifndef THIWINDOW_H
#define THIWINDOW_H

#include <QDialog>
#include <QtSql>
#include <QListWidgetItem>
#include <QButtonGroup>
#include "collectionbwindow.h"

namespace Ui {
class thiwindow;
}

class thiwindow : public QDialog
{
    Q_OBJECT

public:
    explicit thiwindow(QWidget *parent = nullptr);
    ~thiwindow();

private slots:
    void on_scrollArea_2_customContextMenuRequested(const QPoint &pos);

    void on_pushButton_4_clicked();
    void on_openCollectionBox_clicked(); // Opens collectionbwindow
    void handleCollectionClosed();

private:
    Ui::thiwindow *ui;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QSqlQuery query;
    QButtonGroup *buttonGroup;
    collectionbwindow *collectionBox;


    void populateList();
    void populateListChange();
    void createProductWidget(QWidget *parent, int id, const QString &name, int price, int stock, int row, int col);
    void createProductWidgetChange(QWidget *parent, const QString &denomination, int count, int row, int col);
    void initializeDatabaseForChangeBox();
    void initializeDatabaseForPurchaseHistory();
    void refillStock(int id);
    void refillDenomination(const QString &denomination);
    int getMaxCountForDenomination(const QString &denomination);
};

#endif // THIWINDOW_H
