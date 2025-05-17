/********************************************************************************
** Form generated from reading UI file 'sec2window.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEC2WINDOW_H
#define UI_SEC2WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_sec2window
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *sec2window)
    {
        if (sec2window->objectName().isEmpty())
            sec2window->setObjectName("sec2window");
        sec2window->resize(1095, 418);
        label = new QLabel(sec2window);
        label->setObjectName("label");
        label->setGeometry(QRect(430, 0, 241, 71));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 26pt \"Segoe UI\";"));
        pushButton = new QPushButton(sec2window);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(460, 120, 181, 81));
        pushButton->setStyleSheet(QString::fromUtf8("font: 700 18pt \"Segoe UI\";"));

        retranslateUi(sec2window);

        QMetaObject::connectSlotsByName(sec2window);
    } // setupUi

    void retranslateUi(QDialog *sec2window)
    {
        sec2window->setWindowTitle(QCoreApplication::translate("sec2window", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("sec2window", "ADMIN MODE", nullptr));
        pushButton->setText(QCoreApplication::translate("sec2window", "STOCK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sec2window: public Ui_sec2window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEC2WINDOW_H
