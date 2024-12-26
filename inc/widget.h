#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QObject>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "myglwidget.h"
#include "rtsp.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void initUI();
    void initConnect();

private:
    MyGLWidget *m_glWidget = nullptr;
    Rtsp *m_rtspThread = nullptr;
    QLineEdit *m_urlEdit = nullptr;
    QPushButton *m_startBtn = nullptr;
    QPushButton *m_stopBtn = nullptr;
};
#endif // WIDGET_H
