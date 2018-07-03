#ifndef WIDGET_HPP
#define WIDGET_HPP

#include "basewindow.hpp"

#include <QWidget>


class QLabel;
class QPushButton;
class QListWidget;
class QToolButton;
class QListWidget;


class Widget : public BaseWindow
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:


private:
    void initComponents();
    void connectSignals();

private:
    QToolButton *tbtn_addtask;
    QToolButton *tbtn_cleartasks;
    QToolButton *tbtn_setting;

    QListWidget *lw_tasks;

};

#endif // WIDGET_HPP
