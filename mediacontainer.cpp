/*********************************************************
*  This file is part of Nostalgia.                       *
*                                                        *
*  Nostalgia is free software: you can redistribute it   *
*  and/or modify it under the terms of the GNU General   *
*  Public License as published by the Free Software      *
*  Foundation, either version 3 of the License, or (at   *
*  your option) any later version.                       *
*                                                        *
*  Nostalgia is distributed in the hope that it will be  *
*  useful, but WITHOUT ANY WARRANTY; without even the    *
*  implied warranty of MERCHANTABILITY or FITNESS FOR A  *
*  PARTICULAR PURPOSE.  See the GNU General Public       *
*  License for more details.                             *
*                                                        *
*  You should have received a copy of the GNU General    *
*  Public License along with Nostalgia.  If not, see     *
*  <http://www.gnu.org/licenses/>.                       *
*********************************************************/

#include "mediacontainer.h"

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
