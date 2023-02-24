/********************************************************************************
** Form generated from reading UI file 'roomcreatwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMCREATWIDGET_H
#define UI_ROOMCREATWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RoomCreatWidget
{
public:
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QPushButton *btnCreate;
    QPushButton *btnWaith;

    void setupUi(QWidget *RoomCreatWidget)
    {
        if (RoomCreatWidget->objectName().isEmpty())
            RoomCreatWidget->setObjectName(QString::fromUtf8("RoomCreatWidget"));
        RoomCreatWidget->resize(228, 130);
        gridLayout = new QGridLayout(RoomCreatWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit = new QLineEdit(RoomCreatWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 0, 1, 2);

        btnCreate = new QPushButton(RoomCreatWidget);
        btnCreate->setObjectName(QString::fromUtf8("btnCreate"));

        gridLayout->addWidget(btnCreate, 1, 0, 1, 1);

        btnWaith = new QPushButton(RoomCreatWidget);
        btnWaith->setObjectName(QString::fromUtf8("btnWaith"));

        gridLayout->addWidget(btnWaith, 1, 1, 1, 1);


        retranslateUi(RoomCreatWidget);

        QMetaObject::connectSlotsByName(RoomCreatWidget);
    } // setupUi

    void retranslateUi(QWidget *RoomCreatWidget)
    {
        RoomCreatWidget->setWindowTitle(QApplication::translate("RoomCreatWidget", "Form", nullptr));
        lineEdit->setPlaceholderText(QApplication::translate("RoomCreatWidget", "\346\210\277\351\227\264\345\220\215", nullptr));
        btnCreate->setText(QApplication::translate("RoomCreatWidget", "\345\210\233\345\273\272", nullptr));
        btnWaith->setText(QApplication::translate("RoomCreatWidget", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RoomCreatWidget: public Ui_RoomCreatWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMCREATWIDGET_H
