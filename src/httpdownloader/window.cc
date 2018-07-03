#include "window.hpp"

#include <QLabel>
#include <QPushButton>
#include <QToolButton>
#include <QHBoxLayout>
#include <QListWidget>

Window::Window(QWidget *parent) :
    BaseWindow(parent)
{
    initComponents();
    connectSignals();
}

Window::~Window()
{

}


void Window::initComponents()
{
    tbtn_addtask = new QToolButton;
    tbtn_addtask->setText("新建任务");
    tbtn_addtask->setIcon(QIcon(":/images/add"));
    tbtn_addtask->setObjectName("addtask_button");
    tbtn_addtask->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    tbtn_cleartasks = new QToolButton;
    tbtn_cleartasks->setText("清空任务");
    tbtn_cleartasks->setIcon(QIcon(":/images/clear"));
    tbtn_cleartasks->setObjectName("clear_button");
    tbtn_cleartasks->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    tbtn_setting = new QToolButton;
    tbtn_setting->setText("设置");
    tbtn_setting->setIcon(QIcon(":/images/setting"));
    tbtn_setting->setObjectName("setting_button");
    tbtn_setting->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    QHBoxLayout *hbLayout = new QHBoxLayout;
    hbLayout->addStretch(1);
    hbLayout->addWidget(tbtn_addtask);
    hbLayout->addWidget(tbtn_cleartasks);
    hbLayout->addWidget(tbtn_setting);


    QWidget *toolWidget = new QWidget;
    toolWidget->setObjectName("tool_widget");
    toolWidget->setLayout(hbLayout);


    lw_tasks = new QListWidget;
    lw_tasks->setObjectName("tasks_listwidget");

    QVBoxLayout *vbLayout = new QVBoxLayout;
    vbLayout->setMargin(0);
    vbLayout->setSpacing(0);
    vbLayout->addWidget(toolWidget);
    vbLayout->addWidget(lw_tasks);

    this->setLayout(vbLayout);
    this->setLogo(QIcon(":/images/download"));
    this->setTitle("Qutedownloader");
}

void Window::connectSignals()
{

}
