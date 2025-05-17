#ifndef SECWINDOW_H
#define SECWINDOW_H

#include <QDialog>
#include <QtSql>
#include <QListWidgetItem>
#include <QButtonGroup>

namespace Ui {
class secwindow;
}

class secwindow : public QDialog
{
    Q_OBJECT

public:
    explicit secwindow(QWidget *parent = nullptr);
    ~secwindow();

private slots:
    void on_scrollArea_2_customContextMenuRequested(const QPoint &pos);

    void on_pushButton_13_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

private:
    Ui::secwindow *ui;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QSqlQuery query;
    QButtonGroup *buttonGroup;
    int remainingBalance = 0;
    bool paymentCompleted = false;

    void initializeDatabase();
    void populateList();
    void createProductWidget(QWidget *parent, int id, const QString &name, int price, int stock, int row, int col);
    void payment(int denomination);
    void updateChangeBox(int change);
};

#endif // SECWINDOW_H

