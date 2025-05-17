/********************************************************************************
** Form generated from reading UI file 'secwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECWINDOW_H
#define UI_SECWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_secwindow
{
public:
    QLabel *label;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QLabel *label_90;
    QLabel *label_87;
    QLabel *label_88;
    QListView *listView_2;
    QLabel *label_78;
    QLabel *label_2;
    QLabel *label_85;
    QLabel *label_82;
    QLabel *label_3;
    QLabel *label_83;
    QListView *listView;
    QPushButton *pushButton_9;
    QPushButton *pushButton_5;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_10;
    QFrame *line;
    QPushButton *pushButton_12;
    QPushButton *pushButton_11;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *pushButton_13;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;

    void setupUi(QDialog *secwindow)
    {
        if (secwindow->objectName().isEmpty())
            secwindow->setObjectName("secwindow");
        secwindow->resize(1102, 975);
        label = new QLabel(secwindow);
        label->setObjectName("label");
        label->setGeometry(QRect(410, 0, 221, 41));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 28pt \"Segoe UI\";"));
        label->setFrameShape(QFrame::Shape::NoFrame);
        scrollArea_2 = new QScrollArea(secwindow);
        scrollArea_2->setObjectName("scrollArea_2");
        scrollArea_2->setGeometry(QRect(0, 70, 721, 901));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 719, 899));
        label_90 = new QLabel(scrollAreaWidgetContents_2);
        label_90->setObjectName("label_90");
        label_90->setGeometry(QRect(70, 420, 111, 16));
        label_87 = new QLabel(scrollAreaWidgetContents_2);
        label_87->setObjectName("label_87");
        label_87->setGeometry(QRect(10, 360, 101, 16));
        label_88 = new QLabel(scrollAreaWidgetContents_2);
        label_88->setObjectName("label_88");
        label_88->setGeometry(QRect(10, 390, 101, 16));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        listView_2 = new QListView(secwindow);
        listView_2->setObjectName("listView_2");
        listView_2->setGeometry(QRect(720, 190, 381, 571));
        label_78 = new QLabel(secwindow);
        label_78->setObjectName("label_78");
        label_78->setGeometry(QRect(870, 200, 81, 16));
        label_78->setStyleSheet(QString::fromUtf8("font: 700 11pt \"Segoe UI\";"));
        label_2 = new QLabel(secwindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(880, 230, 61, 16));
        label_85 = new QLabel(secwindow);
        label_85->setObjectName("label_85");
        label_85->setGeometry(QRect(850, 260, 121, 16));
        label_85->setStyleSheet(QString::fromUtf8("font: 700 11pt \"Segoe UI\";"));
        label_82 = new QLabel(secwindow);
        label_82->setObjectName("label_82");
        label_82->setGeometry(QRect(890, 330, 41, 16));
        label_82->setStyleSheet(QString::fromUtf8("font: 700 11pt \"Segoe UI\";"));
        label_3 = new QLabel(secwindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(820, 290, 181, 16));
        label_83 = new QLabel(secwindow);
        label_83->setObjectName("label_83");
        label_83->setGeometry(QRect(860, 390, 101, 16));
        label_83->setStyleSheet(QString::fromUtf8("font: 700 11pt \"Segoe UI\";"));
        listView = new QListView(secwindow);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(740, 520, 341, 181));
        pushButton_9 = new QPushButton(secwindow);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(750, 560, 80, 24));
        pushButton_5 = new QPushButton(secwindow);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(860, 560, 81, 21));
        pushButton_2 = new QPushButton(secwindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(750, 600, 80, 24));
        pushButton_4 = new QPushButton(secwindow);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(750, 640, 80, 24));
        pushButton_10 = new QPushButton(secwindow);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(980, 560, 80, 24));
        line = new QFrame(secwindow);
        line->setObjectName("line");
        line->setGeometry(QRect(950, 520, 20, 181));
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        pushButton_12 = new QPushButton(secwindow);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(980, 600, 80, 24));
        pushButton_11 = new QPushButton(secwindow);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(980, 640, 80, 24));
        label_5 = new QLabel(secwindow);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(870, 420, 91, 20));
        label_4 = new QLabel(secwindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(880, 360, 51, 16));
        label_6 = new QLabel(secwindow);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(830, 530, 41, 16));
        label_6->setStyleSheet(QString::fromUtf8("font: 700 11pt \"Segoe UI\";"));
        label_7 = new QLabel(secwindow);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(980, 530, 81, 16));
        label_7->setStyleSheet(QString::fromUtf8("font: 700 11pt \"Segoe UI\";"));
        pushButton_13 = new QPushButton(secwindow);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(780, 710, 91, 31));
        pushButton_13->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Segoe UI\";"));
        label_8 = new QLabel(secwindow);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(870, 450, 81, 20));
        label_9 = new QLabel(secwindow);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(850, 480, 121, 20));
        pushButton_14 = new QPushButton(secwindow);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(950, 710, 91, 31));
        pushButton_14->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Segoe UI\";"));
        pushButton_15 = new QPushButton(secwindow);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setGeometry(QRect(830, 810, 171, 51));
        pushButton_15->setStyleSheet(QString::fromUtf8("font: 700 16pt \"Segoe UI\";"));

        retranslateUi(secwindow);

        QMetaObject::connectSlotsByName(secwindow);
    } // setupUi

    void retranslateUi(QDialog *secwindow)
    {
        secwindow->setWindowTitle(QCoreApplication::translate("secwindow", "Dialog", nullptr));
#if QT_CONFIG(tooltip)
        label->setToolTip(QCoreApplication::translate("secwindow", "<html><head/><body><p>USER MODE</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        label->setWhatsThis(QCoreApplication::translate("secwindow", "<html><head/><body><p>dadad</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label->setText(QCoreApplication::translate("secwindow", "USER MODE", nullptr));
        label_90->setText(QString());
        label_87->setText(QString());
        label_88->setText(QString());
        label_78->setText(QCoreApplication::translate("secwindow", "Selected ID", nullptr));
        label_2->setText(QString());
        label_85->setText(QCoreApplication::translate("secwindow", "Selected Product", nullptr));
        label_82->setText(QCoreApplication::translate("secwindow", "Price", nullptr));
        label_3->setText(QString());
        label_83->setText(QCoreApplication::translate("secwindow", "Insert Money", nullptr));
        pushButton_9->setText(QCoreApplication::translate("secwindow", "1\340\270\277", nullptr));
        pushButton_5->setText(QCoreApplication::translate("secwindow", "10\340\270\277", nullptr));
        pushButton_2->setText(QCoreApplication::translate("secwindow", "2\340\270\277", nullptr));
        pushButton_4->setText(QCoreApplication::translate("secwindow", "5\340\270\277", nullptr));
        pushButton_10->setText(QCoreApplication::translate("secwindow", "20\340\270\277", nullptr));
        pushButton_12->setText(QCoreApplication::translate("secwindow", "50\340\270\277", nullptr));
        pushButton_11->setText(QCoreApplication::translate("secwindow", "100\340\270\277", nullptr));
        label_5->setText(QString());
        label_4->setText(QString());
        label_6->setText(QCoreApplication::translate("secwindow", "Coins", nullptr));
        label_7->setText(QCoreApplication::translate("secwindow", "Bank Notes", nullptr));
        pushButton_13->setText(QCoreApplication::translate("secwindow", "Cancel", nullptr));
        label_8->setText(QString());
        label_9->setText(QString());
        pushButton_14->setText(QCoreApplication::translate("secwindow", "Clear", nullptr));
        pushButton_15->setText(QCoreApplication::translate("secwindow", "Collection Box", nullptr));
    } // retranslateUi

};

namespace Ui {
    class secwindow: public Ui_secwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECWINDOW_H
