#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QBitmap>
#include <QCloseEvent>
#include <QFileDialog>
#include <QMenu>
#include <QMessageBox>
#include <QPainter>
#include <QSqlQuery>
#include <QStandardPaths>
#include <QStyleOption>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QSqlRecord>
#include <QSettings>
#include <QVideoWidget>
#include <QVBoxLayout>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QMediaPlayer>
#include <QTimer>


//视频播放器
QMediaPlayer* videoplayer;

//播放器控件
QVideoWidget* widget;

QVBoxLayout* layout_video;//布局

QTimer *timer;

int maxValue=1000;

bool if_reload=false;

//构造函数
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    //ui 界面初始化
    init_ui();
    //播放器初始化
    init_player();
    //数据库初始化
    init_sqlite();
    //右键菜单
    init_actions();
    //歌单初始化
    init_musicList();
    //播放器托盘化
    init_hide();

}

//析构函数
MainWidget::~MainWidget()
{
    delete ui;
}

//初始化ui
void  MainWidget::init_ui(){

    setWindowFlags(Qt::FramelessWindowHint);

    //    //窗口设置圆角后，会出现留白，需要添加以下代码  不要设置半透明背景 是（视频 只有声音 没有视频  窗口半透明化了）
    //    setAttribute(Qt::WA_TranslucentBackground, true); ！！！！！！！！！！！！！！

    //    //设置关于窗体为圆角
    QBitmap bmp(this->size());

    bmp.fill();

    QPainter p(&bmp);

    p.setPen(Qt::NoPen);

    p.setBrush(Qt::black);

    p.drawRoundedRect(bmp.rect(),20,20);

    setMask(bmp);

    //设置 任务栏图标点击缩放 再点击启动
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    ui->volumeSlider->hide();
    ui->stackedWidget->setCurrentIndex(0);
}

//重新绘制主窗口
void MainWidget::paintEvent(QPaintEvent * event){



    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}


void MainWidget::init_player(){
    //    player=new QMediaPlayer();
    //播放器初始化

    player= new QMediaPlayer(this);
    playlistquery= new QMediaPlaylist;
    playlist=new QMediaPlaylist;
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    playlistquery->setPlaybackMode(QMediaPlaylist::Loop);


    //信号和槽  对歌曲播放有问题，暂时放弃此方法 使进度条随歌曲播放移动！！！！！！！！
    connect(ui->positionSlider, &QAbstractSlider::valueChanged, this, &MainWidget::setPosition);
    //播放器进度条移动  根据 音乐的position变化而移动进度条
    connect(player, &QMediaPlayer::positionChanged, this, &MainWidget::updatePosition);
    //时间跟随 歌曲的时间 一起变化
    connect(player, &QMediaPlayer::durationChanged, this, &MainWidget::updateDuration);
    connect(player, &QMediaPlayer::metaDataAvailableChanged, this, &MainWidget::updateInfo);
}

//播放器歌单初始化
void MainWidget:: init_musicList(){
    //localMusic 本地音乐 索应出 提前设置 数据库name字段的 名字
    ui->listWidget->musicList.setName("LocalMusic");
    ui->listWidget->musicList.read_fromSQL();
    ui->listWidget->refresh();

    //FavorMusic 喜欢的音乐索引  提前设置 数据库name字段的 名字
    ui->favorMusicWidget->musicList.setName("FavorMusic");
    ui->favorMusicWidget->musicList.read_fromSQL();
    ui->favorMusicWidget->refresh();

    QSqlQuery sql_query;
    QString select_sql="select name from MusicLists";
    sql_query.prepare(select_sql);
    if(sql_query.exec())
    {
        while (sql_query.next()) {
            QString musicListName=sql_query.value(0).toString();

            MusicList tempList;
            tempList.setName(musicListName);
            tempList.read_fromSQL();
            musiclist.push_back(tempList);
        }

    }
    //    namelist_refresh();

}
//暂时没用
void MainWidget::namelist_refresh()
{
    //先清空
    QSqlQuery sql_query;
    QString delete_sql="delete from MusicLists";
    sql_query.prepare(delete_sql);
    sql_query.exec();
    for(size_t i=0;i<musiclist.size();i++){
        QSqlQuery sql_query2;

        QString insert_sql="insert into MusicLists values (?)";
        sql_query2.prepare(insert_sql);
        sql_query2.addBindValue(musiclist[i].getName());
        sql_query2.exec();
    }

    //展示刷新
    ui->listWidget->clear();
    for(size_t i=0;i<musiclist.size();i++){
        QListWidgetItem *item=new QListWidgetItem;
        item->setIcon(QIcon(":/image/image/image/music_list.png"));
        item->setText(musiclist[i].getName());
        ui->listWidget->addItem(item);
    }
    //添加按钮
    ui->listWidget->refresh();

}


