/********************************************************************************
** Form generated from reading UI file 'stockwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOCKWINDOW_H
#define UI_STOCKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_stockwindow
{
public:
    QLabel *label;

    void setupUi(QDialog *stockwindow)
    {
        if (stockwindow->objectName().isEmpty())
            stockwindow->setObjectName("stockwindow");
        stockwindow->resize(757, 522);
        label = new QLabel(stockwindow);
        label->setObjectName("label");
        label->setGeometry(QRect(320, 0, 121, 51));
        label->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        label->setFrameShape(QFrame::Shape::NoFrame);

        retranslateUi(stockwindow);

        QMetaObject::connectSlotsByName(stockwindow);
    } // setupUi

    void retranslateUi(QDialog *stockwindow)
    {
        stockwindow->setWindowTitle(QCoreApplication::translate("stockwindow", "Dialog", nullptr));
#if QT_CONFIG(tooltip)
        label->setToolTip(QCoreApplication::translate("stockwindow", "<html><head/><body><p>USER MODE</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        label->setWhatsThis(QCoreApplication::translate("stockwindow", "<html><head/><body><p>dadad</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label->setText(QCoreApplication::translate("stockwindow", "STOCK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class stockwindow: public Ui_stockwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOCKWINDOW_H
