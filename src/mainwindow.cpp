#include "inc/mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGlobal>
#include <QString>
#include <QDebug>
#include <QTimer>
#include <QMediaPlayer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("强声强光告警应用软件");
    //1.设备初始化
    DeviceInit();
    //1.1 建设云台通信管道
    //1.2 建设网口继电器通信管道
    //1.3 建设声波控制通信管道
    //2.通信数据初始化
    DataInit();
    //3.加载配置项
    //4.建设通信管道
    //5.线程启动
    UIControlsRun();
    //5.1启动云台线程
    GimbalStart();
    //5.2启动网口继电器线程
    AcousticcontrolStart();
    AcousticcontrolUDPStart();
    //6.启动强光线程
    StrongLightStart();
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::DeviceInit()
{
    GimbalInit();
    AcousticcontrolInit();
    AcousticcontrolUDPInit();
    StrongLightInit();
    CameraInit();
    WarnningInit();
}
void MainWindow::GimbalInit()
{
    gimbal = new Gimbal();
    gimbalOption = new GimbalOption();
    gimbalOption->hide();
    thread_Gimbal = new QThread();
    gimbal->setObjectName("Gimbal");
    gimbal->moveToThread(thread_Gimbal);
    //摇杆初始化
    RockerInit();
}
void MainWindow::AcousticcontrolInit()
{
    acousticcontrol = new Acousticcontrol();
    acousticcontrolOption = new AcousticcontrolOption();
    acousticcontrolOption->hide();
    thread_AcousticControl = new QThread();
    acousticcontrol->setObjectName("Acousticcontrol");
    acousticcontrol->moveToThread(thread_AcousticControl);

}
void MainWindow::AcousticcontrolUDPInit()
{
    acousticcontrolUdp = new AcousticcontrolUDP();
    thread_acousticcontrolUdp = new QThread();
    acousticcontrolUdp->moveToThread(thread_acousticcontrolUdp);
}
void MainWindow::StrongLightInit()
{
    stronglight = new StrongLight();
    strongLightOption = new StrongLightOption();
    strongLightOption->hide();
    thread_StrongLight = new QThread();
    stronglight->setObjectName("StrongLight");
    stronglight->moveToThread(thread_StrongLight);
}

void MainWindow::CameraInit()
{
#if __WIN32__
    m_daulLight = new QDaulLightCamera(ui->gbMediaPlayer);
    m_daulLight->slotStartVideoPlayer();
    thread_DaulLightCamera = new QThread();
    m_daulLight->setObjectName("DaulLightCamera");
    m_daulLight->moveToThread(thread_DaulLightCamera);
#else

#endif
}

void MainWindow::WarnningInit()
{
    m_OwWarn = new QOwWarnning(ui->gbOwWarnning);
    thread_OwWarnning = new QThread();
    m_OwWarn->setObjectName("Warnning");
    m_OwWarn->moveToThread(thread_OwWarnning);
}

