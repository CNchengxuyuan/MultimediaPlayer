#ifndef MUSICLIST_H
#define MUSICLIST_H

#include "Music.h"
#include <QString>
#include <QMediaPlaylist>
#include <vector>
#include <bits/stl_vector.h>


class MusicListWidget;
//指定命名空间
using namespace std;
class MusicList
{
    //歌曲名
    QString name;
    //所储存的歌曲
    vector<Music> music;
    //控制是否要和数据库交互
    bool sql_flag=true;


public:
    MusicList(){}
    MusicList(const QList<QUrl> & urls,QString iname="");


    //初始化歌曲属性
     void read_fromSQL();
    //设定歌单名
    void setName(const QString & iname){name=iname;}
    //获取现存的歌单名
     QString getName(){ return name; }
    //将本歌单加入播放列表
    void addToPlayList(QMediaPlaylist *playlist);


    //设定数据库标志
    void setSQl(bool on){sql_flag=on;}
    //从url集合中添加歌曲
    void addMusic(const QList<QUrl> & urls);
    //添加一首歌曲
    void addMusic(const Music &iMusic);
 void  setMusic(const QList<QUrl> & urls);
    //数据库删除所有歌曲
    void remove_SQL_all();
    //清空所有的QListWidgetitem 控件
    void clear();
    //添加QListWidgetitem 控件
    void addToListWidget(MusicListWidget *listWidget);
Music getMusic(int pos);

    //友元
    friend class  MusicListWidget;
    friend class MainWidget;
};

#endif // MUSICLIST_H
