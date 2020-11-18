#ifndef MUSIC_H
#define MUSIC_H
#include <QString>
#include <QUrl>


class Music{
public:

    //歌曲资源地址
    QUrl url;
    //歌手
    QString author;
    //歌曲名
    QString title;
    //时长
    qint64 duration;
    //唱片集
    QString albumTitle;
    //比特率
    int audioBitRate;

    //公共的构造函数
    Music(){}
    Music(QUrl iurl);
    //根据歌曲url 获取 歌曲信息 刷新信息
    void refreshInfo();
    //返回歌曲Url
    QUrl getUrl() const {return url;}

    //返回歌曲信息
    QString getInfo() const;

    //存入数据库
    void insertSQL(const QString & name);

    //友元类
        friend class MusicList;


} ;







#endif // MUSIC_H
