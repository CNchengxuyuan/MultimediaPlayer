#include "MusicListwidget.h"

MusicListWidget::MusicListWidget(QWidget *parent) : QListWidget(parent)
{
    printf("nihap");
}


void MusicListWidget::refresh()
{
    clear();//先清空
    musicList.addToListWidget(this);
}

void MusicListWidget::setMusicList_playing(const MusicList &music)
{
    musicList=music;
    musicList.setSQl(false);
    refresh();
}
