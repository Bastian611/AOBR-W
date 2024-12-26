/********************************************************************************
** Form generated from reading UI file 'gimbaloption.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GIMBALOPTION_H
#define UI_GIMBALOPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GimbalOption
{
public:
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_7;
    QGroupBox *groupBox_Gimbal_IP_Option;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox_1_changeOption;
    QLabel *label_tcp_device_1_1;
    QLabel *label_tcpiplabel_device_1_1;
    QLabel *label_tcpportlabel_device_1_1;
    QLineEdit *lineEdit_tcpip_device_1_1;
    QLineEdit *lineEdit_tcpport_device_1_1;
    QPushButton *btn_tcpsave_device_1_1;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *groupBox;
    QLabel *label_tcp_device_1;
    QLabel *label_tcpiplabel_device_1;
    QLabel *label_tcpportlabel_device_1;
    QLineEdit *lineEdit_tcpip_device_1;
    QLineEdit *lineEdit_tcpport_device_1;
    QPushButton *btn_tcpconnect_device_1;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_5;
    QGroupBox *groupBox_Gimbal_RealtimeAckhaul_Option;
    QCheckBox *checkBoxRealtimeAckhaulOpenSet;
    QComboBox *comboBox_RealtimeAckhaul;
    QPushButton *btnRealtimeAckhaulClose;
    QPushButton *btnRealtimeAckhaulOpen;
    QLabel *label_RealtimeAckhaul;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer_6;
    QGroupBox *groupBox_Gimbal_Speed_Option;
    QSpinBox *spinBox_speed_horizontal;
    QLabel *label_speed_horrizontal;
    QLabel *label_speed_vertical;
    QSpinBox *spinBox_speed_vertical;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_11;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *btnOneClickZeroing;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_8;

    void setupUi(QWidget *GimbalOption)
    {
        if (GimbalOption->objectName().isEmpty())
            GimbalOption->setObjectName(QString::fromUtf8("GimbalOption"));
        GimbalOption->resize(829, 830);
        gridLayout_2 = new QGridLayout(GimbalOption);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer_7 = new QSpacerItem(36, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 2, 3, 1, 1);

        groupBox_Gimbal_IP_Option = new QGroupBox(GimbalOption);
        groupBox_Gimbal_IP_Option->setObjectName(QString::fromUtf8("groupBox_Gimbal_IP_Option"));
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
        label_tcp_device_1_1 = new QLabel(groupBox_1_changeOption);
        label_tcp_device_1_1->setObjectName(QString::fromUtf8("label_tcp_device_1_1"));
        label_tcp_device_1_1->setGeometry(QRect(10, 30, 91, 16));
        label_tcpiplabel_device_1_1 = new QLabel(groupBox_1_changeOption);
        label_tcpiplabel_device_1_1->setObjectName(QString::fromUtf8("label_tcpiplabel_device_1_1"));
        label_tcpiplabel_device_1_1->setGeometry(QRect(20, 50, 21, 16));
        label_tcpiplabel_device_1_1->setLayoutDirection(Qt::LeftToRight);
        label_tcpportlabel_device_1_1 = new QLabel(groupBox_1_changeOption);
        label_tcpportlabel_device_1_1->setObjectName(QString::fromUtf8("label_tcpportlabel_device_1_1"));
        label_tcpportlabel_device_1_1->setGeometry(QRect(210, 50, 41, 16));
        lineEdit_tcpip_device_1_1 = new QLineEdit(groupBox_1_changeOption);
        lineEdit_tcpip_device_1_1->setObjectName(QString::fromUtf8("lineEdit_tcpip_device_1_1"));
        lineEdit_tcpip_device_1_1->setGeometry(QRect(50, 50, 141, 21));
        lineEdit_tcpport_device_1_1 = new QLineEdit(groupBox_1_changeOption);
        lineEdit_tcpport_device_1_1->setObjectName(QString::fromUtf8("lineEdit_tcpport_device_1_1"));
        lineEdit_tcpport_device_1_1->setGeometry(QRect(260, 50, 51, 21));
        btn_tcpsave_device_1_1 = new QPushButton(groupBox_1_changeOption);
        btn_tcpsave_device_1_1->setObjectName(QString::fromUtf8("btn_tcpsave_device_1_1"));
        btn_tcpsave_device_1_1->setGeometry(QRect(340, 50, 71, 23));

        gridLayout->addWidget(groupBox_1_changeOption, 3, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 4, 1, 1, 1);

        groupBox = new QGroupBox(groupBox_Gimbal_IP_Option);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(100);
        sizePolicy.setVerticalStretch(100);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(500, 100));
        label_tcp_device_1 = new QLabel(groupBox);
        label_tcp_device_1->setObjectName(QString::fromUtf8("label_tcp_device_1"));
        label_tcp_device_1->setGeometry(QRect(10, 30, 91, 16));
        label_tcpiplabel_device_1 = new QLabel(groupBox);
        label_tcpiplabel_device_1->setObjectName(QString::fromUtf8("label_tcpiplabel_device_1"));
        label_tcpiplabel_device_1->setGeometry(QRect(20, 50, 21, 16));
        label_tcpiplabel_device_1->setLayoutDirection(Qt::LeftToRight);
        label_tcpportlabel_device_1 = new QLabel(groupBox);
        label_tcpportlabel_device_1->setObjectName(QString::fromUtf8("label_tcpportlabel_device_1"));
        label_tcpportlabel_device_1->setGeometry(QRect(210, 50, 41, 16));
        lineEdit_tcpip_device_1 = new QLineEdit(groupBox);
        lineEdit_tcpip_device_1->setObjectName(QString::fromUtf8("lineEdit_tcpip_device_1"));
        lineEdit_tcpip_device_1->setGeometry(QRect(50, 50, 141, 21));
        lineEdit_tcpport_device_1 = new QLineEdit(groupBox);
        lineEdit_tcpport_device_1->setObjectName(QString::fromUtf8("lineEdit_tcpport_device_1"));
        lineEdit_tcpport_device_1->setGeometry(QRect(260, 50, 51, 21));
        btn_tcpconnect_device_1 = new QPushButton(groupBox);
        btn_tcpconnect_device_1->setObjectName(QString::fromUtf8("btn_tcpconnect_device_1"));
        btn_tcpconnect_device_1->setGeometry(QRect(340, 50, 75, 23));

        gridLayout->addWidget(groupBox, 1, 1, 1, 1);


        gridLayout_2->addWidget(groupBox_Gimbal_IP_Option, 1, 2, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_9, 2, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(94, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 1, 0, 1, 2);

        groupBox_Gimbal_RealtimeAckhaul_Option = new QGroupBox(GimbalOption);
        groupBox_Gimbal_RealtimeAckhaul_Option->setObjectName(QString::fromUtf8("groupBox_Gimbal_RealtimeAckhaul_Option"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_Gimbal_RealtimeAckhaul_Option->sizePolicy().hasHeightForWidth());
        groupBox_Gimbal_RealtimeAckhaul_Option->setSizePolicy(sizePolicy1);
        groupBox_Gimbal_RealtimeAckhaul_Option->setMinimumSize(QSize(600, 200));
        checkBoxRealtimeAckhaulOpenSet = new QCheckBox(groupBox_Gimbal_RealtimeAckhaul_Option);
        checkBoxRealtimeAckhaulOpenSet->setObjectName(QString::fromUtf8("checkBoxRealtimeAckhaulOpenSet"));
        checkBoxRealtimeAckhaulOpenSet->setGeometry(QRect(20, 30, 281, 19));
        checkBoxRealtimeAckhaulOpenSet->setChecked(true);
        comboBox_RealtimeAckhaul = new QComboBox(groupBox_Gimbal_RealtimeAckhaul_Option);
        comboBox_RealtimeAckhaul->setObjectName(QString::fromUtf8("comboBox_RealtimeAckhaul"));
        comboBox_RealtimeAckhaul->setGeometry(QRect(460, 30, 100, 22));
        btnRealtimeAckhaulClose = new QPushButton(groupBox_Gimbal_RealtimeAckhaul_Option);
        btnRealtimeAckhaulClose->setObjectName(QString::fromUtf8("btnRealtimeAckhaulClose"));
        btnRealtimeAckhaulClose->setGeometry(QRect(330, 70, 131, 100));
        btnRealtimeAckhaulOpen = new QPushButton(groupBox_Gimbal_RealtimeAckhaul_Option);
        btnRealtimeAckhaulOpen->setObjectName(QString::fromUtf8("btnRealtimeAckhaulOpen"));
        btnRealtimeAckhaulOpen->setGeometry(QRect(100, 70, 131, 100));
        label_RealtimeAckhaul = new QLabel(groupBox_Gimbal_RealtimeAckhaul_Option);
        label_RealtimeAckhaul->setObjectName(QString::fromUtf8("label_RealtimeAckhaul"));
        label_RealtimeAckhaul->setGeometry(QRect(340, 30, 111, 20));

        gridLayout_2->addWidget(groupBox_Gimbal_RealtimeAckhaul_Option, 2, 2, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_10, 3, 0, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_12, 5, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(32, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 3, 3, 1, 1);

        groupBox_Gimbal_Speed_Option = new QGroupBox(GimbalOption);
        groupBox_Gimbal_Speed_Option->setObjectName(QString::fromUtf8("groupBox_Gimbal_Speed_Option"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_Gimbal_Speed_Option->sizePolicy().hasHeightForWidth());
        groupBox_Gimbal_Speed_Option->setSizePolicy(sizePolicy2);
        groupBox_Gimbal_Speed_Option->setMinimumSize(QSize(600, 70));
        spinBox_speed_horizontal = new QSpinBox(groupBox_Gimbal_Speed_Option);
        spinBox_speed_horizontal->setObjectName(QString::fromUtf8("spinBox_speed_horizontal"));
        spinBox_speed_horizontal->setEnabled(true);
        spinBox_speed_horizontal->setGeometry(QRect(140, 20, 40, 40));
        QFont font;
        font.setPointSize(20);
        spinBox_speed_horizontal->setFont(font);
        label_speed_horrizontal = new QLabel(groupBox_Gimbal_Speed_Option);
        label_speed_horrizontal->setObjectName(QString::fromUtf8("label_speed_horrizontal"));
        label_speed_horrizontal->setGeometry(QRect(30, 30, 81, 21));
        label_speed_vertical = new QLabel(groupBox_Gimbal_Speed_Option);
        label_speed_vertical->setObjectName(QString::fromUtf8("label_speed_vertical"));
        label_speed_vertical->setGeometry(QRect(250, 30, 91, 31));
        spinBox_speed_vertical = new QSpinBox(groupBox_Gimbal_Speed_Option);
        spinBox_speed_vertical->setObjectName(QString::fromUtf8("spinBox_speed_vertical"));
        spinBox_speed_vertical->setGeometry(QRect(390, 20, 40, 40));
        spinBox_speed_vertical->setFont(font);

        gridLayout_2->addWidget(groupBox_Gimbal_Speed_Option, 3, 2, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_5, 6, 2, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(87, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_11, 5, 3, 1, 1);

        groupBox_2 = new QGroupBox(GimbalOption);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        groupBox_2->setMinimumSize(QSize(0, 80));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_13 = new QSpacerItem(253, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_13);

        btnOneClickZeroing = new QPushButton(groupBox_2);
        btnOneClickZeroing->setObjectName(QString::fromUtf8("btnOneClickZeroing"));
        sizePolicy1.setHeightForWidth(btnOneClickZeroing->sizePolicy().hasHeightForWidth());
        btnOneClickZeroing->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(btnOneClickZeroing);

        horizontalSpacer_14 = new QSpacerItem(252, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_14);


        gridLayout_2->addWidget(groupBox_2, 5, 1, 1, 2);

        verticalSpacer_6 = new QSpacerItem(20, 26, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_6, 4, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 0, 2, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(87, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_8, 1, 3, 1, 1);


        retranslateUi(GimbalOption);

        QMetaObject::connectSlotsByName(GimbalOption);
    } // setupUi

    void retranslateUi(QWidget *GimbalOption)
    {
        GimbalOption->setWindowTitle(QCoreApplication::translate("GimbalOption", "Form", nullptr));
        groupBox_Gimbal_IP_Option->setTitle(QCoreApplication::translate("GimbalOption", "\344\272\221\345\217\260IP\350\256\276\347\275\256", nullptr));
        groupBox_1_changeOption->setTitle(QCoreApplication::translate("GimbalOption", "\346\233\264\346\224\271\350\256\276\347\275\256\357\274\232", nullptr));
        label_tcp_device_1_1->setText(QCoreApplication::translate("GimbalOption", "TCP\347\253\257\345\217\243\357\274\232", nullptr));
        label_tcpiplabel_device_1_1->setText(QCoreApplication::translate("GimbalOption", "IP\357\274\232", nullptr));
        label_tcpportlabel_device_1_1->setText(QCoreApplication::translate("GimbalOption", "port\357\274\232", nullptr));
        lineEdit_tcpip_device_1_1->setText(QString());
        btn_tcpsave_device_1_1->setText(QCoreApplication::translate("GimbalOption", "\344\277\235\345\255\230", nullptr));
        groupBox->setTitle(QCoreApplication::translate("GimbalOption", "\345\217\202\346\225\260\346\237\245\350\257\242\357\274\232", nullptr));
        label_tcp_device_1->setText(QCoreApplication::translate("GimbalOption", "TCP\347\253\257\345\217\243\357\274\232", nullptr));
        label_tcpiplabel_device_1->setText(QCoreApplication::translate("GimbalOption", "IP\357\274\232", nullptr));
        label_tcpportlabel_device_1->setText(QCoreApplication::translate("GimbalOption", "port\357\274\232", nullptr));
        lineEdit_tcpip_device_1->setText(QString());
        btn_tcpconnect_device_1->setText(QCoreApplication::translate("GimbalOption", "\350\277\236\346\216\245", nullptr));
        groupBox_Gimbal_RealtimeAckhaul_Option->setTitle(QCoreApplication::translate("GimbalOption", "\350\247\222\345\272\246\345\233\236\344\274\240\350\256\276\347\275\256", nullptr));
        checkBoxRealtimeAckhaulOpenSet->setText(QCoreApplication::translate("GimbalOption", "\350\247\222\345\272\246\345\233\236\344\274\240\345\212\237\350\203\275(\351\207\215\345\220\257\347\224\237\346\225\210)", nullptr));
        btnRealtimeAckhaulClose->setText(QCoreApplication::translate("GimbalOption", "\345\205\263\351\227\255\345\256\236\346\227\266\345\233\236\344\274\240", nullptr));
        btnRealtimeAckhaulOpen->setText(QCoreApplication::translate("GimbalOption", "\346\211\223\345\274\200\345\256\236\346\227\266\345\233\236\344\274\240", nullptr));
        label_RealtimeAckhaul->setText(QCoreApplication::translate("GimbalOption", "\345\233\236\344\274\240\351\242\221\347\216\207(hz):", nullptr));
        groupBox_Gimbal_Speed_Option->setTitle(QCoreApplication::translate("GimbalOption", "\344\277\257\344\273\260\351\200\237\345\272\246\350\256\276\347\275\256", nullptr));
        label_speed_horrizontal->setText(QCoreApplication::translate("GimbalOption", "\346\260\264\345\271\263\351\200\237\345\272\246\357\274\232", nullptr));
        label_speed_vertical->setText(QCoreApplication::translate("GimbalOption", "\345\236\202\347\233\264\351\200\237\345\272\246\357\274\232", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("GimbalOption", "\344\270\200\351\224\256\345\275\222\351\233\266", nullptr));
        btnOneClickZeroing->setText(QCoreApplication::translate("GimbalOption", "\344\270\200\351\224\256\345\275\222\351\233\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GimbalOption: public Ui_GimbalOption {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GIMBALOPTION_H
