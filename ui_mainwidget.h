/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <MusicListWidget.h>
#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QLabel *label_2;
    QLabel *coverLabel;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QLabel *label_4;
    QPushButton *pushButton_10;
    QWidget *widget;
    QPushButton *pushButton_5;
    QPushButton *btnSkin;
    QPushButton *pushButton;
    QPushButton *btnQuit;
    QPushButton *btnMin;
    QPushButton *pushButton_12;
    QSlider *positionSlider;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnPre;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnPlay;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnNext;
    QPushButton *btnAdd;
    QPushButton *btnPlayMode;
    QPushButton *btnLyric;
    QPushButton *btnVolume;
    QStackedWidget *stackedWidget;
    QWidget *page_1;
    QWidget *page_2;
    MusicListWidget *listWidget;
    QWidget *page_3;
    QWidget *widget_2;
    QPushButton *pushButton_11;
    QTextEdit *textEdit_2;
    MusicListWidget *listWidget_2;
    QLabel *label_5;
    QWidget *page_4;
    MusicListWidget *favorMusicWidget;
    QWidget *page_5;
    QFrame *frame;
    QPushButton *pushButton_15;
    QPushButton *pushButton_14;
    QSlider *positionSliderTwo;
    QLabel *positionLabel;
    QSlider *volumeSlider;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->setWindowModality(Qt::NonModal);
        MainWidget->setEnabled(true);
        MainWidget->resize(1200, 800);
        MainWidget->setAutoFillBackground(false);
        MainWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(43, 43, 43);\n"
""));
        pushButton_2 = new QPushButton(MainWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(-110, 70, 311, 61));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton\n"
"\n"
"\n"
"{\n"
"	font: 12pt \"Arial\";\n"
"color: white;\n"
"border-radius:0px;\n"
"background: transparent;\n"
"background-repeat:no-repeat;\n"
"border:none;\n"
"background-position:center center;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: rgb(255, 255, 255,100);\n"
"}\n"
"QPushButton:pressed{\n"
"background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgb(255, 255, 255);\n"
"}\n"
""));
        pushButton_2->setIconSize(QSize(50, 30));
        pushButton_2->setAutoDefault(false);
        pushButton_2->setFlat(true);
        pushButton_4 = new QPushButton(MainWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(-140, 130, 341, 71));
        pushButton_4->setAutoFillBackground(false);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	font: 12pt \"Arial\";\n"
"color: white;\n"
"border-radius:0px;\n"
"background: transparent;\n"
"background-repeat:no-repeat;\n"
"border:none;\n"
"background-position:center center;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: rgb(255, 255, 255,100);\n"
"}\n"
"QPushButton:pressed{\n"
"background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgb(255, 255, 255);\n"
"}\n"
""));
        pushButton_4->setIconSize(QSize(50, 30));
        pushButton_4->setAutoDefault(false);
        pushButton_4->setFlat(true);
        pushButton_3 = new QPushButton(MainWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(-140, 180, 341, 61));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	font: 12pt \"Arial\";\n"
"color: white;\n"
"border-radius:0px;\n"
"background: transparent;\n"
"background-repeat:no-repeat;\n"
"border:none;\n"
"background-position:center center;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: rgb(255, 255, 255,100);\n"
"}\n"
"QPushButton:pressed{\n"
"background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgb(255, 255, 255);\n"
"}\n"
""));
        pushButton_3->setIconSize(QSize(50, 30));
        pushButton_3->setAutoDefault(false);
        pushButton_3->setFlat(true);
        label_2 = new QLabel(MainWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(-20, 260, 141, 31));
        label_2->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 8pt \"Agency FB\";\n"
"color: white"));
        coverLabel = new QLabel(MainWidget);
        coverLabel->setObjectName(QString::fromUtf8("coverLabel"));
        coverLabel->setGeometry(QRect(30, 600, 201, 201));
        coverLabel->setStyleSheet(QString::fromUtf8("background: transparent;"));
        coverLabel->setPixmap(QPixmap(QString::fromUtf8(":/image/image/image/non-music.png")));
        pushButton_6 = new QPushButton(MainWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(-20, 290, 221, 61));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	font: 12pt \"Arial\";\n"
