/********************************************************************************
** Form generated from reading UI file 'giftwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GIFTWIDGET_H
#define UI_GIFTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GiftWidget
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QRadioButton *rbGiftfish;
    QLabel *lbfish;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *rbGiftfly;
    QLabel *lbfly;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *rbGiftrocket;
    QLabel *lbrocket;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLCDNumber *lcdmonney;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLCDNumber *lcdintegral;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnIntegral;
    QPushButton *btnMonney;
    QPushButton *btnRecharge;
    QPushButton *btnGoaway;

    void setupUi(QWidget *GiftWidget)
    {
        if (GiftWidget->objectName().isEmpty())
            GiftWidget->setObjectName(QString::fromUtf8("GiftWidget"));
        GiftWidget->resize(371, 200);
        verticalLayout_4 = new QVBoxLayout(GiftWidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        rbGiftfish = new QRadioButton(GiftWidget);
        rbGiftfish->setObjectName(QString::fromUtf8("rbGiftfish"));
        rbGiftfish->setCursor(QCursor(Qt::PointingHandCursor));
        rbGiftfish->setLayoutDirection(Qt::LeftToRight);

        verticalLayout->addWidget(rbGiftfish);

        lbfish = new QLabel(GiftWidget);
        lbfish->setObjectName(QString::fromUtf8("lbfish"));

        verticalLayout->addWidget(lbfish);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        rbGiftfly = new QRadioButton(GiftWidget);
        rbGiftfly->setObjectName(QString::fromUtf8("rbGiftfly"));
        rbGiftfly->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_2->addWidget(rbGiftfly);

        lbfly = new QLabel(GiftWidget);
        lbfly->setObjectName(QString::fromUtf8("lbfly"));

        verticalLayout_2->addWidget(lbfly);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        rbGiftrocket = new QRadioButton(GiftWidget);
        rbGiftrocket->setObjectName(QString::fromUtf8("rbGiftrocket"));

        verticalLayout_3->addWidget(rbGiftrocket);

        lbrocket = new QLabel(GiftWidget);
        lbrocket->setObjectName(QString::fromUtf8("lbrocket"));

        verticalLayout_3->addWidget(lbrocket);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(GiftWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        lcdmonney = new QLCDNumber(GiftWidget);
        lcdmonney->setObjectName(QString::fromUtf8("lcdmonney"));
        lcdmonney->setProperty("value", QVariant(0.000000000000000));

        horizontalLayout_3->addWidget(lcdmonney);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(GiftWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        lcdintegral = new QLCDNumber(GiftWidget);
        lcdintegral->setObjectName(QString::fromUtf8("lcdintegral"));

        horizontalLayout_4->addWidget(lcdintegral);


        verticalLayout_4->addLayout(horizontalLayout_4);

        lineEdit = new QLineEdit(GiftWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_4->addWidget(lineEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btnIntegral = new QPushButton(GiftWidget);
        btnIntegral->setObjectName(QString::fromUtf8("btnIntegral"));

        horizontalLayout_2->addWidget(btnIntegral);

        btnMonney = new QPushButton(GiftWidget);
        btnMonney->setObjectName(QString::fromUtf8("btnMonney"));

        horizontalLayout_2->addWidget(btnMonney);

        btnRecharge = new QPushButton(GiftWidget);
        btnRecharge->setObjectName(QString::fromUtf8("btnRecharge"));

        horizontalLayout_2->addWidget(btnRecharge);

        btnGoaway = new QPushButton(GiftWidget);
        btnGoaway->setObjectName(QString::fromUtf8("btnGoaway"));

        horizontalLayout_2->addWidget(btnGoaway);


        verticalLayout_4->addLayout(horizontalLayout_2);


        retranslateUi(GiftWidget);

        QMetaObject::connectSlotsByName(GiftWidget);
    } // setupUi

    void retranslateUi(QWidget *GiftWidget)
    {
        GiftWidget->setWindowTitle(QApplication::translate("GiftWidget", "Form", nullptr));
        rbGiftfish->setText(QApplication::translate("GiftWidget", "\351\261\274\350\233\213", nullptr));
        lbfish->setText(QApplication::translate("GiftWidget", "100\347\247\257\345\210\206/10\345\205\203", nullptr));
        rbGiftfly->setText(QApplication::translate("GiftWidget", "\351\243\236\346\234\272", nullptr));
        lbfly->setText(QApplication::translate("GiftWidget", "1019\347\247\257\345\210\206/200\345\205\203", nullptr));
        rbGiftrocket->setText(QApplication::translate("GiftWidget", "\347\201\253\347\256\255", nullptr));
        lbrocket->setText(QApplication::translate("GiftWidget", "16666\347\247\257\345\210\206/999\345\205\203", nullptr));
        label->setText(QApplication::translate("GiftWidget", "\345\275\223\345\211\215\351\207\221\351\242\235\357\274\232", nullptr));
        label_2->setText(QApplication::translate("GiftWidget", "\345\275\223\345\211\215\347\247\257\345\210\206\357\274\232", nullptr));
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QApplication::translate("GiftWidget", "\350\257\267\350\276\223\345\205\245\350\246\201\345\205\205\345\200\274\347\232\204\351\207\221\351\242\235", nullptr));
        btnIntegral->setText(QApplication::translate("GiftWidget", "\347\247\257\345\210\206\351\200\201\345\207\272", nullptr));
        btnMonney->setText(QApplication::translate("GiftWidget", "\344\275\231\351\242\235\351\200\201\345\207\272", nullptr));
        btnRecharge->setText(QApplication::translate("GiftWidget", "\345\205\205\345\200\274", nullptr));
        btnGoaway->setText(QApplication::translate("GiftWidget", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GiftWidget: public Ui_GiftWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GIFTWIDGET_H
