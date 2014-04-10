#ifndef MEDIACONTAINER_H
#define MEDIACONTAINER_H

#include <QObject>
#include <QAbstractItemModel>
#include "media.h"

class MediaContainer : public QObject
{
	Q_OBJECT
public:
	explicit MediaContainer(QObject *parent = 0);
	
private:
	QList<Media> contents;
	
signals:
	
public slots:
	
};

#endif // MEDIACONTAINER_H