"color: white;\n"
"border-radius:0px;\n"
"background: transparent;\n"
"background-repeat:no-repeat;\n"
"border:none;\n"
"background-position:center center;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: rgb(255, 255, 255,100);\n"
"}\n"
"QPushButton:pressed{\n"
"background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgb(255, 255, 255);\n"
"}\n"
""));
        pushButton_6->setIconSize(QSize(50, 30));
        pushButton_6->setAutoDefault(false);
        pushButton_6->setFlat(true);
        pushButton_7 = new QPushButton(MainWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(-20, 350, 221, 61));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	font: 12pt \"Arial\";\n"
"color: white;\n"
"border-radius:0px;\n"
"background: transparent;\n"
"background-repeat:no-repeat;\n"
"border:none;\n"
"background-position:center center;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: rgb(255, 255, 255,100);\n"
"}\n"
"QPushButton:pressed{\n"
"background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgb(255, 255, 255);\n"
"}\n"
""));
        pushButton_7->setIconSize(QSize(50, 30));
        pushButton_7->setAutoDefault(false);
        pushButton_7->setFlat(true);
        pushButton_8 = new QPushButton(MainWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(0, 410, 201, 61));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	font: 12pt \"Arial\";\n"
"color: white;\n"
"border-radius:0px;\n"
"background: transparent;\n"
"background-repeat:no-repeat;\n"
"border:none;\n"
"background-position:center center;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: rgb(255, 255, 255,100);\n"
"}\n"
"QPushButton:pressed{\n"
"background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgb(255, 255, 255);\n"
"}\n"
""));
        pushButton_8->setIconSize(QSize(50, 30));
        pushButton_8->setAutoDefault(false);
        pushButton_8->setFlat(true);
        pushButton_9 = new QPushButton(MainWidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(-10, 460, 201, 61));
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	font: 12pt \"Arial\";\n"
"color: white;\n"
"border-radius:0px;\n"
"background: transparent;\n"
"background-repeat:no-repeat;\n"
"border:none;\n"
"background-position:center center;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: rgb(255, 255, 255,100);\n"
"}\n"
"QPushButton:pressed{\n"
"background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgb(255, 255, 255);\n"
"}\n"
""));
        pushButton_9->setIconSize(QSize(50, 30));
        pushButton_9->setAutoDefault(false);
        pushButton_9->setFlat(true);
        label_4 = new QLabel(MainWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 510, 141, 31));
        label_4->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: white;\n"
"font: 8pt \"Agency FB\";"));
        pushButton_10 = new QPushButton(MainWidget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(0, 540, 191, 61));
        pushButton_10->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	font: 12pt \"Arial\";\n"
"color: white;\n"
"border-radius:0px;\n"
"background: transparent;\n"
"background-repeat:no-repeat;\n"
"border:none;\n"
"background-position:center center;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: rgb(255, 255, 255,100);\n"
"}\n"
"QPushButton:pressed{\n"
"background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgb(255, 255, 255);\n"
"}\n"
""));
        pushButton_10->setIconSize(QSize(50, 30));
        pushButton_10->setAutoDefault(false);
        pushButton_10->setFlat(true);
        widget = new QWidget(MainWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 1201, 71));
        widget->setStyleSheet(QString::fromUtf8(""));
        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(-10, 0, 211, 71));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton\n"
