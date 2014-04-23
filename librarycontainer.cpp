#include "librarycontainer.h"
#include <QSharedData>

class LibraryContainerData : public QSharedData {
public:
};

LibraryContainer::LibraryContainer() : data(new LibraryContainerData)
{
}

LibraryContainer::LibraryContainer(const LibraryContainer &rhs) : data(rhs.data)
{
}

LibraryContainer &LibraryContainer::operator=(const LibraryContainer &rhs)
{
	if (this != &rhs)
		data.operator=(rhs.data);
	return *this;
}

LibraryContainer::~LibraryContainer()
{
}
