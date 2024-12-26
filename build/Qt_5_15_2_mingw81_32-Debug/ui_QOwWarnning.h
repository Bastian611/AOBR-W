/********************************************************************************
** Form generated from reading UI file 'QOwWarnning.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QOWWARNNING_H
#define UI_QOWWARNNING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QOwWarnning
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QLabel *lbWarnPoint;
    QLabel *lbWarnTip;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *vblWarnEvent;

    void setupUi(QWidget *QOwWarnning)
    {
        if (QOwWarnning->objectName().isEmpty())
            QOwWarnning->setObjectName(QString::fromUtf8("QOwWarnning"));
        QOwWarnning->resize(350, 700);
        horizontalLayoutWidget = new QWidget(QOwWarnning);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 331, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setPointSize(10);
        label_2->setFont(font);
        label_2->setFrameShape(QFrame::Box);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lbWarnPoint = new QLabel(horizontalLayoutWidget);
        lbWarnPoint->setObjectName(QString::fromUtf8("lbWarnPoint"));
        lbWarnPoint->setMinimumSize(QSize(20, 20));
        lbWarnPoint->setMaximumSize(QSize(25, 25));
        lbWarnPoint->setLayoutDirection(Qt::LeftToRight);
        lbWarnPoint->setPixmap(QPixmap(QString::fromUtf8(":/photo/green.png")));
        lbWarnPoint->setScaledContents(true);
        lbWarnPoint->setAlignment(Qt::AlignCenter);
        lbWarnPoint->setWordWrap(false);

        horizontalLayout->addWidget(lbWarnPoint);

        lbWarnTip = new QLabel(horizontalLayoutWidget);
        lbWarnTip->setObjectName(QString::fromUtf8("lbWarnTip"));

        horizontalLayout->addWidget(lbWarnTip);

        verticalLayoutWidget = new QWidget(QOwWarnning);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 50, 331, 631));
        vblWarnEvent = new QVBoxLayout(verticalLayoutWidget);
        vblWarnEvent->setObjectName(QString::fromUtf8("vblWarnEvent"));
        vblWarnEvent->setContentsMargins(0, 0, 0, 0);

        retranslateUi(QOwWarnning);

        QMetaObject::connectSlotsByName(QOwWarnning);
    } // setupUi

    void retranslateUi(QWidget *QOwWarnning)
    {
        QOwWarnning->setWindowTitle(QCoreApplication::translate("QOwWarnning", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("QOwWarnning", "  \345\221\250\347\225\214\346\243\200\346\265\213  ", nullptr));
        lbWarnPoint->setText(QString());
        lbWarnTip->setText(QCoreApplication::translate("QOwWarnning", "\346\243\200\346\265\213\345\210\260\345\274\202\345\270\270\347\216\260\350\261\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QOwWarnning: public Ui_QOwWarnning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QOWWARNNING_H
