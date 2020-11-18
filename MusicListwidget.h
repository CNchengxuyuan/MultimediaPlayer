#ifndef MYLISTWIDGET_H
#define MYLISTWIDGET_H

#include<QListWidget>
#include<MusicList.h>

class MusicListWidget:public QListWidget
{
    Q_OBJECT
    //当前歌曲列表（存储的是歌曲信息）

    //当前展示列表项使用的图标
    QIcon icon=QIcon(":/image/image/image/music.png");

public:
    MusicList   musicList;
    MusicListWidget(QWidget *parent = Q_NULLPTR);
    //刷新显示（当musicList有所变化时，需要调用）
    void refresh();

    void setMusicList_playing(const MusicList& music);

    QIcon getIcon(){ return icon; }

    friend class MainWidget;

};

#endif // MYLISTWIDGET_H