//播放器初始化
void MainWidget:: init(){
    ui->listWidget->musicList.setName("LocalMusic");
    ui->listWidget->musicList.read_fromSQL();
    ui->listWidget->refresh();
}

//数据据初始化
void MainWidget::init_sqlite()
{
    QSqlDatabase database;
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        database = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("Music.db");
        database.setUserName("NJUTang");
        database.setPassword("123456");
        if (!database.open())
        {
            //            QMessageBox::critical(this,"无法打开数据库文件：Music.db",database.lastError().databaseText());
            exit(-1);
        }
    }
    //检查两个表是否存在，不存在则创建不存在的表
    QSqlQuery query;
    query.exec(QString("select count(*) from sqlite_master where type='table' and name='%1'").arg("MusicInfo"));
    if(query.next()){
        if(query.value(0).toInt()==0){
            QSqlQuery sql_query;
            //QString create_sql = "create table MusicInfo (id int primary key, name varchar(30), url varchar(200), author varchar(50), title varchar(50), duration bigint, albumTitle varchar(50), audioBitRate int)";
            QString create_sql = "create table MusicInfo (name varchar(30), url varchar(200), author varchar(50), title varchar(50), duration bigint, albumTitle varchar(50), audioBitRate int)";
            sql_query.prepare(create_sql);
            sql_query.exec();
        }
    }
    QSqlQuery query2;
    query2.exec(QString("select count(*) from sqlite_master where type='table' and name='%1'").arg("MusicLists"));
    if(query2.next()){
        if(query2.value(0).toInt()==0){
            QSqlQuery sql_query;
            QString create_sql = "create table MusicLists (name varchar(30))";
            sql_query.prepare(create_sql);
            sql_query.exec();
        }
    }
}

void  MainWidget::init_hide(){
    mSysTrayIcon = new QSystemTrayIcon(this);
    //新建托盘要显示的icon
    QIcon icon = QIcon(":/backgrond/imagecloud.ico");
    //将icon设到QSystemTrayIcon对象中
    mSysTrayIcon->setIcon(icon);
    //当鼠标移动到托盘上的图标时，会显示此处设置的内容
    mSysTrayIcon->setToolTip(QObject::trUtf8("网易云音乐"));

    //给QSystemTrayIcon添加槽函数
    connect(mSysTrayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason)));

    //建立托盘操作的菜单
    createActions();
    createMenu();
    //在系统托盘显示此对象
    mSysTrayIcon->show();
}

//创建托盘程序  小标的menu 界面
void  MainWidget::createActions()
{
    mShowMainAction = new QAction(QObject::trUtf8("显示主界面"),this);
    connect(mShowMainAction,SIGNAL(triggered()),this,SLOT(on_showMainAction()));

    mExitAppAction = new QAction(QObject::trUtf8("退出"),this);
    connect(mExitAppAction,SIGNAL(triggered()),this,SLOT(on_exitAppAction()));

}

//创建主界面
void  MainWidget::createMenu()
{
    mMenu = new QMenu(this);
    mMenu->setStyleSheet("background-color:white");
    mMenu->addAction(mShowMainAction);
    mMenu->addSeparator();
    mMenu->move(100,100);
    mMenu->addAction(mExitAppAction);

    mSysTrayIcon->setContextMenu(mMenu);
}

