#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QObject>

class AudioPlayer : public QObject
{
	Q_OBJECT
public:
	explicit AudioPlayer(QObject *parent = 0);
	
signals:
	void togglePlayback();
	void pause();
	void play();
	void halt();
	
	
public slots:
	
};

#endif // AUDIOPLAYER_H
