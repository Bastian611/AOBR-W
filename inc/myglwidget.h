#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLTexture>
#include <QOpenGLShaderProgram>
#include <QTimer>

QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram)
QT_FORWARD_DECLARE_CLASS(QOpenGLTexture)

class MyGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit MyGLWidget(QWidget *parent = nullptr);
    ~MyGLWidget();

protected:
    void initializeGL() override;
    void paintGL() override;

public slots:
    void showYuv(uchar *buf, uint width, uint height);

private:
    QOpenGLShaderProgram *program;
    QOpenGLBuffer m_vbo;
    GLuint m_textureUniformY, m_textureUniformU, m_textureUniformV; // opengl中y、u、v分量位置
    QOpenGLTexture *m_textureY = nullptr, *m_textureU = nullptr, *m_textureV = nullptr;
    GLuint m_idY, m_idU, m_idV;
    uint m_videoWidth, m_videoHeight;
    uchar *yuvPtr = nullptr;
};

#endif // MYGLWIDGET_H
