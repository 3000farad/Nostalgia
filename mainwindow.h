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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QStackedWidget>
#include <QListWidget>
#include <QDockWidget>
#include <QTreeWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT
	
public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	
protected:
	void contextMenuEvent(QContextMenuEvent *event);
	
private slots:
	void newFile();
	
private:
	//Ui::MainWindow *ui;
	QStackedWidget *tableStack;
	QDockWidget *listSelectorDock;
	QTreeWidget *listSelector;
	QMenu *libraryMenu;
	QMenu *playlistMenu;
	QMenu *editMenu;
	QMenu *controlsMenu;
	QMenu *dataMenu;
	QMenu *optionsMenu;
	QMenu *helpMenu;
	QAction *newAct;  // TODO:  REMOVE
	QAction *playPauseAct;
	
	QListWidget *TEMPTBD;
	QListWidget *TEMPTBD2;
};

#endif // MAINWINDOW_H
