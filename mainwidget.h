#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "MusicList.h"
#include <QWidget>
#include <QSystemTrayIcon>
#include <QMediaPlayer>
#include <QVBoxLayout>

#include <bits/stl_vector.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWidget;

}
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT
public:

    //构造方法
    MainWidget(QWidget *parent = nullptr);

    //类析构方法
    ~MainWidget();

    //播放器ui 初始化
    void init_ui();
    //背景重绘方法
    void paintEvent(QPaintEvent *);

    //播放器初始化配置
    void init_player();

    //播放器初始化
    void  init_musicList();
    //播放器初始化
    void namelist_refresh();
    void init();

    //数据库初始化
    void init_sqlite();


    //托盘菜单栏显示
    void init_hide();
    //创建托盘菜单栏
    void createActions();
    //创建托盘主菜单栏
    void createMenu();
    void init_actions();
    //删除数据库歌曲
    void init_delete();

    //设置歌曲进度条移动
    void updateDuration(qint64 duration);
    void updatePosition(qint64 position);
    void setPosition(int position);

    //添加到我喜欢的
    void  play_to_favor();
    void updateInfo();
    //背景设置
    void background_setting();
    void background_to_default();



    //当前播放器
    QMediaPlayer *player;
    //当前播放列表
    QMediaPlaylist *playlist;

    QMediaPlaylist *playlistquery;
    //多个歌单
    vector<MusicList> musiclist;
    //托盘菜单
    QMenu *mMenu;
    QAction *mShowMainAction;
    QAction *mExitAppAction;
    QSystemTrayIcon * mSysTrayIcon;
    //“当前播放”列表的右键菜单
    QMenu *menu_playlist;
    //换肤菜单
    QMenu * menu_changeSkin;
    void showv();

    // ui 点击事件
private slots:
    //点击托盘图标的事件
    void on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason);
    //显示托盘
    void on_showMainAction();
    //缩放托盘
    void on_exitAppAction();
    //关闭程序
    void on_btnQuit_clicked();
    //缩放程序
    void on_btnMin_clicked();

    void on_btnPlay_clicked();

    void on_btnAdd_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);

    void on_pushButton_6_clicked();

    void on_btnNext_clicked();

    void on_btnPre_clicked();

    void on_btnPlayMode_clicked();

    void on_pushButton_clicked();

    void on_btnVolume_clicked();

    void on_volumeSlider_valueChanged(int value);

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_11_clicked();

    void on_listWidget_2_doubleClicked(const QModelIndex &index);

    void on_listWidget_3_customContextMenuRequested(const QPoint &pos);

    void on_listWidget_customContextMenuRequested(const QPoint &pos);

    void on_pushButton_10_clicked();

    void on_favorMusicWidget_doubleClicked(const QModelIndex &index);

    void on_btnSkin_clicked();

    void on_pushButton_4_clicked();

    void  onTimerOut();

    void on_pushButton_15_clicked();

    void on_pushButton_14_clicked();

private:

    //窗口移动
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
    //是否进行托盘初始化
    bool falg=false;
    bool m_bDragging;
    //搜索页面刷新
    bool refresh=true;

    bool volume_flag=true;
    // 是否正在拖动
    QPoint m_poStartPosition;	// 拖动开始前的鼠标位置
    QPoint m_poFramePosition;	// 窗体的原始位置
    Ui::MainWidget *ui;
};
#endif // MAINWIDGET_H
