/********************************************************************************
** Form generated from reading UI file 'thiwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THIWINDOW_H
#define UI_THIWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_thiwindow
{
public:
    QLabel *label;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_3;
    QLabel *label_91;
    QLabel *label_89;
    QLabel *label_92;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_4;
    QLabel *label_93;
    QLabel *label_94;
    QLabel *label_95;
    QLabel *label_2;

    void setupUi(QDialog *thiwindow)
    {
        if (thiwindow->objectName().isEmpty())
            thiwindow->setObjectName("thiwindow");
        thiwindow->resize(1348, 1068);
        label = new QLabel(thiwindow);
        label->setObjectName("label");
        label->setGeometry(QRect(560, 0, 251, 71));
        label->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        label->setFrameShape(QFrame::Shape::NoFrame);
        scrollArea_2 = new QScrollArea(thiwindow);
        scrollArea_2->setObjectName("scrollArea_2");
        scrollArea_2->setGeometry(QRect(0, 90, 721, 901));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName("scrollAreaWidgetContents_3");
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 719, 899));
        label_91 = new QLabel(scrollAreaWidgetContents_3);
        label_91->setObjectName("label_91");
        label_91->setGeometry(QRect(70, 420, 111, 16));
        label_89 = new QLabel(scrollAreaWidgetContents_3);
        label_89->setObjectName("label_89");
        label_89->setGeometry(QRect(10, 360, 101, 16));
        label_92 = new QLabel(scrollAreaWidgetContents_3);
        label_92->setObjectName("label_92");
        label_92->setGeometry(QRect(10, 390, 101, 16));
        scrollArea_2->setWidget(scrollAreaWidgetContents_3);
        scrollArea_3 = new QScrollArea(thiwindow);
        scrollArea_3->setObjectName("scrollArea_3");
        scrollArea_3->setGeometry(QRect(720, 170, 621, 711));
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName("scrollAreaWidgetContents_4");
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 619, 709));
        label_93 = new QLabel(scrollAreaWidgetContents_4);
        label_93->setObjectName("label_93");
        label_93->setGeometry(QRect(70, 420, 111, 16));
        label_94 = new QLabel(scrollAreaWidgetContents_4);
        label_94->setObjectName("label_94");
        label_94->setGeometry(QRect(10, 360, 101, 16));
        label_95 = new QLabel(scrollAreaWidgetContents_4);
        label_95->setObjectName("label_95");
        label_95->setGeometry(QRect(10, 390, 101, 16));
        scrollArea_3->setWidget(scrollAreaWidgetContents_4);
        label_2 = new QLabel(thiwindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(960, 130, 141, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 700 18pt \"Segoe UI\";"));

        retranslateUi(thiwindow);

        QMetaObject::connectSlotsByName(thiwindow);
    } // setupUi

    void retranslateUi(QDialog *thiwindow)
    {
        thiwindow->setWindowTitle(QCoreApplication::translate("thiwindow", "Dialog", nullptr));
#if QT_CONFIG(tooltip)
        label->setToolTip(QCoreApplication::translate("thiwindow", "<html><head/><body><p>USER MODE</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        label->setWhatsThis(QCoreApplication::translate("thiwindow", "<html><head/><body><p>dadad</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label->setText(QCoreApplication::translate("thiwindow", "ADMIN MODE", nullptr));
        label_91->setText(QString());
        label_89->setText(QString());
        label_92->setText(QString());
        label_93->setText(QString());
        label_94->setText(QString());
        label_95->setText(QString());
        label_2->setText(QCoreApplication::translate("thiwindow", "Change Box", nullptr));
    } // retranslateUi

};

namespace Ui {
    class thiwindow: public Ui_thiwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THIWINDOW_H
