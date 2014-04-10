#ifndef MEDIA_H
#define MEDIA_H

#include <QDateTime>

class Media
{
	
public:
	Media();
	quint32 getID();
	QString getName();
	QString getLocation();
	bool findFailed;
	bool readFailed;
	
protected:
	quint32 id;
	QString name;
	QString location;
	
};

#endif // MEDIA_H
