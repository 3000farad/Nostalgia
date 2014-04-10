#ifndef MEDIACONTAINER_H
#define MEDIACONTAINER_H

#include <QSharedDataPointer>

class MediaContainerData;

class MediaContainer
{
public:
	MediaContainer();
	MediaContainer(const MediaContainer &);
	MediaContainer &operator=(const MediaContainer &);
	~MediaContainer();
	
private:
	QSharedDataPointer<MediaContainerData> data;
};

#endif // MEDIACONTAINER_H
