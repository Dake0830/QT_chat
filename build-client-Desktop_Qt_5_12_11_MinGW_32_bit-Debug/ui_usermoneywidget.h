/********************************************************************************
** Form generated from reading UI file 'usermoneywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMONEYWIDGET_H
#define UI_USERMONEYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserMoneyWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *btnRecharge;

    void setupUi(QWidget *UserMoneyWidget)
    {
        if (UserMoneyWidget->objectName().isEmpty())
            UserMoneyWidget->setObjectName(QString::fromUtf8("UserMoneyWidget"));
        UserMoneyWidget->resize(166, 110);
        verticalLayout = new QVBoxLayout(UserMoneyWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(UserMoneyWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(UserMoneyWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        btnRecharge = new QPushButton(UserMoneyWidget);
        btnRecharge->setObjectName(QString::fromUtf8("btnRecharge"));

        verticalLayout->addWidget(btnRecharge);


        retranslateUi(UserMoneyWidget);

        QMetaObject::connectSlotsByName(UserMoneyWidget);
    } // setupUi

    void retranslateUi(QWidget *UserMoneyWidget)
    {
        UserMoneyWidget->setWindowTitle(QApplication::translate("UserMoneyWidget", "Form", nullptr));
        label->setText(QApplication::translate("UserMoneyWidget", "\344\275\231\351\242\235\357\274\232", nullptr));
        btnRecharge->setText(QApplication::translate("UserMoneyWidget", " \345\205\205\345\200\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserMoneyWidget: public Ui_UserMoneyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMONEYWIDGET_H
