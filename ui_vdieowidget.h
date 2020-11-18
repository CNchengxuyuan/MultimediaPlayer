/********************************************************************************
** Form generated from reading UI file 'vdieowidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VDIEOWIDGET_H
#define UI_VDIEOWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_vdieoWidget
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QSlider *positionSliderTwo;
    QLabel *positionLabel;

    void setupUi(QWidget *vdieoWidget)
    {
        if (vdieoWidget->objectName().isEmpty())
            vdieoWidget->setObjectName(QString::fromUtf8("vdieoWidget"));
        vdieoWidget->resize(1200, 800);
        vdieoWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(43, 43, 43);"));
        label = new QLabel(vdieoWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(-40, -10, 1321, 671));
        pushButton = new QPushButton(vdieoWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(900, 680, 141, 91));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/backgrond/image/background/tianjia.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(50, 50));
        pushButton_2 = new QPushButton(vdieoWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(1040, 680, 151, 91));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/backgrond/image/background/shanchu.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(50, 50));
        pushButton_3 = new QPushButton(vdieoWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(0, 680, 151, 91));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/backgrond/image/background/bofang.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon2);
        pushButton_3->setIconSize(QSize(50, 50));
        positionSliderTwo = new QSlider(vdieoWidget);
        positionSliderTwo->setObjectName(QString::fromUtf8("positionSliderTwo"));
        positionSliderTwo->setEnabled(true);
        positionSliderTwo->setGeometry(QRect(160, 710, 601, 51));
        QFont font;
        font.setPointSize(13);
        positionSliderTwo->setFont(font);
        positionSliderTwo->setCursor(QCursor(Qt::PointingHandCursor));
        positionSliderTwo->setStyleSheet(QString::fromUtf8("QSlider::add-page:Horizontal\n"
"{     \n"
"background-color: rgba(255, 255, 255,150);\n"
"height:4px;  \n"
"} \n"
"QSlider::sub-page:Horizontal   \n"
"{  \n"
"background-color: rgb(255, 255, 255);\n"
"height:4px;\n"
"}\n"
"QSlider::groove:Horizontal   \n"
"{ \n"
"background:transparent; \n"
"height:4px;\n"
"}  \n"
"QSlider::handle:Horizontal\n"
"{ \n"
"height:16px; \n"
"width:16px; \n"
"border-image:url(:/image/image/image/sliderHandle.png);\n"
"margin: -6 0px; \n"
"}\n"
"      \n"
""));
        positionSliderTwo->setSingleStep(10);
        positionSliderTwo->setOrientation(Qt::Horizontal);
        positionSliderTwo->setTickPosition(QSlider::NoTicks);
        positionLabel = new QLabel(vdieoWidget);
        positionLabel->setObjectName(QString::fromUtf8("positionLabel"));
        positionLabel->setEnabled(true);
        positionLabel->setGeometry(QRect(780, 710, 111, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Calibri"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        positionLabel->setFont(font1);
        positionLabel->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);"));
        positionLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(vdieoWidget);

        QMetaObject::connectSlotsByName(vdieoWidget);
    } // setupUi

    void retranslateUi(QWidget *vdieoWidget)
    {
        vdieoWidget->setWindowTitle(QCoreApplication::translate("vdieoWidget", "Form", nullptr));
        label->setText(QString());
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        positionLabel->setText(QCoreApplication::translate("vdieoWidget", "00:00/00:00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class vdieoWidget: public Ui_vdieoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VDIEOWIDGET_H
