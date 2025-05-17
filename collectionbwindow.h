#ifndef COLLECTIONBWINDOW_H
#define COLLECTIONBWINDOW_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class collectionbwindow;
}

class collectionbwindow : public QDialog
{
    Q_OBJECT

public:
    explicit collectionbwindow(QWidget *parent = nullptr);
    ~collectionbwindow();
    void loadPurchaseHistory();


signals:
    void collectionClosed();

private slots:
    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_scrollArea_customContextMenuRequested(const QPoint &pos);

private:
    Ui::collectionbwindow *ui;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QSqlQuery query;
};

#endif // COLLECTIONBWINDOW_H
