/********************************************************************************
** Form generated from reading UI file 'chatroomwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATROOMWIDGET_H
#define UI_CHATROOMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qvideowidget.h"

QT_BEGIN_NAMESPACE

class Ui_ChatroomWidget
{
public:
    QGridLayout *gridLayout;
    QVideoWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QPushButton *btnChrefersh;
    QListWidget *lvuser;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextBrowser *textBrowser;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnGoaway;
    QPushButton *btnGift;
    QCheckBox *cbxCamera;
    QCheckBox *checkBox;

    void setupUi(QWidget *ChatroomWidget)
    {
        if (ChatroomWidget->objectName().isEmpty())
            ChatroomWidget->setObjectName(QString::fromUtf8("ChatroomWidget"));
        ChatroomWidget->resize(632, 607);
        gridLayout = new QGridLayout(ChatroomWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new QVideoWidget(ChatroomWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(400, 300));

        gridLayout->addWidget(widget, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(ChatroomWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        btnChrefersh = new QPushButton(ChatroomWidget);
        btnChrefersh->setObjectName(QString::fromUtf8("btnChrefersh"));

        horizontalLayout_2->addWidget(btnChrefersh);


        verticalLayout_2->addLayout(horizontalLayout_2);

        lvuser = new QListWidget(ChatroomWidget);
        lvuser->setObjectName(QString::fromUtf8("lvuser"));

        verticalLayout_2->addWidget(lvuser);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(ChatroomWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        textBrowser = new QTextBrowser(ChatroomWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);


        verticalLayout_3->addLayout(verticalLayout);

        lineEdit = new QLineEdit(ChatroomWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_3->addWidget(lineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnGoaway = new QPushButton(ChatroomWidget);
        btnGoaway->setObjectName(QString::fromUtf8("btnGoaway"));

        horizontalLayout->addWidget(btnGoaway);

        btnGift = new QPushButton(ChatroomWidget);
        btnGift->setObjectName(QString::fromUtf8("btnGift"));

        horizontalLayout->addWidget(btnGift);

        cbxCamera = new QCheckBox(ChatroomWidget);
        cbxCamera->setObjectName(QString::fromUtf8("cbxCamera"));

        horizontalLayout->addWidget(cbxCamera);

        checkBox = new QCheckBox(ChatroomWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout->addWidget(checkBox);


        verticalLayout_3->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_3, 1, 0, 1, 2);


        retranslateUi(ChatroomWidget);

        QMetaObject::connectSlotsByName(ChatroomWidget);
    } // setupUi

    void retranslateUi(QWidget *ChatroomWidget)
    {
        ChatroomWidget->setWindowTitle(QApplication::translate("ChatroomWidget", "Form", nullptr));
        label_2->setText(QApplication::translate("ChatroomWidget", "\346\210\277\351\227\264\345\206\205\346\210\220\345\221\230", nullptr));
        btnChrefersh->setText(QApplication::translate("ChatroomWidget", "\345\210\267\346\226\260", nullptr));
        label->setText(QApplication::translate("ChatroomWidget", "\346\266\210\346\201\257\345\210\227\350\241\250", nullptr));
        btnGoaway->setText(QApplication::translate("ChatroomWidget", "\347\246\273\345\274\200", nullptr));
        btnGift->setText(QApplication::translate("ChatroomWidget", "\351\200\201\347\244\274", nullptr));
        cbxCamera->setText(QApplication::translate("ChatroomWidget", "\346\221\204\345\203\217\345\244\264", nullptr));
        checkBox->setText(QApplication::translate("ChatroomWidget", "\345\274\271\345\271\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatroomWidget: public Ui_ChatroomWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATROOMWIDGET_H
