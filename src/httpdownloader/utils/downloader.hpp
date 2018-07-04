#ifndef UTILITIES_DOWNLOADER_HPP
#define UTILITIES_DOWNLOADER_HPP

#include <QObject>

class QDir;

namespace Utilities {

class Downloader : public QObject
{
    Q_OBJECT
public:
    Downloader(QObject *parent = nullptr);

    void setUrl(const QUrl &url);
    void setUrl(const QString &url);
    void setDir(const QDir &url);
    void setDir(const QString &dir);

    void start();
    float speed()const;
    float progress()const;

    QString error()const;

signals:
    void completed();
    void failed();


};

}


#endif // UTILITIES_HPP