void MainWidget::init_actions(){
    //“当前播放”列表右键菜单初始化
    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    QAction *action_playlist_delete=new QAction(QIcon(":/image/image/image/remove.png"),u8"移除");
    //    connect(action_playlist_delete,&QAction::triggered,this,&MainWidget::playlist_removeMusic);
    QAction *action_playlist_showfile=new QAction(QIcon(":/image/image/image/music-dir.png"),u8"打开所在文件夹");
    //    connect(action_playlist_showfile,&QAction::triggered,ui->playListWidget,&MusicListWidget::showInExplorer);
    QAction *action_playlist_detail=new QAction(QIcon(":/image/image/image/detail.png"),u8"歌曲详情");
    //    connect(action_playlist_detail,&QAction::triggered,ui->playListWidget,&MusicListWidget::detail);
    QAction *action_play_to_favor=new QAction(QIcon(":/image/image/image/To-like.png"),u8"添加到我喜欢");
    connect(action_play_to_favor,&QAction::triggered,this,&MainWidget::play_to_favor);


    menu_playlist=new QMenu(this);
    menu_playlist->setStyleSheet("background:rgba(255, 255, 255);");
    menu_playlist->addAction(action_playlist_delete);
    menu_playlist->addAction(action_playlist_showfile);
    menu_playlist->addAction(action_playlist_detail);
    menu_playlist->addAction(action_play_to_favor);



    //“换肤”的菜单项
    QAction *action_backgroud_to_default = new QAction(QIcon(":/image/image/image/default.png"),u8"更换到默认背景");
    connect(action_backgroud_to_default,&QAction::triggered,this,&MainWidget::background_to_default);
    QAction *action_backgroud_setting=new QAction(QIcon(":/image/image/image/setting.png"),u8"自定义背景");
    connect(action_backgroud_setting,&QAction::triggered,this,&MainWidget::background_setting);
    menu_changeSkin=new QMenu(this);
    menu_changeSkin->addAction(action_backgroud_to_default);
    menu_changeSkin->addAction(action_backgroud_setting);
}

void MainWidget::background_to_default()
{
    ui->page_1->show();
    ui->label_5->show();
    ui->pushButton_5->show();
    ui->pushButton_5->isFlat();
    //    QString fileName=":/image/image/background/default.jpg";
    QSettings mysettings("./QTmusic.ini",QSettings::IniFormat);
    mysettings.setIniCodec("UTF8");
    //    mysettings.setValue("background/image-url",fileName);
    setStyleSheet(QString("QWidget#MainWidget{"
                          "background-color: rgb(43, 43, 43);}"
                          ));
}
void MainWidget::background_setting()
{
    //从默认图片位置打开文件选择框
    QString fileName=QFileDialog::getOpenFileName(this,("选择自定义背景图片"),QStandardPaths::standardLocations(QStandardPaths::PicturesLocation).first(),u8"图片文件(*jpg *png)");
    ui->page_1->hide();
    ui->label_5->hide();
    ui->pushButton_5->hide();
    if(!fileName.isEmpty())
    {
        QImage testImage(fileName);
        if(!testImage.isNull()){
            QSettings mysettings("./QTmusic.ini",QSettings::IniFormat);
            mysettings.setIniCodec("UTF8");
            mysettings.setValue("background/image-url",fileName);
            setStyleSheet(QString("QWidget#MainWidget{"
                                  "border-radius:10px;"
                                  "border-image: url(%1);}").arg(fileName));
        }
    }
}


void MainWidget::updateInfo()
{
    if (player->isMetaDataAvailable()) {

        //封面图片（应获取"ThumbnailImage" From: https://www.zhihu.com/question/36859497）
        QImage picImage= player->metaData(QStringLiteral("ThumbnailImage")).value<QImage>();
        if(picImage.isNull()) picImage=QImage(":/image/image/image/non-music.png");
        ui->coverLabel->setPixmap(QPixmap::fromImage(picImage));
        ui->coverLabel->setScaledContents(true);

    }
}
void MainWidget::play_to_favor()
{
    int pos=ui->listWidget->currentRow();
    ui->favorMusicWidget->musicList.addMusic(ui->listWidget->musicList.getMusic(pos));
    ui->favorMusicWidget->refresh();
    ui->stackedWidget->setCurrentIndex(3);
}




