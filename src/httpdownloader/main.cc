#include "widget.hpp"
#include <QApplication>
#include <QTextCodec>
#include <QFile>
#include <QIcon>
#include <QDebug>

static QString getStyleSheet();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QApplication::setWindowIcon(QIcon(":/images/download"));
    Widget w;
    w.resize(500,360);
    w.setStyleSheet(getStyleSheet());
    w.show();
    return a.exec();
}


QString getStyleSheet()
{
    QFile f(":/qss/style");
    if(f.open(QIODevice::ReadOnly))
    {
        QString style(f.readAll());
        f.close();
        return style;
    }
    return QString();
}
