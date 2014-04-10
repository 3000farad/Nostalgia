#include "mediacontainer.h"
#include <QSharedData>

class MediaContainerData : public QSharedData {
public:
};

MediaContainer::MediaContainer() : data(new MediaContainerData)
{
}

MediaContainer::MediaContainer(const MediaContainer &rhs) : data(rhs.data)
{
}

MediaContainer &MediaContainer::operator=(const MediaContainer &rhs)
{
	if (this != &rhs)
		data.operator=(rhs.data);
	return *this;
}

MediaContainer::~MediaContainer()
{
}
