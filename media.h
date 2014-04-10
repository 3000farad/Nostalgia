#ifndef MEDIA_H
#define MEDIA_H

#include <QObject>
#include <QDateTime>

class Media : public QObject
{
	Q_OBJECT
	
public:
	typedef enum {
		MP_ID,
		MP_Name,
		MP_Location
	} Parameter;
	
	explicit Media(QObject *parent = 0);
	
	bool modifyParameter(Media::Parameter param, QVariant newValue);
	
private:
	quint32 ID;
	QString Name;
	QString Location;
	QDateTime LastPlayed;
	QDateTime LastSkipped;
	QDateTime DateAdded;
	
	
signals:
	
public slots:
	
};

#endif // MEDIA_H