//创建方法的新方式
QString formatTime(qint64 timeMilliSeconds)
{
    qint64 seconds = timeMilliSeconds / 1000;
    const qint64 minutes = seconds / 60;
    seconds -= minutes * 60;
    return QStringLiteral("%1:%2")
            .arg(minutes, 2, 10, QLatin1Char('0'))
            .arg(seconds, 2, 10, QLatin1Char('0'));
}

//更新进度属性设置
void MainWidget::updateDuration(qint64 duration)
{
    //设置Qslider 范围 0 - 歌曲大小
    ui->positionSlider->setRange(0, static_cast<int>(duration));
    //设置进度条的进行条件是歌曲的时间大于0
    ui->positionSlider->setEnabled(static_cast<int>(duration) > 0);

    ui->positionSlider->setPageStep(static_cast<int>(duration) / 10);
}


//更新进度条
void MainWidget::updatePosition(qint64 position)
{
    //    ui->positionSlider->setMaximum(player->duration());
    ui->positionSlider->setValue(static_cast<int>(position));
    ui->positionLabel->setText(formatTime(position)+"/"+formatTime(player->duration()));

}

//进度条设置
void MainWidget::setPosition(int position)
{
    // avoid seeking when the slider value change is triggered from updatePosition()
    //QAbs  返回对应参数值的绝对值
    if (qAbs(player->position() - position) > 99)
        player->setPosition(position);
}








//关闭按钮
void MainWidget::on_btnQuit_clicked()
{
    //隐藏程序主窗口
    this->hide();
}

//缩放按钮
void MainWidget::on_btnMin_clicked()
{

    this->hide();
    //      showMinimized();
}




void MainWidget::on_showMainAction()
{
    this->show();
}

void MainWidget::on_exitAppAction()
{
    exit(0);
}
void MainWidget::on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason){
    case QSystemTrayIcon::Trigger:
        //单击托盘图标
        break;
    case QSystemTrayIcon::DoubleClick:
        //双击托盘图标
        //双击后显示主程序窗口
        //        this->show();
        //this->move(350,120);
        //        this->showMaximized();
        this->show();

        break;
    default:
        break;
    }
}

//窗口可拖动
void MainWidget::mousePressEvent(QMouseEvent* event)
{
    //实现点击界面中某点，音量条隐藏
    int x=event->pos().x();
    int y=event->pos().y();
    int x_widget=ui->volumeSlider->geometry().x(); //注：这里“wiget”的名字是要从UI文件编译后生成的ui_xxx.h文件中得知（在UI布局中看不到）
    int y_widget=ui->volumeSlider->geometry().y();
    int w=ui->volumeSlider->geometry().width();
    int h=ui->volumeSlider->geometry().height();
    if(!(x>=x_widget&&x<=x_widget+w && y>=y_widget&&y<=y_widget+h)){
        ui->volumeSlider->hide();
    }


    if (event->button() == Qt::LeftButton)
    {
        QRect rect = ui->widget->rect();  //rect是鼠标实现可拖动的区域
        rect.setBottom(rect.top() + 220);
        if (rect.contains(event->pos()))
        {
            m_bDragging = true;
            m_poStartPosition = event->globalPos();
            m_poFramePosition = frameGeometry().topLeft();
        }
    }
    QWidget::mousePressEvent(event);
}

void MainWidget::mouseMoveEvent(QMouseEvent* event)
{
    if (event->buttons() & Qt::LeftButton)	//只响应鼠标所见
    {
        if (m_bDragging)
        {
            // delta 相对偏移量,
            QPoint delta = event->globalPos() - m_poStartPosition;
            // 新位置：窗体原始位置  + 偏移量
            move(m_poFramePosition + delta);
        }
    }
    QWidget::mouseMoveEvent(event);
}

