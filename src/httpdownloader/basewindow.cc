#include "basewindow.hpp"
#include <QIcon>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QDebug>

BaseWindow::BaseWindow(QWidget *parent) :
    QWidget(parent)
{
    initComponents();
    connectSignals();
}


void BaseWindow::setLogo(const QIcon &icon)
{
    lbl_logo->setPixmap(icon.pixmap(20,20));
}
void BaseWindow::setTitle(const QString &text)
{
    lbl_title->setText(text);
}


void BaseWindow::setLayout(QLayout *layout)
{
    wdg_content->setLayout(layout);
}

void BaseWindow::setMinimizeVisible(bool visible)
{
    pbtn_minimize->setVisible(visible);
}


void BaseWindow::showModal()
{
    setWindowModality(Qt::ApplicationModal);
    show();
    if(QWidget *parent = parentWidget())
    {
        const QRect &rect = parent->geometry();
        int x = (rect.width()-this->width())/2+rect.x();
        int y = (rect.height()-this->height())/2+rect.y();
        move(x,y);
    }

}

void BaseWindow::onClose()
{

}

void BaseWindow::mousePressEvent(QMouseEvent *event)
{
    if((event->buttons() & Qt::LeftButton)  && wdg_title->rect().contains(event->pos()))
    {
        pressed = true;
        distance = event->globalPos() - pos();
    }

    QWidget::mousePressEvent(event);
}

void BaseWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(pressed && (event->buttons() & Qt::LeftButton))
    {
        move(event->globalPos()-distance);
    }

    QWidget::mouseMoveEvent(event);
}

void BaseWindow::mouseReleaseEvent(QMouseEvent *event)
{
    pressed = false;
    QWidget::mouseReleaseEvent(event);
}

void BaseWindow::initComponents()
{
    lbl_logo = new QLabel;
    lbl_title = new QLabel;
    lbl_title->setObjectName("window_title");

    pbtn_minimize = new QPushButton;
    pbtn_minimize->setObjectName("minimize_button");

    pbtn_close = new QPushButton;
    pbtn_close->setObjectName("close_button");

    QHBoxLayout *hbLayout = new QHBoxLayout;
    hbLayout->setMargin(0);
    hbLayout->setSpacing(0);
    hbLayout->addWidget(lbl_logo);
    hbLayout->addWidget(lbl_title);
    hbLayout->addStretch(1);
    hbLayout->addWidget(pbtn_minimize);
    hbLayout->addWidget(pbtn_close);

    wdg_title = new QWidget;
    wdg_title->setLayout(hbLayout);

    wdg_content = new QWidget;
    wdg_content->setObjectName("content_widget");

    QVBoxLayout *vbLayout = new QVBoxLayout;
    vbLayout->setMargin(4);
    vbLayout->setSpacing(2);
    vbLayout->addWidget(wdg_title);
    vbLayout->addWidget(wdg_content,1);

    QWidget::setLayout(vbLayout);
    this->setObjectName("basewindow");
    this->setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
}

void BaseWindow::connectSignals()
{
    QObject::connect(pbtn_minimize, &QPushButton::clicked, this, &BaseWindow::minimize);
    QObject::connect(pbtn_close,&QPushButton::clicked,this,&BaseWindow::handleClosed);
}

void BaseWindow::minimize()
{
    setWindowState(Qt::WindowMinimized);
}

void BaseWindow::handleClosed()
{
    onClose();
    close();
}



