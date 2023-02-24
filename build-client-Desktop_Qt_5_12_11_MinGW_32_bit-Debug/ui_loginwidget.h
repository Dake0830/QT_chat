/********************************************************************************
** Form generated from reading UI file 'loginwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIDGET_H
#define UI_LOGINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWidget
{
public:
    QGridLayout *gridLayout;
    QPushButton *btnRegister;
    QPushButton *btnLogin;
    QLineEdit *leUsername;
    QCheckBox *cbLogin;
    QLineEdit *lePassword;
    QCheckBox *cbRemberpass;

    void setupUi(QWidget *LoginWidget)
    {
        if (LoginWidget->objectName().isEmpty())
            LoginWidget->setObjectName(QString::fromUtf8("LoginWidget"));
        LoginWidget->resize(248, 134);
        gridLayout = new QGridLayout(LoginWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btnRegister = new QPushButton(LoginWidget);
        btnRegister->setObjectName(QString::fromUtf8("btnRegister"));

        gridLayout->addWidget(btnRegister, 4, 0, 1, 1);

        btnLogin = new QPushButton(LoginWidget);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));

        gridLayout->addWidget(btnLogin, 4, 1, 1, 1);

        leUsername = new QLineEdit(LoginWidget);
        leUsername->setObjectName(QString::fromUtf8("leUsername"));

        gridLayout->addWidget(leUsername, 0, 0, 1, 2);

        cbLogin = new QCheckBox(LoginWidget);
        cbLogin->setObjectName(QString::fromUtf8("cbLogin"));

        gridLayout->addWidget(cbLogin, 3, 1, 1, 1);

        lePassword = new QLineEdit(LoginWidget);
        lePassword->setObjectName(QString::fromUtf8("lePassword"));
        lePassword->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lePassword, 1, 0, 1, 2);

        cbRemberpass = new QCheckBox(LoginWidget);
        cbRemberpass->setObjectName(QString::fromUtf8("cbRemberpass"));

        gridLayout->addWidget(cbRemberpass, 3, 0, 1, 1);


        retranslateUi(LoginWidget);

        QMetaObject::connectSlotsByName(LoginWidget);
    } // setupUi

    void retranslateUi(QWidget *LoginWidget)
    {
        LoginWidget->setWindowTitle(QApplication::translate("LoginWidget", "Form", nullptr));
        btnRegister->setText(QApplication::translate("LoginWidget", "\346\263\250\345\206\214", nullptr));
        btnLogin->setText(QApplication::translate("LoginWidget", "\347\231\273\345\275\225", nullptr));
        leUsername->setPlaceholderText(QApplication::translate("LoginWidget", "\347\224\250\346\210\267\345\220\215", nullptr));
        cbLogin->setText(QApplication::translate("LoginWidget", "\350\207\252\345\212\250\347\231\273\345\275\225", nullptr));
        lePassword->setPlaceholderText(QApplication::translate("LoginWidget", "\345\257\206\347\240\201", nullptr));
        cbRemberpass->setText(QApplication::translate("LoginWidget", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWidget: public Ui_LoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
