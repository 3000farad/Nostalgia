#include "media.h"

Media::Media(QObject *parent) :
	QObject(parent)
{
}

bool modifyParameter(Media::Parameter param, int newValue) {
	return false;
}
