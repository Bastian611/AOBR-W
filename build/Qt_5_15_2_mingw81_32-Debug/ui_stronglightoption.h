/********************************************************************************
** Form generated from reading UI file 'stronglightoption.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STRONGLIGHTOPTION_H
#define UI_STRONGLIGHTOPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StrongLightOption
{
public:
    QGroupBox *groupBox_Gimbal_IP_Option;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox_1_changeOption;
    QLabel *label_tcp_device_3_1;
    QLabel *label_tcpiplabel_device_3_1;
    QLabel *label_tcpportlabel_device_3_1;
    QLineEdit *lineEdit_tcpip_device_3_1;
    QLineEdit *lineEdit_tcpport_device_3_1;
    QPushButton *btn_tcpsave_device_3_1;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *groupBox_2;
    QLabel *label_tcp_device_3;
    QLabel *label_tcpiplabel_device_3;
    QLabel *label_tcpportlabel_device_3;
    QLineEdit *lineEdit_tcpip_device_3;
    QLineEdit *lineEdit_tcpport_device_3;
    QPushButton *btn_tcpconnect_device_3;

    void setupUi(QWidget *StrongLightOption)
    {
        if (StrongLightOption->objectName().isEmpty())
            StrongLightOption->setObjectName(QString::fromUtf8("StrongLightOption"));
        StrongLightOption->resize(643, 543);
        groupBox_Gimbal_IP_Option = new QGroupBox(StrongLightOption);
        groupBox_Gimbal_IP_Option->setObjectName(QString::fromUtf8("groupBox_Gimbal_IP_Option"));
        groupBox_Gimbal_IP_Option->setGeometry(QRect(10, 30, 612, 353));
        gridLayout = new QGridLayout(groupBox_Gimbal_IP_Option);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 3, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        groupBox_1_changeOption = new QGroupBox(groupBox_Gimbal_IP_Option);
        groupBox_1_changeOption->setObjectName(QString::fromUtf8("groupBox_1_changeOption"));
        groupBox_1_changeOption->setMinimumSize(QSize(500, 100));
        label_tcp_device_3_1 = new QLabel(groupBox_1_changeOption);
        label_tcp_device_3_1->setObjectName(QString::fromUtf8("label_tcp_device_3_1"));
        label_tcp_device_3_1->setGeometry(QRect(10, 30, 91, 16));
        label_tcpiplabel_device_3_1 = new QLabel(groupBox_1_changeOption);
        label_tcpiplabel_device_3_1->setObjectName(QString::fromUtf8("label_tcpiplabel_device_3_1"));
        label_tcpiplabel_device_3_1->setGeometry(QRect(20, 50, 21, 16));
        label_tcpiplabel_device_3_1->setLayoutDirection(Qt::LeftToRight);
        label_tcpportlabel_device_3_1 = new QLabel(groupBox_1_changeOption);
        label_tcpportlabel_device_3_1->setObjectName(QString::fromUtf8("label_tcpportlabel_device_3_1"));
        label_tcpportlabel_device_3_1->setGeometry(QRect(180, 50, 41, 16));
        lineEdit_tcpip_device_3_1 = new QLineEdit(groupBox_1_changeOption);
        lineEdit_tcpip_device_3_1->setObjectName(QString::fromUtf8("lineEdit_tcpip_device_3_1"));
        lineEdit_tcpip_device_3_1->setGeometry(QRect(50, 50, 121, 21));
        lineEdit_tcpport_device_3_1 = new QLineEdit(groupBox_1_changeOption);
        lineEdit_tcpport_device_3_1->setObjectName(QString::fromUtf8("lineEdit_tcpport_device_3_1"));
        lineEdit_tcpport_device_3_1->setGeometry(QRect(230, 50, 51, 21));
        btn_tcpsave_device_3_1 = new QPushButton(groupBox_1_changeOption);
        btn_tcpsave_device_3_1->setObjectName(QString::fromUtf8("btn_tcpsave_device_3_1"));
        btn_tcpsave_device_3_1->setGeometry(QRect(310, 50, 71, 23));

        gridLayout->addWidget(groupBox_1_changeOption, 3, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 4, 1, 1, 1);

        groupBox_2 = new QGroupBox(groupBox_Gimbal_IP_Option);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(100);
        sizePolicy.setVerticalStretch(100);
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMinimumSize(QSize(500, 100));
        label_tcp_device_3 = new QLabel(groupBox_2);
        label_tcp_device_3->setObjectName(QString::fromUtf8("label_tcp_device_3"));
        label_tcp_device_3->setGeometry(QRect(10, 30, 91, 16));
        label_tcpiplabel_device_3 = new QLabel(groupBox_2);
        label_tcpiplabel_device_3->setObjectName(QString::fromUtf8("label_tcpiplabel_device_3"));
        label_tcpiplabel_device_3->setGeometry(QRect(20, 50, 21, 16));
        label_tcpiplabel_device_3->setLayoutDirection(Qt::LeftToRight);
        label_tcpportlabel_device_3 = new QLabel(groupBox_2);
        label_tcpportlabel_device_3->setObjectName(QString::fromUtf8("label_tcpportlabel_device_3"));
        label_tcpportlabel_device_3->setGeometry(QRect(180, 50, 41, 16));
        lineEdit_tcpip_device_3 = new QLineEdit(groupBox_2);
        lineEdit_tcpip_device_3->setObjectName(QString::fromUtf8("lineEdit_tcpip_device_3"));
        lineEdit_tcpip_device_3->setGeometry(QRect(50, 50, 121, 21));
        lineEdit_tcpport_device_3 = new QLineEdit(groupBox_2);
        lineEdit_tcpport_device_3->setObjectName(QString::fromUtf8("lineEdit_tcpport_device_3"));
        lineEdit_tcpport_device_3->setGeometry(QRect(230, 50, 51, 21));
        btn_tcpconnect_device_3 = new QPushButton(groupBox_2);
        btn_tcpconnect_device_3->setObjectName(QString::fromUtf8("btn_tcpconnect_device_3"));
        btn_tcpconnect_device_3->setGeometry(QRect(310, 50, 75, 23));

        gridLayout->addWidget(groupBox_2, 1, 1, 1, 1);


        retranslateUi(StrongLightOption);

        QMetaObject::connectSlotsByName(StrongLightOption);
    } // setupUi

    void retranslateUi(QWidget *StrongLightOption)
    {
        StrongLightOption->setWindowTitle(QCoreApplication::translate("StrongLightOption", "Form", nullptr));
        groupBox_Gimbal_IP_Option->setTitle(QCoreApplication::translate("StrongLightOption", "\345\274\272\345\205\211IP\350\256\276\347\275\256", nullptr));
        groupBox_1_changeOption->setTitle(QCoreApplication::translate("StrongLightOption", "\346\233\264\346\224\271\350\256\276\347\275\256\357\274\232", nullptr));
        label_tcp_device_3_1->setText(QCoreApplication::translate("StrongLightOption", "TCP\347\253\257\345\217\243\357\274\232", nullptr));
        label_tcpiplabel_device_3_1->setText(QCoreApplication::translate("StrongLightOption", "IP\357\274\232", nullptr));
        label_tcpportlabel_device_3_1->setText(QCoreApplication::translate("StrongLightOption", "port\357\274\232", nullptr));
        lineEdit_tcpip_device_3_1->setText(QString());
        btn_tcpsave_device_3_1->setText(QCoreApplication::translate("StrongLightOption", "\344\277\235\345\255\230", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("StrongLightOption", "\345\217\202\346\225\260\346\237\245\350\257\242\357\274\232", nullptr));
        label_tcp_device_3->setText(QCoreApplication::translate("StrongLightOption", "TCP\347\253\257\345\217\243\357\274\232", nullptr));
        label_tcpiplabel_device_3->setText(QCoreApplication::translate("StrongLightOption", "IP\357\274\232", nullptr));
        label_tcpportlabel_device_3->setText(QCoreApplication::translate("StrongLightOption", "port\357\274\232", nullptr));
        lineEdit_tcpip_device_3->setText(QString());
        btn_tcpconnect_device_3->setText(QCoreApplication::translate("StrongLightOption", "\350\277\236\346\216\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StrongLightOption: public Ui_StrongLightOption {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STRONGLIGHTOPTION_H
