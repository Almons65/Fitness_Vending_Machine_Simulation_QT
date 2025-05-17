/********************************************************************************
** Form generated from reading UI file 'collectionbwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLLECTIONBWINDOW_H
#define UI_COLLECTIONBWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_collectionbwindow
{
public:
    QLabel *label;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;

    void setupUi(QDialog *collectionbwindow)
    {
        if (collectionbwindow->objectName().isEmpty())
            collectionbwindow->setObjectName("collectionbwindow");
        collectionbwindow->resize(746, 789);
        label = new QLabel(collectionbwindow);
        label->setObjectName("label");
        label->setGeometry(QRect(210, 10, 311, 51));
        label->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        label->setFrameShape(QFrame::Shape::NoFrame);
        scrollArea = new QScrollArea(collectionbwindow);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(0, 69, 741, 631));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 739, 629));
        scrollArea->setWidget(scrollAreaWidgetContents);
        pushButton_13 = new QPushButton(collectionbwindow);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(210, 720, 141, 51));
        pushButton_13->setStyleSheet(QString::fromUtf8("font: 700 14pt \"Segoe UI\";"));
        pushButton_14 = new QPushButton(collectionbwindow);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(450, 720, 111, 51));
        pushButton_14->setStyleSheet(QString::fromUtf8("font: 700 14pt \"Segoe UI\";"));

        retranslateUi(collectionbwindow);

        QMetaObject::connectSlotsByName(collectionbwindow);
    } // setupUi

    void retranslateUi(QDialog *collectionbwindow)
    {
        collectionbwindow->setWindowTitle(QCoreApplication::translate("collectionbwindow", "Dialog", nullptr));
#if QT_CONFIG(tooltip)
        label->setToolTip(QCoreApplication::translate("collectionbwindow", "<html><head/><body><p>USER MODE</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        label->setWhatsThis(QCoreApplication::translate("collectionbwindow", "<html><head/><body><p>dadad</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label->setText(QCoreApplication::translate("collectionbwindow", "COLLECTION BOX", nullptr));
        pushButton_13->setText(QCoreApplication::translate("collectionbwindow", "Collect Money", nullptr));
        pushButton_14->setText(QCoreApplication::translate("collectionbwindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class collectionbwindow: public Ui_collectionbwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLLECTIONBWINDOW_H
