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

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent)
{
	// See http://qt-project.org/doc/qt-4.8/mainwindow.html
	
	///////////////////////////
	/// VIEW TABLE BUILDING ///
	///////////////////////////
	
	/// Song Table ///
	TEMPTBD = new QListWidget(this);
	new QListWidgetItem("Test", TEMPTBD);
	new QListWidgetItem("Test2", TEMPTBD);
	new QListWidgetItem("Hey buddy", TEMPTBD);
	TEMPTBD2 = new QListWidget(this);
	new QListWidgetItem("Completely New", TEMPTBD2);
	new QListWidgetItem("Gamechanging", TEMPTBD2);
	new QListWidgetItem("Hey buddy", TEMPTBD2);
	
	/// Artist Table ///
	/// Album Table ///
	/// Genre Table ///
	
	/// Table Stack ///
	tableStack = new QStackedWidget(this);
	tableStack->addWidget(TEMPTBD);
	tableStack->addWidget(TEMPTBD2);
	statusBar()->showMessage(QString("Counted %1 widgets").arg(tableStack->count()));
	
	setCentralWidget(tableStack);
	
	/////////////////////
	/// MENU BUILDING ///
	/////////////////////
	
	/// File Menu ///
	fileMenu = menuBar()->addMenu(tr("&File"));
	
	openFileAct = new QAction(tr("&Open a file..."), this);
	//importLibAct->setShortcuts(QKeySequence::New);
	openFileAct->setStatusTip(tr("Temporarily open a file without importing it"));
	connect(openFileAct, SIGNAL(triggered()), this, SLOT(notImplemented()));
	fileMenu->addAction(openFileAct);
	
	openStreamAct = new QAction(tr("&Open a stream or podcast..."), this);
	//importLibAct->setShortcuts(QKeySequence::New);
	openStreamAct->setStatusTip(tr("Temporarily open a stream or podcast episode without importing it"));
	//connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));
	fileMenu->addAction(openStreamAct);
	
	fileMenu->addSeparator();
	
	importFilesAct = new QAction(tr("&Import files..."), this);
	//importLibAct->setShortcuts(QKeySequence::New);
	importFilesAct->setStatusTip(tr("Import new files to your library"));
	//connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));
	fileMenu->addAction(importFilesAct);
	
	importWizardAct = new QAction(tr("&Advanced import..."), this);
	//importLibAct->setShortcuts(QKeySequence::New);
	importWizardAct->setStatusTip(tr("Import new files to your library using the Import Wizard"));
	//connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));
	fileMenu->addAction(importWizardAct);
	
	importStreamAct = new QAction(tr("&Import stream or podcast..."), this);
	//importLibAct->setShortcuts(QKeySequence::New);
	importStreamAct->setStatusTip(tr("Import a stream or podcast to your library"));
	//connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));
	fileMenu->addAction(importStreamAct);
	
	fileMenu->addSeparator();
	
	exportLibAct = new QAction(tr("&Export library..."), this);
	//exportLibAct->setShortcuts(QKeySequence::New);
	exportLibAct->setStatusTip(tr("Export your library for import elsewhere"));
	//connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));
	fileMenu->addAction(exportLibAct);
	
	moveLibAct = new QAction(tr("&Move library..."), this);
	//moveLibAct->setShortcuts(QKeySequence::New);
	moveLibAct->setEnabled(false);  // TODO:  Set to rely on the setting whether or not library is automatically organized
	moveLibAct->setStatusTip(tr("Move your library to a new location"));
	//connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));
	fileMenu->addAction(moveLibAct);
	
	loadDiffLibAct = new QAction(tr("&Load a library..."), this);
	//loadDiffLibAct->setShortcuts(QKeySequence::New);
	loadDiffLibAct->setStatusTip(tr("Select a different library to load and restart Nostalgia"));
	//connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));
	fileMenu->addAction(loadDiffLibAct);
	
	fileMenu->addSeparator();
	
	
	
	/// Edit Menu ///
	//newAct = new QAction(tr("&New"), this);
	//newAct->setShortcuts(QKeySequence::New);
	//newAct->setStatusTip(tr("Create a new file"));
	//connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));
	
	editMenu = menuBar()->addMenu(tr("&Edit"));
	//libraryMenu->addAction(newAct);
	//libraryMenu->addSeparator();
	
	
	/// Playlist Menu ///
	//newAct = new QAction(tr("&New"), this);
	//newAct->setShortcuts(QKeySequence::New);
	//newAct->setStatusTip(tr("Create a new file"));
	//connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));
	
	playlistMenu = menuBar()->addMenu(tr("&Playlist"));
	//libraryMenu->addAction(newAct);
	//libraryMenu->addSeparator();
	
	
	/// Playback Menu ///
	playbackMenu = menuBar()->addMenu(tr("&Playback"));
	
	playPauseAct = new QAction(tr("&Play/Pause"), this);
	QList<QKeySequence> TEMPLISTOFKEYSEQUENCES; TEMPLISTOFKEYSEQUENCES.append(QKeySequence(Qt::Key_Space));  // TODO:  REMOVE (put in settings)
	playPauseAct->setShortcuts(TEMPLISTOFKEYSEQUENCES);
	playPauseAct->setStatusTip(tr("Toggle playback"));
	connect(playPauseAct, SIGNAL(triggered()), this, SLOT(notImplemented()));
	
	playbackMenu->addAction(playPauseAct);
	//libraryMenu->addSeparator();
	
	
	/// Tools Menu ///
	//newAct = new QAction(tr("&New"), this);
	//newAct->setShortcuts(QKeySequence::New);
	//newAct->setStatusTip(tr("Create a new file"));
	//connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));
	
	toolsMenu = menuBar()->addMenu(tr("&Tools"));
	//libraryMenu->addAction(newAct);
	//libraryMenu->addSeparator();
	
	
	/// Options Menu ///
	//newAct = new QAction(tr("&New"), this);
	//newAct->setShortcuts(QKeySequence::New);
	//newAct->setStatusTip(tr("Create a new file"));
	//connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));
	
	optionsMenu = menuBar()->addMenu(tr("&Options"));
	//libraryMenu->addAction(newAct);
	//libraryMenu->addSeparator();
	
	
	/// Help Menu ///
	//newAct = new QAction(tr("&New"), this);
	//newAct->setShortcuts(QKeySequence::New);
	//newAct->setStatusTip(tr("Create a new file"));
	//connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));
	
	helpMenu = menuBar()->addMenu(tr("&Help"));
	//libraryMenu->addAction(newAct);
	//libraryMenu->addSeparator();
	
	
	/////////////////////
	/// DOCK BUILDING ///
	/////////////////////
	
	/// List Selector Dock ///
	listSelectorDock = new QDockWidget(tr("Lists"), this);
	listSelectorDock->setAllowedAreas(Qt::LeftDockWidgetArea |
									 Qt::RightDockWidgetArea);
	addDockWidget(Qt::LeftDockWidgetArea, listSelectorDock);
	
	listSelector = new QTreeWidget(listSelectorDock);
	listSelectorDock->setWidget(listSelector);
	
	/// Playback Controls Grid ///
	/// Song Info Grid ///
	/// Search Layout ///
	/// Main Bar Dock ///
	
	
	////////////////////
	/// WINDOW SETUP ///
	////////////////////
	
	setWindowTitle(tr("Nostalgia"));
	setMinimumSize(600,300);
	resize(1000,500);
	
	
	/////////////////////////////
	/// OTHER INITIALIZATIONS ///
	/////////////////////////////
	
	notImplementedMessage = new QMessageBox(QMessageBox::Information,
		tr("Feature Not Implemented"),
		tr("Unfortunately, the item you requested has not yet been implemented.  You "
		   "can either wait until a new version is released (ETA: probably years) or contact the "
		   "developers and harshly demand they implement it now.  Results may vary."),
		   QMessageBox::Ok);
	
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event) {
	
}

void MainWindow::notImplemented() {
	notImplementedMessage->show();
	statusBar()->showMessage(tr("Feature Not Implemented"));
}

MainWindow::~MainWindow() {
}
