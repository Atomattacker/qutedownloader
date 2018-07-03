#include "widget.hpp"

#include <QLabel>
#include <QPushButton>
#include <QToolButton>

Widget::Widget(QWidget *parent) :
    BaseWindow(parent)
{
    initComponents();
    connectSignals();
}

Widget::~Widget()
{

}


void Widget::initComponents()
{

    tbtn_addtask = new QToolButton;

    tbtn_cleartasks = new QToolButton;
    tbtn_setting = new QToolButton;

    this->setLogo(QIcon(":/images/download"));
    this->setTitle("Qutedownloader");
}

void Widget::connectSignals()
{

}
