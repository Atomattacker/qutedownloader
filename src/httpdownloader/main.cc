#include "window.hpp"
#include <QApplication>
#include <QTextCodec>
#include <QFile>
#include <QIcon>
#include <QDebug>

static QString getStyleSheet();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setWindowIcon(QIcon(":/images/download"));
    Window w;
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