void MainWindow::DataInit()
{
    UIInit();
    SlotConnectToSignal();
}
void MainWindow::UIInit()
{
    //lcd初始化
    ui->lcdNumber_horizontal->setDigitCount(6);
    ui->lcdNumber_horizontal->setMode(QLCDNumber::Dec);
    ui->lcdNumber_horizontal->setSegmentStyle(QLCDNumber::Flat);
    ui->lcdNumber_horizontal->setStyleSheet("border: 1px solid green; color: green; background: silver;");
    ui->lcdNumber_vertical->setDigitCount(6);
    ui->lcdNumber_vertical->setMode(QLCDNumber::Dec);
    ui->lcdNumber_vertical->setSegmentStyle(QLCDNumber::Flat);
    ui->lcdNumber_vertical->setStyleSheet("border: 1px solid green; color: green; background: silver;");
    //lcd的timer初始化
    lcdTimer = new QTimer(this);
    lcdTimer->setInterval(50);// 设置定时间隔ms
    angle_vertical = 0;
    angle_horizontal = 0;
    //滑块控件和数字输入盒子初始化
    ui->slider_speed_horizontal->setRange(1,8);
    ui->slider_speed_vertical->setRange(1,8);
    ui->slider_speed_horizontal->setPageStep(1);
    ui->slider_speed_vertical->setPageStep(1);
    ui->Slider_PlayVolume->setRange(1,100);
    ui->Slider_CapVolume->setRange(1,100);
    ui->Slider_PlayVolume->setPageStep(1);
    ui->Slider_CapVolume->setPageStep(1);
    ui->Slider_PlayVolume->setValue(1);
    ui->Slider_CapVolume->setValue(1);
    //Led指示灯初始化
    SetLED(ui->label_bird_repellent_switch_led,0,15);
    SetLED(ui->label_broadcast_led,0,15);
    SetLED(ui->label_Spotlight_led,0,15);
    SetLED(ui->label_Dazzling_led,0,15);
    SetCircularButton(ui->btnBroadcast,0,40);
    ui->label_Frequency->setText("10HZ");
    //云台TCP连接状态初始化
    g_GimbalState = 0;
}
void MainWindow::SlotConnectToSignal()
{
    /****lcd******/
    connect(lcdTimer, SIGNAL(timeout()), this, SLOT(onTimeOut()));

    /****云台水平速度与垂直速度滚动条与数值显示控制******/
    connect(ui->slider_speed_horizontal,SIGNAL(valueChanged(int)),gimbalOption,SLOT(HspinboxSetValue(int)));
    connect(ui->slider_speed_vertical,SIGNAL(valueChanged(int)),gimbalOption,SLOT(VspinboxSetValue(int)));
    connect(gimbalOption,SIGNAL(sig_Hslidervaluechanged(int)),ui->slider_speed_horizontal,SLOT(setValue(int)));
    connect(gimbalOption,SIGNAL(sig_Vslidervaluechanged(int)),ui->slider_speed_vertical,SLOT(setValue(int)));
    /****云台角度自动回传设置******/
    connect(gimbal,SIGNAL(sendAngleData(int,int)),this,SLOT(handle_AngleData(int,int)));

    connect(gimbalOption,SIGNAL(sig_btnRealtimeAckhaulOpen()),gimbal,SLOT(btnRealtimeAckhaulOpenClicked()));
    connect(gimbalOption,SIGNAL(sig_btnRealtimeAckhaulClose()),gimbal,SLOT(btnRealtimeAckhaulCloseClicked()));
    connect(gimbalOption,SIGNAL(sig_RealtimeAckhaulTextChanged(QString)),gimbal,SLOT(comboBox_RealtimeAckhaulChange(QString)));
    connect(gimbalOption,SIGNAL(sig_checkBoxRealtimeAckhaulOpenSet(bool)),gimbal,SLOT(handle_checkBoxRealtimeAckhaulOpenSet(bool)));

    /****强声设备功能块:设备1******/
    connect(ui->pushButton_listUpdate,SIGNAL(clicked()),acousticcontrol,SLOT(playerListUpdate()));
    connect(ui->btnPlay,SIGNAL(clicked()),acousticcontrol,SLOT(Play()));
    connect(ui->btnPause,SIGNAL(clicked()),acousticcontrol,SLOT(Pause()));
    connect(ui->btnPrevious,SIGNAL(clicked()),acousticcontrol,SLOT(SongPrevious()));
    connect(ui->btnNext,SIGNAL(clicked()),acousticcontrol,SLOT(SongNext()));
    connect(ui->btnRepeatPlay,SIGNAL(clicked()),acousticcontrol,SLOT(SongSinglecycle()));
    connect(ui->Slider_PlayVolume,SIGNAL(valueChanged(int)),acousticcontrol,SLOT(SliderPLayerVolumeChanged(int)));
    connect(ui->Slider_CapVolume,SIGNAL(valueChanged(int)),acousticcontrol,SLOT(SliderCapVolumeChanged(int)));
    connect(ui->listWidget,SIGNAL(doubleClicked(QModelIndex)),acousticcontrol,SLOT(SongListdoubleClick(QModelIndex)));
    connect(acousticcontrol,SIGNAL(sig_listWidgetAddItem(QString)),this,SLOT(handle_listWidgetAddItem(QString)));//当有设备2时，设备2的mp3文件顺序和数量应与设备1一致
    connect(acousticcontrol,SIGNAL(sig_listWidgetClear()),this,SLOT(handle_listWidgetClear()));
    connect(acousticcontrol,SIGNAL(sig_SongNext(QString)),this,SLOT(handle_SongNext(QString)));
    connect(acousticcontrol,SIGNAL(sig_SongPrevious(QString)),this,SLOT(handle_SongPrevious(QString)));

    /****强声设备一键驱散功能:设备1******/
    connect(acousticcontrolOption,SIGNAL(sig_btnOneKey()),acousticcontrol,SLOT(OneKeyClicked()));

    /****强声设备一键喊话功能:设备1******/
    connect(ui->btnBroadcast,SIGNAL(clicked()),acousticcontrolUdp,SLOT(btnBroadcastClicked()));
    connect(ui->btnBroadcast,SIGNAL(clicked()),this,SLOT(btnBroadcastClicked()));//同一个信号对应的第二个槽
    connect(ui->Slider_CapVolume,SIGNAL(valueChanged(int)),acousticcontrolUdp,SLOT(SliderCapVolumeChanged(int)));//同一个信号对应的第二个槽,udp采集音量
    connect(ui->btnBroadcast,SIGNAL(pressed()),acousticcontrol,SLOT(btnBroadcastPressed()));
    /****强声设备实时文件播放功能:设备1******/
    connect(acousticcontrolOption,SIGNAL(sig_getUploadFilePath(QString)),acousticcontrol,SLOT(hander_getUploadFilePath(QString)));
    connect(acousticcontrolOption,SIGNAL(sig_btnUploadFile()),acousticcontrol,SLOT(UploadFileClicked()));

    /****云台设备TCP按键连接与断开功能******/
    connect(gimbalOption,SIGNAL(sig_TcpConnect()),gimbal,SLOT(btnConnectClicked()));
    connect(gimbal,SIGNAL(sig_ConnectState(int,QString,QString,int)),
            this,SLOT(handle_ConnectState(int,QString,QString,int)));
    connect(gimbal,SIGNAL(sig_ConnectState(int,QString,QString,int)),
            gimbalOption,SLOT(handle_ConnectState(int,QString,QString,int)));

    /****云台设备一键归零功能******/
    connect(gimbalOption,SIGNAL(sig_btnOneClickZeroing()),gimbal,SLOT(btnOneClickZeroingClicked()));

    /****强声设备TCP按键连接与断开功能:设备1******/
    connect(acousticcontrolOption,SIGNAL(sig_btn_tcpconnect()),acousticcontrol,SLOT(btnConnectClicked()));

    /****强声设备TCP连接状态与ip显示:设备1******/
    connect(acousticcontrol,SIGNAL(sig_ConnectState(int,QString,QString,int)),
            acousticcontrolOption,SLOT(handle_ConnectState(int,QString,QString,int)));

    /****强声设备UDP连接状态与ip显示:设备1******/
    connect(acousticcontrolUdp,SIGNAL(sig_ConnectState(int,QString,QString,int)),
            acousticcontrolOption,SLOT(handle_ConnectState(int,QString,QString,int)));
    connect(acousticcontrolOption,SIGNAL(sig_IPSet(QString,QString)),acousticcontrolUdp,SLOT(handle_IPSet(QString,QString)));

    /*强光设备*/
    connect(ui->btn_switch_strongLight,SIGNAL(clicked()),stronglight,SLOT(btnSwitchOnOff()));
    connect(ui->btn_switch_flash,SIGNAL(clicked()),stronglight,SLOT(btnFlashOnOff()));
    connect(ui->btn_angle_min,SIGNAL(clicked()),stronglight,SLOT(btnAngleMin()));
    connect(ui->btn_angle_max,SIGNAL(clicked()),stronglight,SLOT(btnAngleMax()));
    connect(stronglight,SIGNAL(sig_ConnectState(int,QString,QString,int)),strongLightOption,SLOT(handle_ConnectState(int,QString,QString,int)));
    connect(strongLightOption,SIGNAL(sig_TcpConnect()),stronglight,SLOT(btnConnectClicked()));
}
void MainWindow::GimbalStart()
{
    thread_Gimbal->start();
    emit gimbal->startSignal();
}
void MainWindow::AcousticcontrolStart()
{
    thread_AcousticControl->start();
    emit acousticcontrol->startSignal();
}
void MainWindow::AcousticcontrolUDPStart()
{
    thread_acousticcontrolUdp->start();
    emit acousticcontrolUdp->startSignal();
}

