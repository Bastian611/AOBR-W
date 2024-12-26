/********************************************************************************
** Form generated from reading UI file 'QDaulLightCamera.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QDAULLIGHTCAMERA_H
#define UI_QDAULLIGHTCAMERA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QDaulLightCamera
{
public:

    void setupUi(QWidget *QDaulLightCamera)
    {
        if (QDaulLightCamera->objectName().isEmpty())
            QDaulLightCamera->setObjectName(QString::fromUtf8("QDaulLightCamera"));
        QDaulLightCamera->resize(550, 490);

        retranslateUi(QDaulLightCamera);

        QMetaObject::connectSlotsByName(QDaulLightCamera);
    } // setupUi

    void retranslateUi(QWidget *QDaulLightCamera)
    {
        QDaulLightCamera->setWindowTitle(QCoreApplication::translate("QDaulLightCamera", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QDaulLightCamera: public Ui_QDaulLightCamera {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QDAULLIGHTCAMERA_H
