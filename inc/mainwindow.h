#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QVector>
#include "inc/gimbal.h"
#include "inc/gimbaloption.h"
//#include "inc/netportrelay.h"
#include "inc/acousticcontrol.h"
#include "inc/acousticcontroludp.h"
#include "inc/acousticcontroloption.h"
#include "inc/stronglight.h"
#include "inc/stronglightoption.h"
//#include "inc/netportrelayoption.h"
#include <QPainter>
#include <math.h>
#include <QMouseEvent>
#include <QFileDialog>
#include <QLabel>
#include "inc/QDaulLightCamera.h"
#include "inc/QOwWarnning.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
#define SMALL_CIRCLE_RADIUS 30 //小圆半径 （小圆图片分辨率为60*60）
#define BIG_CIRCLE_RADIUS 90 //大圆半径 （大圆图片分辨率为180*180）
//device name
#ifndef DEVICE_NAME_GIMBAL
#define DEVICE_NAME_GIMBAL              0X01
#endif
#ifndef DEVICE_NAME_ACOUSTICCONTROL_UDP
#define DEVICE_NAME_ACOUSTICCONTROL_UDP 0X02
#endif
#ifndef DEVICE_NAME_ACOUSTICCONTROL
#define DEVICE_NAME_ACOUSTICCONTROL     0X03
#endif
//painter value
#define IMAGE_PAINTER_1_CENTEROFCIRCLE_X    450
#define IMAGE_PAINTER_1_CENTEROFCIRCLE_Y    440
#define IMAGE_PAINTER_1_RECTANGLE_WIDTH     200.0
#define IMAGE_PAINTER_1_RECTANGLE_HEIGHT    200.0
#define IMAGE_PAINTER_1_RECTANGLE_X     (IMAGE_PAINTER_1_CENTEROFCIRCLE_X - (IMAGE_PAINTER_1_RECTANGLE_WIDTH/2))
#define IMAGE_PAINTER_1_RECTANGLE_Y     (IMAGE_PAINTER_1_CENTEROFCIRCLE_Y - (IMAGE_PAINTER_1_RECTANGLE_HEIGHT/2))
#define IMAGE_PAINTER_1_RECTANGLE_SPANANGLE  60
#define IMAGE_PAINTER_1_RADIALGRAD_X        IMAGE_PAINTER_1_CENTEROFCIRCLE_X
#define IMAGE_PAINTER_1_RADIALGRAD_Y        IMAGE_PAINTER_1_CENTEROFCIRCLE_Y
#define IMAGE_PAINTER_1_RADIALGRAD_RADIUS   (IMAGE_PAINTER_1_RECTANGLE_WIDTH/2)
#define IMAGE_PAINTER_2_LINE_POINT1_X   IMAGE_PAINTER_1_CENTEROFCIRCLE_X
#define IMAGE_PAINTER_2_LINE_POINT1_Y   IMAGE_PAINTER_1_CENTEROFCIRCLE_Y
#define IMAGE_PAINTER_2_LINE_POINT1_LENGTH   110
#define IMAGE_PAINTER_2_LINE_POINT2_X   IMAGE_PAINTER_2_LINE_POINT1_X
#define IMAGE_PAINTER_2_LINE_POINT2_Y   (IMAGE_PAINTER_2_LINE_POINT1_Y - IMAGE_PAINTER_2_LINE_POINT1_LENGTH)

#define BIG_CIRCLE_X    450
#define BIG_CIRCLE_Y    655

// 主界面
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void DataInit();
    void setvalue_speed_horizontal(int val);
    void setvalue_speed_vertical(int val);
    int getvalue();
private slots:
    void onTimeOut();
    void DeviceInit();
    void GimbalInit();
    void GimbalStart();
    void AcousticcontrolInit();
    void AcousticcontrolStart();
    void AcousticcontrolUDPInit();
    void AcousticcontrolUDPStart();
    void StrongLightInit();
    void StrongLightStart();
    void handle_AngleData(int type,int angle);
    void handle_ConnectState(int deviceName,QString IP,QString Port,int State);
    void handle_listWidgetAddItem(QString);
    void handle_listWidgetClear();
    void btnBroadcastClicked();
    void handle_SongPrevious(QString);
    void handle_SongNext(QString);

    void CameraInit();
//    void CameraStart();
    void WarnningInit();
//    void WarnningStart();


/*****/

    void on_GimbaOptionPage_clicked();

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_btn_switch_strongLight_clicked();

    void on_btn_switch_flash_clicked();

signals:
    void sig(int value);

private:
    Ui::MainWindow *ui;
    void UIInit();
    void SlotConnectToSignal();
    void UIControlsRun();
    int angle_horizontal;
    int angle_vertical;
    /****/
    QPoint BigCir_xy; //大圆圆心坐标
    QPoint SmallCir_xy; //小圆圆心坐标
    bool MousePressFlag; //鼠标按下的标志位
    quint8 directionOnOffFlag;
    quint8 directionOnOffFlagbuffer;
    QPoint MapRemov_Old;

    QImage Image;
    QPixmap pixmap;
    QPixmap fixpixmap;
    QImage Image_horizontal;
    QPixmap pixmap_horizontal;
    QPixmap fixpixmap_horizontal;
    double horizontalangle;
    QTransform matrix;
    void RoteInit();
    void RoteHorizontal(int data);
    void RockerInit();
    void paintEvent(QPaintEvent *event); //绘图事件：绘制地图、摇杆中的大圆和小圆
    void mouseMoveEvent(QMouseEvent *); //鼠标移动事件：实现摇杆功能
    void mousePressEvent(QMouseEvent *); //鼠标按下事件：获取摇杆所在的实时坐标
    void mouseReleaseEvent(QMouseEvent *); //鼠标释放事件：释放鼠标，则MousePressFlag复位，且小圆圆心设置为初始值，更新绘图事件后，重新绘图使小圆（摇杆）回到原处
    /*****/
    QTimer *lcdTimer;
    Gimbal *gimbal;
    Acousticcontrol *acousticcontrol;
    AcousticcontrolUDP *acousticcontrolUdp;
    QThread *thread_acousticcontrolUdp;
    QThread *thread_Gimbal;
    QThread *thread_AcousticControl;
    QThread *thread_NetProtrelay;
    StrongLight *stronglight;
    QThread *thread_StrongLight;
    QDaulLightCamera* m_daulLight;
    QThread *thread_DaulLightCamera;
    QOwWarnning* m_OwWarn;
    QThread *thread_OwWarnning;
    int g_GimbalState;
    void SetLED(QLabel* label,int color,int size);
    void SetCircularButton(QPushButton *btn,int color,int size);
    /*****/
    GimbalOption *gimbalOption;
    AcousticcontrolOption *acousticcontrolOption;
    StrongLightOption *strongLightOption;
};
#endif // MAINWINDOW_H
