/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_gimbaldisplay;
    QLabel *label_horizontal;
    QLCDNumber *lcdNumber_horizontal;
    QLabel *label_vertical;
    QLCDNumber *lcdNumber_vertical;
    QSlider *slider_speed_vertical;
    QSlider *slider_speed_horizontal;
    QLabel *label_speed_vertical_control;
    QLabel *label_speed_horrizontal_control;
    QGroupBox *groupBox_gimbalcontrol;
    QGroupBox *groupBox_playerVolSet;
    QGridLayout *gridLayout_2;
    QLabel *label_PlayVol;
    QSlider *Slider_PlayVolume;
    QLabel *label_CalVol;
    QSlider *Slider_CapVolume;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout;
    QLabel *label_bird_repellent_switch_led;
    QLabel *label_broadcast_led;
    QLabel *label;
    QLabel *label_2;
    QGroupBox *groupBox_5;
    QListWidget *listWidget;
    QPushButton *pushButton_listUpdate;
    QPushButton *btnRepeatPlay;
    QPushButton *btnPlay;
    QPushButton *btnPause;
    QPushButton *btnPrevious;
    QPushButton *btnNext;
    QGroupBox *groupBox_6;
    QLabel *label_horizontal_pixmap;
    QGroupBox *groupBox_7;
    QLabel *label_Spotlight_led;
    QLabel *label_Dazzling_led;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_Frequency;
    QPushButton *btn_switch_strongLight;
    QPushButton *btn_switch_flash;
    QPushButton *btn_angle_min;
    QPushButton *btn_angle_max;
    QGroupBox *groupBox;
    QLabel *label_8;
    QPushButton *btnBroadcast;
    QGroupBox *groupBox_2;
    QPushButton *pushButton;
    QPushButton *GimbaOptionPage;
    QPushButton *pushButton_2;
    QGroupBox *gbMediaPlayer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 800);
        QFont font;
        font.setPointSize(9);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox_gimbaldisplay = new QGroupBox(centralwidget);
        groupBox_gimbaldisplay->setObjectName(QString::fromUtf8("groupBox_gimbaldisplay"));
        groupBox_gimbaldisplay->setGeometry(QRect(330, 90, 261, 211));
        label_horizontal = new QLabel(groupBox_gimbaldisplay);
        label_horizontal->setObjectName(QString::fromUtf8("label_horizontal"));
        label_horizontal->setGeometry(QRect(9, 40, 131, 21));
        lcdNumber_horizontal = new QLCDNumber(groupBox_gimbaldisplay);
        lcdNumber_horizontal->setObjectName(QString::fromUtf8("lcdNumber_horizontal"));
        lcdNumber_horizontal->setGeometry(QRect(149, 30, 91, 31));
        lcdNumber_horizontal->setFont(font);
        label_vertical = new QLabel(groupBox_gimbaldisplay);
        label_vertical->setObjectName(QString::fromUtf8("label_vertical"));
        label_vertical->setGeometry(QRect(10, 80, 131, 21));
        lcdNumber_vertical = new QLCDNumber(groupBox_gimbaldisplay);
        lcdNumber_vertical->setObjectName(QString::fromUtf8("lcdNumber_vertical"));
        lcdNumber_vertical->setGeometry(QRect(149, 70, 91, 31));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(false);
        lcdNumber_vertical->setFont(font1);
        lcdNumber_vertical->setSegmentStyle(QLCDNumber::Filled);
        slider_speed_vertical = new QSlider(groupBox_gimbaldisplay);
        slider_speed_vertical->setObjectName(QString::fromUtf8("slider_speed_vertical"));
        slider_speed_vertical->setGeometry(QRect(10, 180, 241, 22));
        slider_speed_vertical->setMinimum(1);
        slider_speed_vertical->setMaximum(8);
        slider_speed_vertical->setValue(1);
        slider_speed_vertical->setOrientation(Qt::Horizontal);
        slider_speed_horizontal = new QSlider(groupBox_gimbaldisplay);
        slider_speed_horizontal->setObjectName(QString::fromUtf8("slider_speed_horizontal"));
        slider_speed_horizontal->setGeometry(QRect(10, 130, 241, 22));
        slider_speed_horizontal->setMinimum(1);
        slider_speed_horizontal->setMaximum(8);
        slider_speed_horizontal->setSingleStep(1);
        slider_speed_horizontal->setValue(1);
        slider_speed_horizontal->setOrientation(Qt::Horizontal);
        label_speed_vertical_control = new QLabel(groupBox_gimbaldisplay);
        label_speed_vertical_control->setObjectName(QString::fromUtf8("label_speed_vertical_control"));
        label_speed_vertical_control->setGeometry(QRect(10, 160, 131, 16));
        label_speed_horrizontal_control = new QLabel(groupBox_gimbaldisplay);
        label_speed_horrizontal_control->setObjectName(QString::fromUtf8("label_speed_horrizontal_control"));
        label_speed_horrizontal_control->setGeometry(QRect(10, 110, 131, 16));
        groupBox_gimbalcontrol = new QGroupBox(centralwidget);
        groupBox_gimbalcontrol->setObjectName(QString::fromUtf8("groupBox_gimbalcontrol"));
        groupBox_gimbalcontrol->setGeometry(QRect(330, 550, 261, 201));
        groupBox_playerVolSet = new QGroupBox(centralwidget);
        groupBox_playerVolSet->setObjectName(QString::fromUtf8("groupBox_playerVolSet"));
        groupBox_playerVolSet->setGeometry(QRect(10, 120, 311, 111));
        gridLayout_2 = new QGridLayout(groupBox_playerVolSet);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_PlayVol = new QLabel(groupBox_playerVolSet);
        label_PlayVol->setObjectName(QString::fromUtf8("label_PlayVol"));

        gridLayout_2->addWidget(label_PlayVol, 0, 0, 1, 1);

        Slider_PlayVolume = new QSlider(groupBox_playerVolSet);
        Slider_PlayVolume->setObjectName(QString::fromUtf8("Slider_PlayVolume"));
        Slider_PlayVolume->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(Slider_PlayVolume, 0, 1, 1, 1);

        label_CalVol = new QLabel(groupBox_playerVolSet);
        label_CalVol->setObjectName(QString::fromUtf8("label_CalVol"));

        gridLayout_2->addWidget(label_CalVol, 1, 0, 1, 1);

        Slider_CapVolume = new QSlider(groupBox_playerVolSet);
        Slider_CapVolume->setObjectName(QString::fromUtf8("Slider_CapVolume"));
        Slider_CapVolume->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(Slider_CapVolume, 1, 1, 1, 1);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 10, 311, 101));
        gridLayout = new QGridLayout(groupBox_4);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_bird_repellent_switch_led = new QLabel(groupBox_4);
        label_bird_repellent_switch_led->setObjectName(QString::fromUtf8("label_bird_repellent_switch_led"));

        gridLayout->addWidget(label_bird_repellent_switch_led, 0, 0, 1, 1);

        label_broadcast_led = new QLabel(groupBox_4);
        label_broadcast_led->setObjectName(QString::fromUtf8("label_broadcast_led"));

        gridLayout->addWidget(label_broadcast_led, 0, 1, 1, 1);

        label = new QLabel(groupBox_4);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 240, 311, 511));
        listWidget = new QListWidget(groupBox_5);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(0, 20, 301, 301));
        pushButton_listUpdate = new QPushButton(groupBox_5);
        pushButton_listUpdate->setObjectName(QString::fromUtf8("pushButton_listUpdate"));
        pushButton_listUpdate->setGeometry(QRect(0, 420, 90, 80));
        btnRepeatPlay = new QPushButton(groupBox_5);
        btnRepeatPlay->setObjectName(QString::fromUtf8("btnRepeatPlay"));
        btnRepeatPlay->setGeometry(QRect(200, 420, 90, 80));
        btnPlay = new QPushButton(groupBox_5);
        btnPlay->setObjectName(QString::fromUtf8("btnPlay"));
        btnPlay->setGeometry(QRect(100, 420, 90, 80));
        btnPause = new QPushButton(groupBox_5);
        btnPause->setObjectName(QString::fromUtf8("btnPause"));
        btnPause->setGeometry(QRect(0, 330, 90, 80));
        btnPrevious = new QPushButton(groupBox_5);
        btnPrevious->setObjectName(QString::fromUtf8("btnPrevious"));
        btnPrevious->setGeometry(QRect(100, 330, 90, 80));
        btnNext = new QPushButton(groupBox_5);
        btnNext->setObjectName(QString::fromUtf8("btnNext"));
        btnNext->setGeometry(QRect(200, 330, 90, 80));
        groupBox_6 = new QGroupBox(centralwidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(330, 300, 261, 251));
        label_horizontal_pixmap = new QLabel(groupBox_6);
        label_horizontal_pixmap->setObjectName(QString::fromUtf8("label_horizontal_pixmap"));
        label_horizontal_pixmap->setGeometry(QRect(50, 130, 53, 15));
        groupBox_7 = new QGroupBox(centralwidget);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(600, 500, 451, 251));
        label_Spotlight_led = new QLabel(groupBox_7);
        label_Spotlight_led->setObjectName(QString::fromUtf8("label_Spotlight_led"));
        label_Spotlight_led->setGeometry(QRect(50, 20, 53, 15));
        label_Dazzling_led = new QLabel(groupBox_7);
        label_Dazzling_led->setObjectName(QString::fromUtf8("label_Dazzling_led"));
        label_Dazzling_led->setGeometry(QRect(170, 20, 53, 15));
        label_3 = new QLabel(groupBox_7);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 40, 53, 15));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(groupBox_7);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(160, 40, 53, 15));
        label_4->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(groupBox_7);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 70, 61, 16));
        label_Frequency = new QLabel(groupBox_7);
        label_Frequency->setObjectName(QString::fromUtf8("label_Frequency"));
        label_Frequency->setGeometry(QRect(90, 70, 53, 15));
        btn_switch_strongLight = new QPushButton(groupBox_7);
        btn_switch_strongLight->setObjectName(QString::fromUtf8("btn_switch_strongLight"));
        btn_switch_strongLight->setGeometry(QRect(20, 160, 75, 23));
        btn_switch_flash = new QPushButton(groupBox_7);
        btn_switch_flash->setObjectName(QString::fromUtf8("btn_switch_flash"));
        btn_switch_flash->setGeometry(QRect(150, 160, 75, 23));
        btn_angle_min = new QPushButton(groupBox_7);
        btn_angle_min->setObjectName(QString::fromUtf8("btn_angle_min"));
        btn_angle_min->setGeometry(QRect(20, 200, 75, 23));
        btn_angle_max = new QPushButton(groupBox_7);
        btn_angle_max->setObjectName(QString::fromUtf8("btn_angle_max"));
        btn_angle_max->setGeometry(QRect(150, 200, 75, 23));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(330, 0, 261, 91));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 60, 71, 16));
        btnBroadcast = new QPushButton(groupBox);
        btnBroadcast->setObjectName(QString::fromUtf8("btnBroadcast"));
        btnBroadcast->setGeometry(QRect(30, 20, 71, 21));
        btnBroadcast->setFont(font);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(1060, 500, 91, 191));
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 20, 75, 23));
        GimbaOptionPage = new QPushButton(groupBox_2);
        GimbaOptionPage->setObjectName(QString::fromUtf8("GimbaOptionPage"));
        GimbaOptionPage->setGeometry(QRect(10, 80, 75, 23));
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 50, 75, 23));
        gbMediaPlayer = new QGroupBox(centralwidget);
        gbMediaPlayer->setObjectName(QString::fromUtf8("gbMediaPlayer"));
        gbMediaPlayer->setGeometry(QRect(600, 0, 550, 490));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_gimbaldisplay->setTitle(QCoreApplication::translate("MainWindow", "\344\272\221\345\217\260\350\247\222\345\272\246\345\222\214\350\275\254\351\200\237\346\230\276\347\244\272\345\214\272\345\237\237", nullptr));
        label_horizontal->setText(QCoreApplication::translate("MainWindow", "\346\260\264\345\271\263\350\247\222\345\272\246\357\274\232", nullptr));
        label_vertical->setText(QCoreApplication::translate("MainWindow", "\344\277\257\344\273\260\350\247\222\345\272\246\357\274\232", nullptr));
        label_speed_vertical_control->setText(QCoreApplication::translate("MainWindow", "\345\236\202\347\233\264\351\200\237\345\272\246\346\216\247\345\210\266\357\274\232", nullptr));
        label_speed_horrizontal_control->setText(QCoreApplication::translate("MainWindow", "\346\260\264\345\271\263\351\200\237\345\272\246\346\216\247\345\210\266:", nullptr));
        groupBox_gimbalcontrol->setTitle(QCoreApplication::translate("MainWindow", "\344\272\221\345\217\260\346\226\271\345\220\221\346\216\247\345\210\266\345\214\272\345\237\237", nullptr));
        groupBox_playerVolSet->setTitle(QCoreApplication::translate("MainWindow", "\345\244\232\345\252\222\344\275\223\351\237\263\351\207\217\350\256\276\347\275\256\345\214\272\345\237\237", nullptr));
        label_PlayVol->setText(QCoreApplication::translate("MainWindow", "\346\222\255\346\224\276\351\237\263\351\207\217\357\274\232", nullptr));
        label_CalVol->setText(QCoreApplication::translate("MainWindow", "\351\207\207\351\233\206\351\237\263\351\207\217\357\274\232", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\346\214\207\347\244\272\347\201\257\345\214\272\345\237\237", nullptr));
        label_bird_repellent_switch_led->setText(QCoreApplication::translate("MainWindow", "led_bird_repellent", nullptr));
        label_broadcast_led->setText(QCoreApplication::translate("MainWindow", "led_broadcast", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\351\251\261\351\270\237", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\226\212\350\257\235", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "\351\237\263\351\242\221\346\226\207\344\273\266\346\230\276\347\244\272\345\214\272\345\237\237", nullptr));
        pushButton_listUpdate->setText(QCoreApplication::translate("MainWindow", "\345\210\227\350\241\250\346\233\264\346\226\260", nullptr));
        btnRepeatPlay->setText(QCoreApplication::translate("MainWindow", "\345\215\225\346\233\262\345\276\252\347\216\257", nullptr));
        btnPlay->setText(QCoreApplication::translate("MainWindow", "\346\222\255\346\224\276", nullptr));
        btnPause->setText(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234/\347\273\247\347\273\255", nullptr));
        btnPrevious->setText(QCoreApplication::translate("MainWindow", "\344\270\212\344\270\200\346\233\262", nullptr));
        btnNext->setText(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\346\233\262", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "\344\272\221\345\217\260\345\222\214\350\275\246\345\244\264\347\233\270\345\257\271\344\275\215\347\275\256\346\230\276\347\244\272\345\214\272\345\237\237", nullptr));
        label_horizontal_pixmap->setText(QCoreApplication::translate("MainWindow", "photo", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "\345\274\272\345\205\211\351\242\221\347\216\207\343\200\201\347\255\211\347\272\247", nullptr));
        label_Spotlight_led->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_Dazzling_led->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\216\242\347\205\247", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\347\234\251\347\233\256", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\345\274\272\345\205\211\351\242\221\347\216\207\357\274\232", nullptr));
        label_Frequency->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        btn_switch_strongLight->setText(QCoreApplication::translate("MainWindow", "\345\274\272\345\205\211\345\274\200\345\205\263", nullptr));
        btn_switch_flash->setText(QCoreApplication::translate("MainWindow", "\351\227\252\347\203\201\345\274\200\345\205\263", nullptr));
        btn_angle_min->setText(QCoreApplication::translate("MainWindow", "\346\234\200\345\260\217\345\217\221\346\225\243\350\247\222", nullptr));
        btn_angle_max->setText(QCoreApplication::translate("MainWindow", "\346\234\200\345\244\247\345\217\221\346\225\243\350\247\222", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\351\251\261\351\270\237\351\237\263\344\270\216\345\226\212\350\257\235\345\214\272\345\237\237", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\344\270\200\351\224\256\345\226\212\350\257\235", nullptr));
        btnBroadcast->setText(QCoreApplication::translate("MainWindow", "button", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\346\250\241\345\235\227\350\256\276\347\275\256\345\214\272\345\237\237", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\345\274\272\345\243\260\350\256\276\347\275\256", nullptr));
        GimbaOptionPage->setText(QCoreApplication::translate("MainWindow", "\344\272\221\345\217\260\350\256\276\347\275\256", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\345\274\272\345\205\211\350\256\276\347\275\256", nullptr));
        gbMediaPlayer->setTitle(QCoreApplication::translate("MainWindow", "\350\247\206\351\242\221\346\230\276\347\244\272\345\214\272\345\237\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
