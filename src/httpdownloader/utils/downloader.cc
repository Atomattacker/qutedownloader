#include "downloader.hpp"

#include <QUrl>

namespace Utilities {

Downloader::Downloader(QObject *parent):
    QObject(parent)
{

}


void Downloader::setUrl(const QUrl &url)
{

}

void Downloader::setUrl(const QString &url)
{

}

void Downloader::setDir(const QDir &url)
{

}

void Downloader::setDir(const QString &dir)
{

}

void Downloader::start()
{

}

float Downloader::speed()const
{

}

float Downloader::progress()const
{

}

QString Downloader::error()const
{

}


}
