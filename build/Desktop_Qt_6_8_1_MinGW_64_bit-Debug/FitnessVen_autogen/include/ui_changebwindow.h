/********************************************************************************
** Form generated from reading UI file 'changebwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEBWINDOW_H
#define UI_CHANGEBWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_changebwindow
{
public:
    QLabel *label;

    void setupUi(QDialog *changebwindow)
    {
        if (changebwindow->objectName().isEmpty())
            changebwindow->setObjectName("changebwindow");
        changebwindow->resize(765, 557);
        label = new QLabel(changebwindow);
        label->setObjectName("label");
        label->setGeometry(QRect(260, 0, 241, 51));
        label->setStyleSheet(QString::fromUtf8("font: 700 28pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        label->setFrameShape(QFrame::Shape::NoFrame);

        retranslateUi(changebwindow);

        QMetaObject::connectSlotsByName(changebwindow);
    } // setupUi

    void retranslateUi(QDialog *changebwindow)
    {
        changebwindow->setWindowTitle(QCoreApplication::translate("changebwindow", "Dialog", nullptr));
#if QT_CONFIG(tooltip)
        label->setToolTip(QCoreApplication::translate("changebwindow", "<html><head/><body><p>USER MODE</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        label->setWhatsThis(QCoreApplication::translate("changebwindow", "<html><head/><body><p>dadad</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label->setText(QCoreApplication::translate("changebwindow", "CHANGE BOX", nullptr));
    } // retranslateUi

};

namespace Ui {
    class changebwindow: public Ui_changebwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEBWINDOW_H
