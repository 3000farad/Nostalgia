/*********************************************************
*  This file is part of Nostalgia.                       *
*                                                        *
*  Nostalgia is Copyright Jason Prince 2014.             *
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

#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	
	// TODO:  SPLASH SCREEN HERE  (Note: splash screen must not have any translatable text on it)
	
	QIcon icon (":/icons/icon32.png");
	app.setWindowIcon(icon);
	
	// TODO:  OPTIONS LOADING HERE
	
	QString locale = QLocale::system().name();  // TODO:  Make this based on settings if available
	QTranslator translator;
	translator.load(QString("arrowpad_") + locale);
	app.installTranslator(&translator);
	
	// TODO:  START AN INSTANCE OF LibraryManager in new thread
	
	// TODO:  START AN INSTANCE OF AudioPlayer in new thread
	
	////////////////////////
	/// MainWindow Setup ///
	////////////////////////
	
	MainWindow window;
	window.show();
	
	// TODO:  KILL SPLASH SCREEN HERE (after ensuring it has been up for 3 seconds)
	
	return app.exec();
}
