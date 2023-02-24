/********************************************************************************
** Form generated from reading UI file 'roomwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMWIDGET_H
#define UI_ROOMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RoomWidget
{
public:
    QGridLayout *gridLayout;
    QPushButton *btnRefresh;
    QPushButton *btnCreate;
    QLabel *label;
    QPushButton *btnExit;
    QListWidget *lwRoom;

    void setupUi(QWidget *RoomWidget)
    {
        if (RoomWidget->objectName().isEmpty())
            RoomWidget->setObjectName(QString::fromUtf8("RoomWidget"));
        RoomWidget->resize(400, 578);
        gridLayout = new QGridLayout(RoomWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btnRefresh = new QPushButton(RoomWidget);
        btnRefresh->setObjectName(QString::fromUtf8("btnRefresh"));

        gridLayout->addWidget(btnRefresh, 0, 2, 1, 1);

        btnCreate = new QPushButton(RoomWidget);
        btnCreate->setObjectName(QString::fromUtf8("btnCreate"));

        gridLayout->addWidget(btnCreate, 0, 3, 1, 1);

        label = new QLabel(RoomWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        btnExit = new QPushButton(RoomWidget);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));

        gridLayout->addWidget(btnExit, 3, 3, 1, 1);

        lwRoom = new QListWidget(RoomWidget);
        lwRoom->setObjectName(QString::fromUtf8("lwRoom"));

        gridLayout->addWidget(lwRoom, 1, 1, 1, 2);


        retranslateUi(RoomWidget);

        QMetaObject::connectSlotsByName(RoomWidget);
    } // setupUi

    void retranslateUi(QWidget *RoomWidget)
    {
        RoomWidget->setWindowTitle(QApplication::translate("RoomWidget", "Form", nullptr));
        btnRefresh->setText(QApplication::translate("RoomWidget", "\345\210\267\346\226\260", nullptr));
        btnCreate->setText(QApplication::translate("RoomWidget", "\345\210\233\345\273\272\346\210\221\347\232\204\346\210\277\351\227\264", nullptr));
        label->setText(QApplication::translate("RoomWidget", "\346\210\277\351\227\264\345\210\227\350\241\250", nullptr));
        btnExit->setText(QApplication::translate("RoomWidget", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RoomWidget: public Ui_RoomWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMWIDGET_H
