#ifndef TASKWINDOW_H
#define TASKWINDOW_H

#include "basewindow.hpp"

class QLabel;
class QLineEdit;
class QPushButton;

class TaskWindow : public BaseWindow
{
public:
    TaskWindow(QWidget *parent = nullptr);

public:
    void showModal();

private:
    void initComponents();
    void connectSignals();

    void selectPath();
    void startDownload();
private:
    QLabel *lbl_address;
    QLabel *lbl_savepath;

    QLineEdit *le_address;
    QLineEdit *le_savepath;

    QPushButton *btn_selectpath;
    QPushButton *btn_download;
    QPushButton *btn_cancel;

};

#endif // TASKWINDOW_H
