#include "media.h"

Media::Media(quint32 m_id) {
	id = m_id;
}


quint32 Media::getID() { return id; }
QString Media::getName() { return name; }
QString Media::getLocation() { return location; }
bool Media::getFindFailed() { return location; }
bool Media::getReadFailed() { return location; }