void MainWindow::StrongLightStart()
{
    thread_StrongLight->start();
    emit stronglight->startSignal();
}
void MainWindow::UIControlsRun()
{
    lcdTimer->start();//启动定时器
    setvalue_speed_horizontal(1);//设定云台转速初始值
    setvalue_speed_vertical(1);
}
void MainWindow::setvalue_speed_horizontal(int val)
{
    ui->slider_speed_horizontal->setValue(val);
}
void MainWindow::setvalue_speed_vertical(int val)
{
    ui->slider_speed_horizontal->setValue(val);
}
int MainWindow::getvalue()
{
    return ui->slider_speed_horizontal->value();
}
void MainWindow::handle_AngleData(int type,int angle)
{
    switch (type) {
    case MESSAGE_GIMBAL_ANGLE_H:
        angle_horizontal = angle;
        // RoteHorizontal(angle_horizontal);
        break;
    case MESSAGE_GIMBAL_ANGLE_V:
        angle_vertical = angle;
        break;
    default:
        break;
    }
}
void MainWindow::onTimeOut()
{
    ui->lcdNumber_horizontal->display(angle_horizontal);
    ui->lcdNumber_vertical->display(angle_vertical);
    update();
}
/*****/
void MainWindow::RockerInit()
{
    //设置大圆圆心坐标
    SmallCir_xy.setX(BIG_CIRCLE_X);
    SmallCir_xy.setY(BIG_CIRCLE_Y);
    //设置小圆圆心位置，与大圆相同
    BigCir_xy=SmallCir_xy;
    //鼠标点击标志初始化
    MousePressFlag=false;
    directionOnOffFlag = 0x00;
    directionOnOffFlagbuffer = 0xFF;
    /****/
    RoteInit();
}
//绘图事件：绘制地图、摇杆中的大圆和小圆
void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event); 
    QPainter painter(this);//绘图画笔
    painter.setRenderHint(QPainter::Antialiasing, true);//抗锯齿
    painter.setRenderHints(QPainter::SmoothPixmapTransform);//消锯齿
    painter.setBackgroundMode(Qt::TransparentMode);
    //绘制摇杆中的大圆
    QPixmap bigCircle_Pixmap;
    bigCircle_Pixmap.load("://photo/big.png");
    painter.drawPixmap(SmallCir_xy.x()-BIG_CIRCLE_RADIUS,SmallCir_xy.y()-BIG_CIRCLE_RADIUS,\
            BIG_CIRCLE_RADIUS*2,BIG_CIRCLE_RADIUS*2,bigCircle_Pixmap);
    //绘制摇杆中的小圆
    QPixmap smallCircle_Pixmap;
    smallCircle_Pixmap.load("://photo/small.png");
    painter.drawPixmap(BigCir_xy.x()-SMALL_CIRCLE_RADIUS,BigCir_xy.y()-SMALL_CIRCLE_RADIUS,\
            SMALL_CIRCLE_RADIUS*2,SMALL_CIRCLE_RADIUS*2,smallCircle_Pixmap);

    //画背景小车
    QPixmap backgraundCar;
    QTransform matrix;
    matrix.rotate(270);
    backgraundCar.load("://photo/backgraundCar-removebg-preview.png");
    backgraundCar = backgraundCar.transformed(matrix,Qt::SmoothTransformation);
    painter.drawPixmap(IMAGE_PAINTER_1_RADIALGRAD_X - backgraundCar.width()/8,
                       IMAGE_PAINTER_1_RADIALGRAD_Y - backgraundCar.height()/16,
                       backgraundCar.width()/4,backgraundCar.height()/4,backgraundCar);
    //画扇形
    painter.resetTransform();//重新设置
    //抗锯齿
    painter.setRenderHint(QPainter::Antialiasing, true);
    //消锯齿
    painter.setRenderHints(QPainter::SmoothPixmapTransform);
    QRectF rectangle(IMAGE_PAINTER_1_RECTANGLE_X,IMAGE_PAINTER_1_RECTANGLE_Y,
                     IMAGE_PAINTER_1_RECTANGLE_WIDTH,IMAGE_PAINTER_1_RECTANGLE_HEIGHT);
    double angle =0;
    angle = 60 - angle_horizontal;
    if(angle < 0)
    {
        angle = 360 + angle;
    }
    int startAngle = (angle) * 16;
    int spanAngle = IMAGE_PAINTER_1_RECTANGLE_SPANANGLE * 16;

    QRadialGradient radialGrad(IMAGE_PAINTER_1_RADIALGRAD_X,IMAGE_PAINTER_1_RADIALGRAD_Y,
                               IMAGE_PAINTER_1_RADIALGRAD_RADIUS);
    radialGrad.setColorAt(0, Qt::red);
    radialGrad.setColorAt(0.2, Qt::yellow);
    radialGrad.setColorAt(0.4, Qt::green);
    radialGrad.setColorAt(0.6, Qt::cyan);
    radialGrad.setColorAt(0.8, Qt::blue);
    radialGrad.setColorAt(1.0, Qt::magenta);
    radialGrad.setSpread(QGradient::PadSpread);
    QBrush brush(radialGrad);
    painter.setBrush(brush);
    painter.drawPie(rectangle, startAngle, spanAngle);
    if((0 <= angle_horizontal)&&(angle_horizontal <= 180))
    {
        painter.drawText(rectangle,Qt::AlignRight,QString("水平:%1°").arg(QString::number(angle_horizontal,'f',2)));
    }
    else
    {
        ;
        painter.drawText(rectangle,Qt::AlignLeft,QString("水平:%1°").arg(QString::number(angle_horizontal,'f',2)));
    }
    painter.drawText(IMAGE_PAINTER_2_LINE_POINT2_X+10,IMAGE_PAINTER_2_LINE_POINT2_Y,
                     QString("%1°").arg(0));
    //画线
    painter.resetTransform();
    //抗锯齿
    painter.setRenderHint(QPainter::Antialiasing, true);
    //消锯齿
    painter.setRenderHints(QPainter::SmoothPixmapTransform);
    QPen pen(QColor(0,0,0));
    pen.setWidth(2);
    pen.setStyle(Qt::DotLine);
    painter.setPen(pen);
    painter.drawLine( QPoint(IMAGE_PAINTER_2_LINE_POINT1_X,IMAGE_PAINTER_2_LINE_POINT1_Y),
                      QPoint(IMAGE_PAINTER_2_LINE_POINT2_X,IMAGE_PAINTER_2_LINE_POINT2_Y));
}
void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    QPoint rocker_xy; //摇杆所在的实时坐标
    int x,y;
    rocker_xy=e->pos();
    if(MousePressFlag) //MousePressFlag为true，说明鼠标点击在了大圆内，才进行计算
    {
        //小圆圆心出了大圆则在大圆上90-25=65  65*65=4225
        if(pow((rocker_xy.x()-SmallCir_xy.x()),2)+pow((rocker_xy.y()-SmallCir_xy.y()),2)>8100)
        {
            x=int( 90*cos(atan2(abs(rocker_xy.y()-SmallCir_xy.y()),abs(rocker_xy.x()-SmallCir_xy.x()))) );
            y=int( 90*sin(atan2(abs(rocker_xy.y()-SmallCir_xy.y()),abs(rocker_xy.x()-SmallCir_xy.x()))) );
            //第一象限
            if(rocker_xy.x()>SmallCir_xy.x()&&rocker_xy.y()>SmallCir_xy.y())
            {
                BigCir_xy.setX(x+SmallCir_xy.x());
                BigCir_xy.setY(y+SmallCir_xy.y());
            }
            //第二象限
            else if(rocker_xy.x()<SmallCir_xy.x()&&rocker_xy.y()>SmallCir_xy.y())
            {
                BigCir_xy.setX(-x+SmallCir_xy.x());
                BigCir_xy.setY(y+SmallCir_xy.y());
                x=-x;
            }
            //第三象限
            else if(rocker_xy.x()<SmallCir_xy.x()&&rocker_xy.y()<SmallCir_xy.y())
            {
                BigCir_xy.setX(-x+SmallCir_xy.x());
                BigCir_xy.setY(-y+SmallCir_xy.y());
                x=-x;
                y=-y;
            }
            //第四象限
            else if(rocker_xy.x()>SmallCir_xy.x()&&rocker_xy.y()<SmallCir_xy.y())
            {
                BigCir_xy.setX(x+SmallCir_xy.x());
                BigCir_xy.setY(-y+SmallCir_xy.y());
                y=-y;
            }
            //处理（90，0），（0，90），（-90,0）,(0,-90)
            //第四象限与第一象限边界点
            else if((rocker_xy.x()>SmallCir_xy.x())&&(rocker_xy.y()==SmallCir_xy.y()))
            {
            }
            //第一象限与第二象限边界点
            else if((rocker_xy.x()==SmallCir_xy.x())&&(rocker_xy.y()>SmallCir_xy.y()))
            {
            }
            //第二象限与第三象限边界点
            else if((rocker_xy.x()<SmallCir_xy.x())&&(rocker_xy.y()==SmallCir_xy.y()))
            {
                x = -x;
            }
            //第三象限与第四象限边界点
            else if((rocker_xy.x()==SmallCir_xy.x())&&(rocker_xy.y()<SmallCir_xy.y()))
            {
                y = -y;
            }
        }
        else
        {
            BigCir_xy=rocker_xy;
            x=rocker_xy.x()-SmallCir_xy.x();
            y=rocker_xy.y()-SmallCir_xy.y();
        }
        //qDebug() <<x<<y;
        update();
        /******/
        //圆环内:900<=x的平方+y的平方<=8100
        if((900 <= (pow(x,2)+pow(y,2)))&&((pow(x,2)+pow(y,2)) <= 8100))
        {
            //上下左右方向区域划分
            if((((0 < x)&&(x <= BIG_CIRCLE_RADIUS))&&((0 <= y)&&(y <= x)))
                ||(((0 < x)&&(x < BIG_CIRCLE_RADIUS))&&(((-1) * x <= y)&&(y < 0))))
            {
                if(directionOnOffFlagbuffer != (directionOnOffFlag & 0x01))
                {
                    directionOnOffFlag &= ~(0x0F);
                    directionOnOffFlag |= 0x01;
                    directionOnOffFlagbuffer = directionOnOffFlag;
                    if(g_GimbalState == QAbstractSocket::ConnectedState)
                    {
                        emit gimbal->sendDataSignal(COMMAND_GIMBAL_TURN_RIGHT,PRESS_STATE_PRESSED);
                    }
                }
            }
            else if((((0 <= x)&&(x < BIG_CIRCLE_RADIUS))&&((x < y)&&(y <= BIG_CIRCLE_RADIUS)))
                     ||(((-BIG_CIRCLE_RADIUS < x)&&(x < 0))&&(((-1) * x < y)&&(y < BIG_CIRCLE_RADIUS))))
            {
                if(directionOnOffFlagbuffer != (directionOnOffFlag & 0x04))
                {
                    directionOnOffFlag &= ~(0x0F);
                    directionOnOffFlag |= 0x04;
                    directionOnOffFlagbuffer = directionOnOffFlag;
                    if(g_GimbalState == QAbstractSocket::ConnectedState)
                    {
                        emit gimbal->sendDataSignal(COMMAND_GIMBAL_TURN_DOWN,PRESS_STATE_PRESSED);
                    }
                }
            }
            else if((((-BIG_CIRCLE_RADIUS <= x)&&(x < 0))&&((0 <= y)&&(y <= (-1) * x)))
                     ||(((-BIG_CIRCLE_RADIUS < x)&&(x < 0))&&((x <= y)&&(y < 0))))
            {
                if(directionOnOffFlagbuffer != (directionOnOffFlag & 0x02))
                {
                    directionOnOffFlag &= ~(0x0F);
                    directionOnOffFlag |= 0x02;
                    directionOnOffFlagbuffer = directionOnOffFlag;
                    if(g_GimbalState == QAbstractSocket::ConnectedState)
                    {
                        emit gimbal->sendDataSignal(COMMAND_GIMBAL_TURN_LEFT,PRESS_STATE_PRESSED);
                    }
                }
            }
            else if((((-BIG_CIRCLE_RADIUS < x)&&(x <= 0))&&((-BIG_CIRCLE_RADIUS <= y)&&(y < x)))
                     ||(((0 < x)&&(x < BIG_CIRCLE_RADIUS))&&((-BIG_CIRCLE_RADIUS < y)&&(y < (-1)* x))))
            {
                if(directionOnOffFlagbuffer != (directionOnOffFlag & 0x08))
                {
                    directionOnOffFlag &= ~(0x0F);
                    directionOnOffFlag |= 0x08;
                    directionOnOffFlagbuffer = directionOnOffFlag;
                    if(g_GimbalState == QAbstractSocket::ConnectedState)
                    {
                        emit gimbal->sendDataSignal(COMMAND_GIMBAL_TURN_UP,PRESS_STATE_PRESSED);
                    }
                }
            }
        }
    }
    MapRemov_Old=rocker_xy;
}
//鼠标释放事件：释放鼠标，则MousePressFlag复位，且小圆圆心设置为初始值，更新绘图事件后，重新绘图使小圆（摇杆）回到原处
void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    Q_UNUSED(e);

    //释放鼠标，则MousePressFlag复位
    MousePressFlag=false;
    //小圆圆心设置为初始值,即大圆圆心值
    BigCir_xy.setX(SmallCir_xy.x());
    BigCir_xy.setY(SmallCir_xy.y());

    this->update(); //更新绘图事件后，重新绘图使小圆（摇杆）回到原处
    //qDebug() << "release";
    if(g_GimbalState == QAbstractSocket::ConnectedState)
    {
        emit gimbal->sendDataSignal(COMMAND_GIMBAL_TURN_STOP,PRESS_STATE_PRESSED);
    }

    directionOnOffFlagbuffer = 0XFF;
}

