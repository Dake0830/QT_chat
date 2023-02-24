/********************************************************************************
** Form generated from reading UI file 'roomdialogwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMDIALOGWIDGET_H
#define UI_ROOMDIALOGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RoomDialogWidget
{
public:
    QGridLayout *gridLayout;
    QLineEdit *leRoomName;
    QPushButton *btnCreate;
    QPushButton *btnWithdaw;

    void setupUi(QDialog *RoomDialogWidget)
    {
        if (RoomDialogWidget->objectName().isEmpty())
            RoomDialogWidget->setObjectName(QString::fromUtf8("RoomDialogWidget"));
        RoomDialogWidget->resize(239, 87);
        gridLayout = new QGridLayout(RoomDialogWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        leRoomName = new QLineEdit(RoomDialogWidget);
        leRoomName->setObjectName(QString::fromUtf8("leRoomName"));

        gridLayout->addWidget(leRoomName, 0, 0, 1, 2);

        btnCreate = new QPushButton(RoomDialogWidget);
        btnCreate->setObjectName(QString::fromUtf8("btnCreate"));

        gridLayout->addWidget(btnCreate, 1, 0, 1, 1);

        btnWithdaw = new QPushButton(RoomDialogWidget);
        btnWithdaw->setObjectName(QString::fromUtf8("btnWithdaw"));

        gridLayout->addWidget(btnWithdaw, 1, 1, 1, 1);


        retranslateUi(RoomDialogWidget);

        QMetaObject::connectSlotsByName(RoomDialogWidget);
    } // setupUi

    void retranslateUi(QDialog *RoomDialogWidget)
    {
        RoomDialogWidget->setWindowTitle(QApplication::translate("RoomDialogWidget", "Dialog", nullptr));
        leRoomName->setPlaceholderText(QApplication::translate("RoomDialogWidget", "\346\210\277\351\227\264\345\220\215", nullptr));
        btnCreate->setText(QApplication::translate("RoomDialogWidget", "\345\210\233\345\273\272", nullptr));
        btnWithdaw->setText(QApplication::translate("RoomDialogWidget", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RoomDialogWidget: public Ui_RoomDialogWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMDIALOGWIDGET_H
