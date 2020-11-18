#include "MusicList.h"
#include <QCoreApplication>
#include <QProgressDialog>
#include <QDesktopServices>
#include <QtSql>
#include <algorithm>
#include <QListWidget>
#include "MusicListWidget.h"
using namespace std;
MusicList::MusicList(const QList<QUrl> &urls, QString iname)
{

}
//初始化歌曲属性
void MusicList::read_fromSQL()
{
    QSqlQuery sql_query;
    QString select_sql = "select url, author, title, duration, albumTitle, audioBitRate from MusicInfo where name = ?";
    sql_query.prepare(select_sql);
    sql_query.addBindValue(name);
    if(sql_query.exec())
    {

        while(sql_query.next())
        {
            Music tempMusic;
            tempMusic.url=QUrl(sql_query.value(0).toString());
            tempMusic.author=sql_query.value(1).toString();
            tempMusic.title=sql_query.value(2).toString();
            tempMusic.duration=sql_query.value(3).toLongLong();
            tempMusic.albumTitle=sql_query.value(4).toString();
            tempMusic.audioBitRate=sql_query.value(5).toInt();
            music.push_back(tempMusic);
        }
    }
}

//将歌单添 加入到播放列表
void MusicList::addToPlayList(QMediaPlaylist *playlist)
{
    for(auto i=music.begin();i!=music.end();i++){
        playlist->addMedia(i->getUrl());
    }
}



//添加多个歌曲
void MusicList::addMusic(const QList<QUrl> &urls)
{
    //实测这里耗时较长，所以添加一个进度显示对话框
    QProgressDialog proDialog(u8"添加进度",u8"取消",0,urls.size());
    proDialog.setMinimumSize(350,150);
    proDialog.setWindowModality(Qt::WindowModal);
    proDialog.setWindowTitle("添加中...请稍后");
    proDialog.show();
    int x=0;
    foreach (QUrl i, urls) {
        x++;
        proDialog.setValue(x);
        //过滤Url的类型
        QMimeDatabase db;
        QMimeType mime = db.mimeTypeForFile(i.toLocalFile());
        if(mime.name()!="audio/mpeg"&&mime.name()!="audio/flac"){
            continue;
        }
        //剩下的符合类型
        music.push_back(Music(i));
        if(sql_flag){
            music[music.size()-1].insertSQL(name);
        }
        if(proDialog.wasCanceled()) break;
    }
}
//添加一首歌曲
void MusicList::addMusic(const Music &iMusic)
{
    music.push_back(iMusic);
    if(sql_flag){
        music[music.size()-1].insertSQL(name);
    }
}

void   MusicList::setMusic(const QList<QUrl> & urls){
    //清理之前的歌曲
    music.clear();
    foreach (QUrl i, urls) {
        //剩下的符合类型
        music.push_back(Music(i));

    }
}



//清除数据库所有歌曲
void MusicList::remove_SQL_all()
{
    QSqlQuery sql_query;
    QString delete_sql = "delete from MusicInfo";
    sql_query.prepare(delete_sql);
    sql_query.addBindValue(name);
    sql_query.exec();
}

//清空QListWidgetitem 控件
void MusicList::clear()
{
    music.clear();
    if(sql_flag){
        remove_SQL_all();
    }
}
//添加QListWidgetitem 控件
void MusicList::addToListWidget(MusicListWidget *listWidget)
{
    foreach(const Music &i,music){
        QListWidgetItem *item = new QListWidgetItem;
        item->setIcon(listWidget->getIcon());
        item->setText(i.getInfo());


//      QByteArray ba=i.getInfo().toLocal8Bit();
//              qDebug() << i.getInfo()+"=====";
        listWidget->addItem(item);
    }


}

Music MusicList::getMusic(int pos)
{
    return music[pos];
}
