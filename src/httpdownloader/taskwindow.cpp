#include "taskwindow.h"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QDebug>

TaskWindow::TaskWindow(QWidget *parent):
    BaseWindow(parent)
{
    initComponents();
    connectSignals();
}

void TaskWindow::showModal()
{
    setWindowModality(Qt::ApplicationModal);
    this->show();
    if(QWidget *parent = parentWidget())
    {
        const QRect &rect = parent->geometry();
        qDebug()<<rect<<",w="<<this->width()<<",h="<<this->height();

        int x = (rect.width()-this->width())/2+rect.x();
        int y = (rect.height()-this->height())/2+rect.y();
        move(x,y);
    }

}

void TaskWindow::initComponents()
{
    lbl_address = new QLabel("下载地址");
    lbl_savepath = new QLabel("保存路径");

    le_address = new QLineEdit;
    le_address->setMinimumWidth(200);

    le_savepath =new QLineEdit;
    le_savepath->setMinimumWidth(200);

    QHBoxLayout *hb1 = new QHBoxLayout;
    hb1->addWidget(lbl_address);
    hb1->addWidget(le_address);

    btn_selectpath = new QPushButton;
    btn_selectpath->setObjectName("selectpath_button");
    btn_selectpath->setIcon(QIcon(":/images/folder"));

    QHBoxLayout *hb2 = new QHBoxLayout;
    hb2->addWidget(lbl_savepath);
    hb2->addWidget(le_savepath);
    hb2->addWidget(btn_selectpath);

    btn_download = new QPushButton("下载");
    btn_download->setObjectName("download_button");

    btn_cancel = new QPushButton("取消");
    btn_cancel->setObjectName("cancel_button");

    QHBoxLayout *hb3 = new QHBoxLayout;
    hb3->addStretch(1);
    hb3->addWidget(btn_download);
    hb3->addWidget(btn_cancel);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(hb1);
    layout->addLayout(hb2);
    layout->addLayout(hb3);

    this->setTitle("新建任务");
    this->setMinimizeVisible(false);
    this->setLayout(layout);

}

void TaskWindow::connectSignals()
{
    QObject::connect(btn_selectpath,&QPushButton::clicked,this, &TaskWindow::selectPath);
    QObject::connect(btn_download,&QPushButton::clicked,this,&TaskWindow::startDownload);
    QObject::connect(btn_cancel,&QPushButton::clicked,this,&TaskWindow::close);
}

void TaskWindow::selectPath()
{

}
void TaskWindow::startDownload()
{

}
