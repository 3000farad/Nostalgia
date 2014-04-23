#ifndef LIBRARYCONTAINER_H
#define LIBRARYCONTAINER_H

#include <QSharedDataPointer>

class LibraryContainerData;

class LibraryContainer
{
public:
	LibraryContainer();
	LibraryContainer(const LibraryContainer &);
	LibraryContainer &operator=(const LibraryContainer &);
	~LibraryContainer();
	
private:
	QSharedDataPointer<LibraryContainerData> data;
};

#endif // LIBRARYCONTAINER_H
