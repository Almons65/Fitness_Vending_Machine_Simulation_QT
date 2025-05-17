/********************************************************************************
** Form generated from reading UI file 'payment.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAYMENT_H
#define UI_PAYMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Payment
{
public:
    QPushButton *pushButton;
    QLabel *label_80;
    QLabel *label_87;
    QListView *listView;
    QPushButton *pushButton_3;
    QListView *listView_2;
    QLabel *label_3;
    QLabel *label_83;
    QFrame *line;
    QPushButton *pushButton_2;
    QLabel *label_85;
    QLabel *label_78;
    QPushButton *pushButton_11;
    QLabel *label_82;
    QLabel *label_2;
    QPushButton *pushButton_10;
    QLabel *label_88;
    QLabel *label_5;
    QLabel *label_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_9;
    QPushButton *pushButton_6;
    QPushButton *pushButton_4;
    QLabel *label_84;

    void setupUi(QDialog *Payment)
    {
        if (Payment->objectName().isEmpty())
            Payment->setObjectName("Payment");
        Payment->resize(410, 550);
        pushButton = new QPushButton(Payment);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 320, 80, 24));
        label_80 = new QLabel(Payment);
        label_80->setObjectName("label_80");
        label_80->setGeometry(QRect(140, 120, 121, 16));
        label_80->setStyleSheet(QString::fromUtf8("font: 700 11pt \"Segoe UI\";"));
        label_87 = new QLabel(Payment);
        label_87->setObjectName("label_87");
        label_87->setGeometry(QRect(10, 240, 101, 16));
        listView = new QListView(Payment);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(30, 310, 341, 171));
        pushButton_3 = new QPushButton(Payment);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(40, 400, 80, 24));
        listView_2 = new QListView(Payment);
        listView_2->setObjectName("listView_2");
        listView_2->setGeometry(QRect(0, 40, 401, 471));
        label_3 = new QLabel(Payment);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(150, 150, 101, 16));
        label_83 = new QLabel(Payment);
        label_83->setObjectName("label_83");
        label_83->setGeometry(QRect(150, 240, 101, 16));
        label_83->setStyleSheet(QString::fromUtf8("font: 700 11pt \"Segoe UI\";"));
        line = new QFrame(Payment);
        line->setObjectName("line");
        line->setGeometry(QRect(220, 310, 20, 171));
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        pushButton_2 = new QPushButton(Payment);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(40, 360, 80, 24));
        label_85 = new QLabel(Payment);
        label_85->setObjectName("label_85");
        label_85->setGeometry(QRect(70, 300, 111, 16));
        label_78 = new QLabel(Payment);
        label_78->setObjectName("label_78");
        label_78->setGeometry(QRect(160, 50, 81, 16));
        label_78->setStyleSheet(QString::fromUtf8("font: 700 11pt \"Segoe UI\";"));
        pushButton_11 = new QPushButton(Payment);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(260, 400, 80, 24));
        label_82 = new QLabel(Payment);
        label_82->setObjectName("label_82");
        label_82->setGeometry(QRect(180, 180, 41, 16));
        label_82->setStyleSheet(QString::fromUtf8("font: 700 11pt \"Segoe UI\";"));
        label_2 = new QLabel(Payment);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(170, 80, 61, 16));
        pushButton_10 = new QPushButton(Payment);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(260, 360, 80, 24));
        label_88 = new QLabel(Payment);
        label_88->setObjectName("label_88");
        label_88->setGeometry(QRect(10, 270, 101, 16));
        label_5 = new QLabel(Payment);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(100, 280, 191, 16));
        label_4 = new QLabel(Payment);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(170, 210, 51, 16));
        pushButton_5 = new QPushButton(Payment);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(140, 320, 80, 24));
        pushButton_9 = new QPushButton(Payment);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(260, 320, 80, 24));
        pushButton_6 = new QPushButton(Payment);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(40, 320, 80, 24));
        pushButton_4 = new QPushButton(Payment);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(40, 400, 80, 24));
        label_84 = new QLabel(Payment);
        label_84->setObjectName("label_84");
        label_84->setGeometry(QRect(150, 120, 101, 16));
        label_84->setStyleSheet(QString::fromUtf8("font: 700 11pt \"Segoe UI\";"));

        retranslateUi(Payment);

        QMetaObject::connectSlotsByName(Payment);
    } // setupUi

    void retranslateUi(QDialog *Payment)
    {
        Payment->setWindowTitle(QCoreApplication::translate("Payment", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Payment", " 1\340\270\277", nullptr));
        label_80->setText(QCoreApplication::translate("Payment", "Selected Product", nullptr));
        label_87->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("Payment", "5\340\270\277", nullptr));
        label_3->setText(QString());
        label_83->setText(QCoreApplication::translate("Payment", "Insert Money", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Payment", "2\340\270\277", nullptr));
        label_85->setText(QString());
        label_78->setText(QCoreApplication::translate("Payment", "Selected ID", nullptr));
        pushButton_11->setText(QCoreApplication::translate("Payment", "100\340\270\277", nullptr));
        label_82->setText(QCoreApplication::translate("Payment", "Price", nullptr));
        label_2->setText(QString());
        pushButton_10->setText(QCoreApplication::translate("Payment", "50\340\270\277", nullptr));
        label_88->setText(QString());
        label_5->setText(QString());
        label_4->setText(QString());
        pushButton_5->setText(QCoreApplication::translate("Payment", "10\340\270\277", nullptr));
        pushButton_9->setText(QCoreApplication::translate("Payment", "20\340\270\277", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Payment", "1\340\270\277", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Payment", "5\340\270\277", nullptr));
        label_84->setText(QCoreApplication::translate("Payment", "Product Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Payment: public Ui_Payment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAYMENT_H