"\n"
"{\n"
"	font: 22pt \"Arial\";\n"
"color: white;\n"
"border-radius:0px;\n"
"background: transparent;\n"
"background-repeat:no-repeat;\n"
"border:none;\n"
"background-position:center center;\n"
"	background-image: url(:/backgrond/image/background/Snipaste_2020-10-29_15-15-09.png);\n"
"}\n"
""));
        pushButton_5->setIconSize(QSize(70, 100));
        pushButton_5->setAutoDefault(false);
        pushButton_5->setFlat(true);
        btnSkin = new QPushButton(widget);
        btnSkin->setObjectName(QString::fromUtf8("btnSkin"));
        btnSkin->setGeometry(QRect(1020, 20, 35, 35));
        btnSkin->setMinimumSize(QSize(35, 35));
        btnSkin->setCursor(QCursor(Qt::PointingHandCursor));
        btnSkin->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/image/skin.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSkin->setIcon(icon);
        btnSkin->setIconSize(QSize(30, 30));
        btnSkin->setFlat(true);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(960, 20, 35, 35));
        pushButton->setMinimumSize(QSize(35, 35));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("image/background/delete (2).png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(40, 40));
        pushButton->setFlat(true);
        btnQuit = new QPushButton(widget);
        btnQuit->setObjectName(QString::fromUtf8("btnQuit"));
        btnQuit->setGeometry(QRect(1140, -10, 61, 91));
        btnQuit->setMinimumSize(QSize(35, 35));
        btnQuit->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border-radius:0px;\n"
"background-image: url(:/image/image/image/quit.png);\n"
"background-repeat:no-repeat;\n"
"border:none;\n"
"background-position:center center;\n"
"\n"
"}\n"
"QPushButton:hover{\n"
"\n"
"background-color: rgba(230,0,0,0.5);\n"
"}\n"
"QPushButton:pressed{\n"
"background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"\n"
"}\n"
""));
        btnQuit->setIconSize(QSize(70, 70));
        btnMin = new QPushButton(widget);
        btnMin->setObjectName(QString::fromUtf8("btnMin"));
        btnMin->setGeometry(QRect(1090, 0, 51, 71));
        btnMin->setMinimumSize(QSize(35, 35));
        btnMin->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border-radius:0px;\n"