void MainWidget::mouseReleaseEvent(QMouseEvent* event)
{
    m_bDragging = false;
    QWidget::mouseReleaseEvent(event);
}


//播放音乐模式
void MainWidget::on_btnPlay_clicked()
{
    if(player->state()==QMediaPlayer::PlayingState)
    {
        ui->btnPlay->setStyleSheet("QPushButton{background-image: url(:/image/image/image/pase.png); background-repeat:no-repeat;background-position:center center;}" );
        player->pause();

    }
    else if(player->state()==QMediaPlayer::PausedState){
        ui->btnPlay->setStyleSheet("QPushButton{background-image: url(:/image/image/image/play.png); background-repeat:no-repeat;background-position:center center;}" );
        player->play();
    }
    else if(!playlist->isEmpty() && (player->state()==QMediaPlayer::StoppedState))
    {
        playlist->setCurrentIndex(0);
        player->play();
    }
}
//添加音乐
void MainWidget::on_btnAdd_clicked()
{
    QFileDialog fileDialog(this);
    //设置打开对话框的模式
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    //显示现有文件
    fileDialog.setFileMode(QFileDialog::ExistingFiles);
    //设置对话框标题
    fileDialog.setWindowTitle(tr("添加本地音乐（注：自动过滤，按下\"Ctrl+A\"全选添加即可；不支持添加文件夹）"));
    //设置过滤器
    QStringList list;list<<"application/octet-stream";
    //添加过滤器
    fileDialog.setMimeTypeFilters(list);
    //设置工作目录
    fileDialog.setDirectory(QStandardPaths::standardLocations(QStandardPaths::MusicLocation).value(0, QDir::homePath()));

    //当选择了文件 确定之后的操作  （加入music 播放器的 存储列表中）
    if (fileDialog.exec() == QDialog::Accepted){

        QList<QUrl> urls=fileDialog.selectedUrls();
        //添加音乐

        ui->listWidget->musicList.addMusic(urls);
        //QListWidget 添加子控件 QListWidgetitem  刷新图像显示
        ui->listWidget->refresh();
        //切换到本地音乐
        ui->stackedWidget->setCurrentIndex(1);//切换到本地音乐
    }
}








//MusicListWdiget 双击播放歌曲
void MainWidget::on_listWidget_doubleClicked(const QModelIndex &index)
{
    volume_flag=false;
    ui->btnPlay->setStyleSheet("QPushButton{background-image: url(:/image/image/image/play.png); background-repeat:no-repeat;background-position:center center;}" );
    player->setPlaylist(playlist);
    //添加歌曲播放表单
    ui->listWidget->musicList.addToPlayList(playlist);
    int i=index.row();
    playlist->setCurrentIndex(i);
    player->play();
    ui->stackedWidget->setCurrentIndex(1);//跳转到当前播放列表
}

void MainWidget::on_pushButton_6_clicked()
{
    //刷新子控件
    //    ui->listWidget->refresh();
    ui->stackedWidget->setCurrentIndex(1);
}
//下一首歌曲
void MainWidget::on_btnNext_clicked()
{
    playlist->next();
}
//上一首歌曲
void MainWidget::on_btnPre_clicked()
{
    playlist->previous();
}

//播放模式
void MainWidget::on_btnPlayMode_clicked()
{
    if(playlist->playbackMode()==QMediaPlaylist::Loop){

        ui->btnPlayMode->setToolTip(u8"随机播放");

        playlist->setPlaybackMode(QMediaPlaylist::Random);
    }
    else if(playlist->playbackMode()==QMediaPlaylist::Random){

        ui->btnPlayMode->setToolTip(u8"单曲循环");

        playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    }
    else if(playlist->playbackMode()==QMediaPlaylist::CurrentItemInLoop){

        ui->btnPlayMode->setToolTip(u8"循环播放");

        playlist->setPlaybackMode(QMediaPlaylist::Loop);
    }
}