//鼠标按下事件：获取摇杆所在的实时坐标
void MainWindow::mousePressEvent(QMouseEvent *e)
{
    QPoint rocker_xy; //摇杆所在的实时坐标
    rocker_xy=e->pos(); //获取摇杆所在的实时坐标
    //qDebug() <<"摇杆坐标： " <<rocker_xy;
    //鼠标点击，在大圆内才设置MousePressFlag
    if(pow((rocker_xy.x()-SmallCir_xy.x()),2)+pow((rocker_xy.y()-SmallCir_xy.y()),2)<=8100) //判断摇杆是否在大圆内
    {
        MousePressFlag=true;
    }
    else
    {
        MapRemov_Old=rocker_xy;
    }
}
void MainWindow::RoteInit()
{
    QTransform matrix;
    //matrix.rotate(180);
    horizontalangle = 0.0;
    Image_horizontal = QImage("://photo/gimbal-small-2-removebg-preview.png");
    pixmap_horizontal = QPixmap::fromImage(Image_horizontal);
    fixpixmap_horizontal = pixmap_horizontal.scaled(Image_horizontal.size().width()/12,Image_horizontal.size().height()/12,
                                                    Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    ui->label_horizontal_pixmap->setGeometry(20,40,200,200);
    ui->label_horizontal_pixmap->setPixmap((fixpixmap_horizontal).transformed(matrix,Qt::SmoothTransformation));
    ui->label_horizontal_pixmap->setAlignment(Qt::AlignCenter);
    ui->label_horizontal_pixmap->lower();
    ui->label_horizontal_pixmap->raise();
}
/*****/
void MainWindow::RoteHorizontal(int data)
{
    QTransform matrix;
    double angle = (double)data;
    angle += 0;
    if(angle > 360)
    {
        angle = angle -360;
    }
    matrix.rotate(angle);
    ui->label_horizontal_pixmap->setPixmap((fixpixmap_horizontal).transformed(matrix,Qt::SmoothTransformation));
    ui->label_horizontal_pixmap->setAlignment(Qt::AlignCenter);
}
void MainWindow::handle_listWidgetAddItem(QString filename)
{
    ui->listWidget->addItem (filename);
}
void MainWindow::handle_listWidgetClear()
{
    ui->listWidget->clear();
}

void MainWindow::btnBroadcastClicked()
{
    static bool flag = true;
    if(flag)
    {
        flag = !flag;
        SetLED(ui->label_broadcast_led,2,15);
        SetCircularButton(ui->btnBroadcast,2,40);
    }
    else
    {
        flag = !flag;
        SetLED(ui->label_broadcast_led,0,15);
        SetCircularButton(ui->btnBroadcast,0,40);
    }
}
void MainWindow::handle_SongPrevious(QString CurrentPlayerIndex)
{
    ui->listWidget->setCurrentRow(CurrentPlayerIndex.toInt());
}
void MainWindow::handle_SongNext(QString CurrentPlayerIndex)
{
    ui->listWidget->setCurrentRow(CurrentPlayerIndex.toInt());
}

void MainWindow::SetLED(QLabel* label,int color,int size)
{
    label->setText("");

    QStringList LEDOption;
    LEDOption << QString("min-width: %1px;").arg(size);
    LEDOption << QString("min-height: %1px;").arg(size);
    LEDOption << QString("max-width: %1px;").arg(size);
    LEDOption << QString("max-height: %1px;").arg(size);
    LEDOption << QString("border-radius: %1px;").arg(size/2);//边框圆角
    QString background = "background-color:";
    switch (color) {
    case 0:
        // 灰色
        background += "#808080";
        break;
    case 1:
        // 红色
        background += "#FF0000";
        break;
    case 2:
        // 绿色
        background += "#00FF00";
        break;
    case 3:
        // 黄色
        background += "#FFFF00";
        break;
    default:
        break;
    }
    const QString SheetStyle =LEDOption[0]+LEDOption[1]+LEDOption[2]+LEDOption[3]+LEDOption[4]+background;
    label->setStyleSheet(SheetStyle);

}
void MainWindow::SetCircularButton(QPushButton *btn,int color,int size)
{
    btn->setText("");
    QStringList LEDOption;
    LEDOption << QString("min-width: %1px;").arg(size);
    LEDOption << QString("min-height: %1px;").arg(size);
    LEDOption << QString("max-width: %1px;").arg(size);
    LEDOption << QString("max-height: %1px;").arg(size);
    LEDOption << QString("border-radius: %1px;").arg(size/2);//边框圆角
    QString background = "background-color:";
    switch (color) {
    case 0:
        // 灰色
        background += "#808080";
        break;
    case 1:
        // 大红色
        background += "#FF0000";
        break;
    case 2:
        // 绿色 绿黄色
        background += "#00FF00";
        break;
    case 3:
        // 黄色
        background += "#FFFF00";
        break;
    default:
        break;
    }
    const QString SheetStyle =LEDOption[0]+LEDOption[1]+LEDOption[2]+LEDOption[3]+LEDOption[4]+background;
    btn->setStyleSheet(SheetStyle);
}

void MainWindow::on_GimbaOptionPage_clicked()
{
    if(gimbalOption->isHidden())
    {
       gimbalOption->show();
    }
    else
    {
       gimbalOption->hide();
    }
}
void MainWindow::on_pushButton_clicked()
{
    if(acousticcontrolOption->isHidden())
    {
       acousticcontrolOption->show();
    }
    else
    {
       acousticcontrolOption->hide();
    }
}
void MainWindow::on_pushButton_2_clicked()
{
    if(strongLightOption->isHidden())
    {
       strongLightOption->show();
    }
    else
    {
       strongLightOption->hide();
    }
}
void MainWindow::on_btn_switch_strongLight_clicked()
{
    static bool flag = true;
    if(flag)
    {
       flag = !flag;
       SetLED(ui->label_Dazzling_led,2,15);
       SetLED(ui->label_Spotlight_led,0,15);
    }
    else
    {
       flag = !flag;
       SetLED(ui->label_Dazzling_led,0,15);
       SetLED(ui->label_Spotlight_led,0,15);
    }

}
void MainWindow::on_btn_switch_flash_clicked()
{
    static bool flag = true;
    if(flag)
    {
       flag = !flag;
       SetLED(ui->label_Dazzling_led,0,15);
       SetLED(ui->label_Spotlight_led,2,15);
    }
    else
    {
       flag = !flag;
       SetLED(ui->label_Dazzling_led,2,15);
       SetLED(ui->label_Spotlight_led,0,15);
    }
}
void MainWindow::handle_ConnectState(int deviceName,QString IP,QString Port,int State)
{
    switch (deviceName) {
    case DEVICE_NAME_GIMBAL:
    {
       qDebug()<<"gimal"<<"ip:"<<IP<<"port:"<<Port;
       g_GimbalState = State;
    }
    break;
    }
}