"background-image: url(:/image/image/image/min.png);\n"
"background-color: rgba(255, 255, 255,0);\n"
"background-repeat:no-repeat;\n"
"border:none;\n"
"background-position:center center;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: rgb(255, 255, 255,100);\n"
"}\n"
"QPushButton:pressed{\n"
"background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"}\n"
""));
        pushButton_12 = new QPushButton(widget);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setGeometry(QRect(830, 20, 111, 41));
        pushButton_12->setStyleSheet(QString::fromUtf8(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/backgrond/image/background/login.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_12->setIcon(icon2);
        pushButton_12->setIconSize(QSize(30, 30));
        pushButton_12->setFlat(true);
        positionSlider = new QSlider(MainWidget);
        positionSlider->setObjectName(QString::fromUtf8("positionSlider"));
        positionSlider->setEnabled(false);
        positionSlider->setGeometry(QRect(310, 730, 801, 21));
        QFont font;
        font.setPointSize(13);
        positionSlider->setFont(font);
        positionSlider->setCursor(QCursor(Qt::PointingHandCursor));
        positionSlider->setStyleSheet(QString::fromUtf8("QSlider::add-page:Horizontal\n"
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
        positionSlider->setSingleStep(10);
        positionSlider->setOrientation(Qt::Horizontal);
        positionSlider->setTickPosition(QSlider::NoTicks);
        layoutWidget = new QWidget(MainWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(310, 670, 311, 61));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnPre = new QPushButton(layoutWidget);
        btnPre->setObjectName(QString::fromUtf8("btnPre"));
        btnPre->setMinimumSize(QSize(0, 35));
        btnPre->setCursor(QCursor(Qt::PointingHandCursor));
        btnPre->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background-image: url(:/image/image/image/pre.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:none;\n"
"}\n"
"QPushButton:hover{\n"
"background-image: url(:/image/image/image-hover/pre-hover.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"}\n"
"QPushButton:pressed{\n"
"background-image: url(:/image/image/image/pre.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"}\n"
""));

        horizontalLayout->addWidget(btnPre);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnPlay = new QPushButton(layoutWidget);
        btnPlay->setObjectName(QString::fromUtf8("btnPlay"));
        btnPlay->setMinimumSize(QSize(0, 35));
        btnPlay->setCursor(QCursor(Qt::PointingHandCursor));
        btnPlay->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background-image: url(:/image/image/image/pase.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:0px;\n"
"}\n"
"\n"
""));
        btnPlay->setLocale(QLocale(QLocale::CentralMoroccoTamazight, QLocale::Morocco));
        btnPlay->setFlat(true);

        horizontalLayout->addWidget(btnPlay);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btnNext = new QPushButton(layoutWidget);
        btnNext->setObjectName(QString::fromUtf8("btnNext"));
        btnNext->setMinimumSize(QSize(0, 35));
        btnNext->setCursor(QCursor(Qt::PointingHandCursor));
        btnNext->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background-image: url(:/image/image/image/next.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:none;\n"
"}\n"
"QPushButton:hover{\n"
"background-image: url(:/image/image/image-hover/next-hover.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"}\n"
"QPushButton:pressed{\n"
"background-image: url(:/image/image/image/next.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"}\n"
""));

        horizontalLayout->addWidget(btnNext);

        btnAdd = new QPushButton(MainWidget);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setGeometry(QRect(940, 680, 41, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        btnAdd->setFont(font1);
        btnAdd->setCursor(QCursor(Qt::PointingHandCursor));
        btnAdd->setStyleSheet(QString::fromUtf8(""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image_hover/image/image-hover/add-hover.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAdd->setIcon(icon3);
        btnAdd->setIconSize(QSize(30, 30));
        btnAdd->setFlat(true);
        btnPlayMode = new QPushButton(MainWidget);
        btnPlayMode->setObjectName(QString::fromUtf8("btnPlayMode"));
        btnPlayMode->setGeometry(QRect(710, 680, 35, 41));
        btnPlayMode->setMinimumSize(QSize(35, 35));
        btnPlayMode->setCursor(QCursor(Qt::PointingHandCursor));
        btnPlayMode->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background-image: url(:/image/image/image/loop.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:none;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-image: url(:/image/image/image-hover/loop-hover.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-image: url(:/image/image/image/loop.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"}\n"
""));
        btnPlayMode->setFlat(false);
        btnLyric = new QPushButton(MainWidget);
        btnLyric->setObjectName(QString::fromUtf8("btnLyric"));
        btnLyric->setGeometry(QRect(830, 680, 35, 41));
        btnLyric->setMinimumSize(QSize(35, 35));
        btnLyric->setCursor(QCursor(Qt::PointingHandCursor));
        btnLyric->setStyleSheet(QString::fromUtf8(""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/image/image/lyric.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLyric->setIcon(icon4);
        btnLyric->setIconSize(QSize(30, 30));
        btnLyric->setFlat(true);
        btnVolume = new QPushButton(MainWidget);
        btnVolume->setObjectName(QString::fromUtf8("btnVolume"));
        btnVolume->setGeometry(QRect(1140, 720, 35, 35));
        btnVolume->setMinimumSize(QSize(35, 35));
        btnVolume->setCursor(QCursor(Qt::PointingHandCursor));
        btnVolume->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background-image: url(:/image/image/image/music-voice.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:none;\n"
"}\n"
"\n"
"\n"
"QPushButton:pressed{\n"
"background-image: url(:/image/image/image/music-voice.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"}\n"
""));
        stackedWidget = new QStackedWidget(MainWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(270, 80, 931, 471));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page_1 = new QWidget();
        page_1->setObjectName(QString::fromUtf8("page_1"));
        page_1->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgba(255, 255, 255, 50);\n"
"\n"
"background-image: url(:/backgrond/image/background/backgroundtwo.png);\n"
""));
        stackedWidget->addWidget(page_1);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        listWidget = new MusicListWidget(page_2);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(0, 0, 961, 471));
        listWidget->setStyleSheet(QString::fromUtf8(" border: none;\n"
"color:rgb(255, 255, 255);\n"
"background: transparent;  \n"
""));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        widget_2 = new QWidget(page_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(-10, 0, 941, 471));
        pushButton_11 = new QPushButton(widget_2);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(740, 80, 141, 51));
        pushButton_11->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/backgrond/image/background/query.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_11->setIcon(icon5);
        pushButton_11->setIconSize(QSize(30, 40));
        pushButton_11->setFlat(false);
        textEdit_2 = new QTextEdit(widget_2);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(40, 80, 681, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Agency FB"));
        font2.setPointSize(16);
        textEdit_2->setFont(font2);
        textEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        listWidget_2 = new MusicListWidget(widget_2);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setGeometry(QRect(40, 161, 881, 281));
        listWidget_2->setStyleSheet(QString::fromUtf8(" border: none;\n"
"color:rgb(255, 255, 255);\n"
"background: transparent;  \n"
""));
        label_5 = new QLabel(widget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(270, 0, 261, 81));
        label_5->setStyleSheet(QString::fromUtf8("background-image: url(:/backgrond/image/background/Snipaste_2020-11-09_19-54-01.png);\n"
"\n"
""));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        favorMusicWidget = new MusicListWidget(page_4);
        favorMusicWidget->setObjectName(QString::fromUtf8("favorMusicWidget"));
        favorMusicWidget->setGeometry(QRect(0, 0, 911, 461));
        favorMusicWidget->setStyleSheet(QString::fromUtf8(" border: none;\n"
"color:rgb(255, 255, 255);\n"
"background: transparent;  \n"
""));
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        frame = new QFrame(page_5);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(20, 0, 911, 401));
        frame->setStyleSheet(QString::fromUtf8("background-image: url(:/backgrond/image/background/classic-camera_ZISHVEKOTJ.webp);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_15 = new QPushButton(page_5);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        pushButton_15->setGeometry(QRect(830, 420, 91, 51));
        pushButton_15->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:0px;\n"
"}\n"
"\n"
""));
        pushButton_15->setIcon(icon3);
        pushButton_15->setIconSize(QSize(50, 50));
        pushButton_14 = new QPushButton(page_5);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        pushButton_14->setGeometry(QRect(40, 420, 71, 51));
        pushButton_14->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background-image: url(:/image/image/image/pase.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:0px;\n"
"}\n"
"\n"
""));
        pushButton_14->setIconSize(QSize(50, 50));
        pushButton_14->setFlat(true);
        positionSliderTwo = new QSlider(page_5);
        positionSliderTwo->setObjectName(QString::fromUtf8("positionSliderTwo"));
        positionSliderTwo->setEnabled(true);
        positionSliderTwo->setGeometry(QRect(140, 420, 671, 51));
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
        stackedWidget->addWidget(page_5);
        positionLabel = new QLabel(MainWidget);
        positionLabel->setObjectName(QString::fromUtf8("positionLabel"));
        positionLabel->setEnabled(false);
        positionLabel->setGeometry(QRect(1000, 690, 141, 21));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Calibri"));
        font3.setPointSize(11);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        positionLabel->setFont(font3);
        positionLabel->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);"));
        positionLabel->setAlignment(Qt::AlignCenter);
        volumeSlider = new QSlider(MainWidget);
        volumeSlider->setObjectName(QString::fromUtf8("volumeSlider"));
        volumeSlider->setGeometry(QRect(1140, 550, 35, 170));
        volumeSlider->setMinimumSize(QSize(35, 170));
        volumeSlider->setStyleSheet(QString::fromUtf8(" QSlider \n"
"    {  \n"
"background: transparent;  \n"
"        min-width:5px; \n"
"        max-width:5px;\n"
"        border:15px solid rgba(255,255,255,0.2); \n"
"    }\n"
"     QSlider::add-page:vertical\n"
"     {      \n"
"	background-color: rgb(255, 255, 255);\n"
"        width:4px;\n"
"     }\n"
"     QSlider::sub-page:vertical  \n"
"    {\n"
"        background-color: rgba(255,255,255,0.5); \n"
"        width:4px;\n"
"     }\n"
"    QSlider::groove:vertical \n"
"    {\n"
"        background:transparent;\n"
"        width:6px;\n"
"    }\n"
"    QSlider::handle:vertical \n"
"    {\n"
"         height: 13px;\n"
"        width:13px;\n"
" \n"
" margin: -0 -4px; \n"
"	border-image: url(:/backgrond/image/background/volumeHandle-2.png);\n"
"     }"));
        volumeSlider->setMaximum(100);
        volumeSlider->setValue(100);
        volumeSlider->setOrientation(Qt::Vertical);

        retranslateUi(MainWidget);

        pushButton_5->setDefault(false);
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        pushButton_2->setText(QCoreApplication::translate("MainWidget", "\345\217\221\347\216\260\351\237\263\344\271\220", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWidget", "\350\247\206\351\242\221", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWidget", "\346\234\213\345\217\213", nullptr));
        label_2->setText(QCoreApplication::translate("MainWidget", "       \346\210\221\347\232\204\351\237\263\344\271\220", nullptr));
        coverLabel->setText(QString());
        pushButton_6->setText(QCoreApplication::translate("MainWidget", "\346\234\254\345\234\260\351\237\263\344\271\220", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWidget", "\344\270\213\350\275\275\347\256\241\347\220\206", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWidget", "\346\210\221\347\232\204\351\237\263\344\271\220\344\272\221\347\233\230", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWidget", "\346\210\221\347\232\204\346\224\266\350\227\217", nullptr));
        label_4->setText(QCoreApplication::translate("MainWidget", "\345\210\233\345\273\272\346\255\214\345\215\225", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWidget", "\346\210\221\345\226\234\346\254\242\347\232\204\351\237\263\344\271\220", nullptr));
        pushButton_5->setText(QString());
#if QT_CONFIG(tooltip)
        btnSkin->setToolTip(QCoreApplication::translate("MainWidget", "\346\233\264\346\215\242\350\203\214\346\231\257", nullptr));
#endif // QT_CONFIG(tooltip)
        btnSkin->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton->setToolTip(QCoreApplication::translate("MainWidget", "\345\205\263\344\272\216", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton->setText(QString());
#if QT_CONFIG(tooltip)
        btnQuit->setToolTip(QCoreApplication::translate("MainWidget", "\345\205\263\351\227\255", nullptr));
#endif // QT_CONFIG(tooltip)
        btnQuit->setText(QString());
#if QT_CONFIG(tooltip)
        btnMin->setToolTip(QCoreApplication::translate("MainWidget", "\346\234\200\345\260\217\345\214\226", nullptr));
#endif // QT_CONFIG(tooltip)
        btnMin->setText(QString());
        pushButton_12->setText(QCoreApplication::translate("MainWidget", "\347\202\271\345\207\273\347\231\273\345\275\225", nullptr));
#if QT_CONFIG(tooltip)
        btnPre->setToolTip(QCoreApplication::translate("MainWidget", "\344\270\212\344\270\200\351\246\226", nullptr));
#endif // QT_CONFIG(tooltip)
        btnPre->setText(QString());
#if QT_CONFIG(shortcut)
        btnPre->setShortcut(QCoreApplication::translate("MainWidget", "Alt+Left", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        btnPlay->setToolTip(QCoreApplication::translate("MainWidget", "\346\222\255\346\224\276/\346\232\202\345\201\234", nullptr));
#endif // QT_CONFIG(tooltip)
        btnPlay->setText(QString());
#if QT_CONFIG(shortcut)
        btnPlay->setShortcut(QCoreApplication::translate("MainWidget", "Space", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        btnNext->setToolTip(QCoreApplication::translate("MainWidget", "\344\270\213\344\270\200\351\246\226", nullptr));
#endif // QT_CONFIG(tooltip)
        btnNext->setText(QString());
#if QT_CONFIG(shortcut)
        btnNext->setShortcut(QCoreApplication::translate("MainWidget", "Alt+Right", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        btnAdd->setToolTip(QCoreApplication::translate("MainWidget", "\346\267\273\345\212\240\346\234\254\345\234\260\351\237\263\344\271\220", nullptr));
#endif // QT_CONFIG(tooltip)
        btnAdd->setText(QString());
#if QT_CONFIG(shortcut)
        btnAdd->setShortcut(QCoreApplication::translate("MainWidget", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        btnPlayMode->setToolTip(QCoreApplication::translate("MainWidget", "\345\276\252\347\216\257\346\222\255\346\224\276", nullptr));
#endif // QT_CONFIG(tooltip)
        btnPlayMode->setText(QString());
#if QT_CONFIG(tooltip)
        btnLyric->setToolTip(QCoreApplication::translate("MainWidget", "\350\277\233\345\205\245\346\255\214\350\257\215\347\225\214\351\235\242", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLyric->setText(QString());
#if QT_CONFIG(tooltip)
        btnVolume->setToolTip(QCoreApplication::translate("MainWidget", "\351\237\263\351\207\217\346\216\247\345\210\266", nullptr));
#endif // QT_CONFIG(tooltip)
        btnVolume->setText(QString());
        pushButton_11->setText(QString());
        label_5->setText(QString());
        pushButton_15->setText(QString());
        pushButton_14->setText(QString());
        positionLabel->setText(QCoreApplication::translate("MainWidget", "00:00/00:00", nullptr));
        (void)MainWidget;
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