//选择框
void MainWidget::on_pushButton_clicked()
{
    QMessageBox::StandardButton btn;

    btn = QMessageBox::question(this, "提示", "此操作不可逆！\n确实要清空吗?", QMessageBox::Yes|QMessageBox::No);

    if (btn == QMessageBox::Yes) {
        ui->listWidget->musicList.clear();
        ui->listWidget->refresh();

        ui->listWidget_2->musicList.clear();
        ui->listWidget_2->refresh();
    }
}

void MainWidget::init_delete(){
    QSqlQuery sql_query;
    QString delete_sql="delete from MusicLists";
    sql_query.prepare(delete_sql);
    sql_query.exec();
}

void MainWidget::on_btnVolume_clicked()
{
    if(ui->volumeSlider->isHidden()){
        ui->volumeSlider->show();
    }else{
        ui->volumeSlider->hide();
    }
}

void MainWidget::on_volumeSlider_valueChanged(int value)
{
    //当正在播放视频和音乐移动音量键 才进行 音量调节
    if(!volume_flag){

        player->setVolume(value);
        videoplayer->setVolume(value);
    }
}



void MainWidget::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWidget::on_pushButton_2_clicked()
{

    if(!refresh){
        ui->textEdit_2->clear();
        ui->listWidget_2->clear();
    }
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWidget::on_pushButton_11_clicked()
{

    QString name = ui->textEdit_2->toPlainText();

    //清除当前 控件listwdiget_2歌曲
    ui->listWidget_2->musicList.clear();

    QSqlQuery query;

    // 设置将要执行的SQL查询语句，:sname是要被绑定数据的位置
    query.prepare("select * from MusicInfo where author = :sname");
    query.bindValue(":sname",name);   // 绑定数据到指定的位置

    query.exec();

    QSqlRecord rec = query.record();

    QList<QUrl> music;

    while(query.next())
    {
        rec = query.record();
        int url= rec.indexOf("url");

        QUrl value1 = query.value(url).toString();

        qDebug()<<"sno:"<<value1<<"\t"<<"sname:";
        music.push_back(value1);
    }

    ui->listWidget_2->musicList.setMusic(music);


    ui->listWidget_2->refresh();
    //切换到本地音乐
    ui->stackedWidget->setCurrentIndex(2);

    refresh=false;

}

void MainWidget::on_listWidget_2_doubleClicked(const QModelIndex &index)
{
    volume_flag=false;
    ui->btnPlay->setStyleSheet("QPushButton{background-image: url(:/image/image/image/play.png); background-repeat:no-repeat;background-position:center center;}" );
    playlistquery->clear();

    for (int i=0;i<ui->listWidget_2->musicList.music.size();i++) {
        playlistquery->addMedia(ui->listWidget_2->musicList.music[i].getUrl());
    }

    player->setPlaylist( playlistquery);
    //    ui->listWidget->musicList.addToPlayList( playlistquery);
    int i=index.row();
    playlistquery->setCurrentIndex(i);
    player->play();
    ui->stackedWidget->setCurrentIndex(2);//跳转到当前播放列表
}


//右击菜单栏
void MainWidget::on_listWidget_3_customContextMenuRequested(const QPoint &pos)
{
    if(ui->listWidget->itemAt(pos)==Q_NULLPTR)
    {
        return;
    }
    menu_playlist->exec(QCursor::pos());
}

void MainWidget::on_listWidget_customContextMenuRequested(const QPoint &pos)
{
    if(ui->listWidget->itemAt(pos)==Q_NULLPTR)
    {
        return;
    }
    menu_playlist->exec(QCursor::pos());
}

void MainWidget::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWidget::on_favorMusicWidget_doubleClicked(const QModelIndex &index)
{
    volume_flag=false;
    ui->btnPlay->setStyleSheet("QPushButton{background-image: url(:/image/image/image/play.png); background-repeat:no-repeat;background-position:center center;}" );
    playlistquery->clear();

    for (int i=0;i<ui->favorMusicWidget->musicList.music.size();i++) {
        playlistquery->addMedia(ui->favorMusicWidget->musicList.music[i].getUrl());
    }

    player->setPlaylist( playlistquery);
    //     ui->favorMusicWidget->musicList.addToPlayList( playlistquery);
    int i=index.row();
    playlistquery->setCurrentIndex(i);
    player->play();
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWidget::on_btnSkin_clicked()
{
    menu_changeSkin->exec(QCursor::pos());
}


void MainWidget::showv(){

}
void MainWidget::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

    if(player->state()==QMediaPlayer::PausedState)
    {
        QImage picImage=QImage(":/image/image/image/non-music.png");
        ui->coverLabel->setPixmap(QPixmap::fromImage(picImage));
        ui->coverLabel->setScaledContents(true);

    }

    //如果视频未播放的话就将播放按钮设置为空
    if(      !if_reload ){
        ui->pushButton_14->setEnabled(false);
    }
}




void MainWidget::on_pushButton_15_clicked()
{

    ui->pushButton_14->setEnabled(true);
    //音量键 控制语句
    volume_flag=false;
    //选择视频文件
    QString filename = QFileDialog::getOpenFileName(this,tr("选择视频文件"),".",
                                                    tr("视频格式(*.avi *.mp4 *.flv *.mkv)"));
    //    QFile file(filename);

    //当选取文件不为空时
    if(filename!=nullptr){

        //播放label 图片更换

        QImage picImage=QImage(":/image/image/image/non-music.png");
        ui->coverLabel->setPixmap(QPixmap::fromImage(picImage));
        ui->coverLabel->setScaledContents(true);

        //当歌曲在播放时 停止歌曲的播放
        if(player->state()==QMediaPlayer::PlayingState)
        {
            player->pause();
        }
        if(if_reload)
        {//重新加载视频时，重置以下变量
            delete layout_video;
            delete  videoplayer ;
            delete widget;
            delete timer;
        }
        if_reload = true;



        //实例化三个全局变量
        layout_video = new QVBoxLayout(this);
        videoplayer = new QMediaPlayer(this);
        widget = new QVideoWidget(this);


        //设置视频播放区域与Label的边距
        layout_video->setMargin(1);
        //根据label_player尺寸设置播放区域
        widget->resize(ui->frame->size());
        layout_video->addWidget(widget);
        ui->frame->setLayout(layout_video);
        videoplayer->setVideoOutput(widget);
        videoplayer->setMedia(QUrl::fromLocalFile(filename));

        ui->positionSliderTwo->setEnabled(true);
        ui->positionSliderTwo->setRange(0,maxValue);

        timer = new QTimer();
        timer->setInterval(1000);//如果想看起来流畅些，可以把时间间隔调小，如100ms
        timer->start();
        //将timer连接至onTimerOut槽函数
        connect(timer, SIGNAL(timeout()), this, SLOT(onTimerOut()));
        ui->pushButton_14->setStyleSheet("QPushButton{background-image: url(:/image/image/image/play.png); background-repeat:no-repeat;background-position:center center;}" );
        videoplayer->play();
    }
}


void MainWidget::on_pushButton_14_clicked()
{


    if(videoplayer->state()==QMediaPlayer::PlayingState)
    {
        ui->pushButton_14->setStyleSheet("QPushButton{background-image: url(:/image/image/image/pase.png); background-repeat:no-repeat;background-position:center center;}" );

        videoplayer->pause();

    }
    else if(videoplayer->state()==QMediaPlayer::PausedState){
        ui->pushButton_14->setStyleSheet("QPushButton{background-image: url(:/image/image/image/play.png); background-repeat:no-repeat;background-position:center center;}" );


        videoplayer->play();
    }
}


void  MainWidget::onTimerOut()
{

    ui->positionSliderTwo->setValue( videoplayer->position()*maxValue/ videoplayer->duration());

    //当视频播放完成时
    if(videoplayer->state()==QMediaPlayer:: StoppedState){

        //视频暂停 到视频最开始处
        //        videoplayer->setPosition(0);
        videoplayer->pause();
        //进度条设置未为0
        ui->positionSliderTwo->setValue(0);
        //播放按钮样式修改
        ui->pushButton_14->setStyleSheet("QPushButton{background-image: url(:/image/image/image/pase.png); background-repeat:no-repeat;background-position:center center;}" );

    }
}


