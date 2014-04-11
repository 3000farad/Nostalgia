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
#include <QStatusBar>
#include <QMenuBar>
#include <QMenu>
#include <QStackedWidget>
#include <QListWidget>  // TODO:  REMOVE THIS
#include <QDockWidget>
#include <QTreeWidget>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT
	
public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	QAction *openFileAct;
	QAction *openStreamAct;
	QAction *importFilesAct;
	QAction *importWizardAct;
	QAction *importStreamAct;
	QAction *exportLibAct;
	QAction *moveLibAct;
	QAction *loadDiffLibAct;
	QAction *playPauseAct;
	QMessageBox *notImplementedMessage;
	
public slots:
	void notImplemented();
	
protected:
	void contextMenuEvent(QContextMenuEvent *event);
	
private slots:
	
private:
	QStackedWidget *tableStack;
	QDockWidget *listSelectorDock;
	QTreeWidget *listSelector;
	QMenu *fileMenu;
	QMenu *editMenu;
	QMenu *playlistMenu;
	QMenu *playbackMenu;
	QMenu *toolsMenu;
	QMenu *optionsMenu;
	QMenu *helpMenu;
	
	QListWidget *TEMPTBD;
	QListWidget *TEMPTBD2;
};

#endif // MAINWINDOW_H
