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
	
	setCentralWidget(tableStack);
	
	/////////////////////
	/// MENU BUILDING ///
	/////////////////////
	 


	

	
	/// File Menu ///
	fileMenu = menuBar()->addMenu(tr("&File"));
	
	/*                  Menu Structure
	 * Name			Activator key		Default shortcut
	 * File						F
	 *   Open file				o		Alt+O
	 *   Open stream			s		Alt+S
	 *  <sep>
	 *   Import file			i		Ctrl+O, also Ctrl+I on non-Mac
	 *   Import wizard			a		Ctrl+Shift+O, also Ctrl+Shift+I on non-Mac
	 *   Import stream			t		Ctrl+S
	 *  <sep>							(ENTIRE SECTION DISABLED WHEN NOTHING IS SELECTED)
	 *   Properties				p		Ctrl+P, also Ctrl+I on Mac
	 *   Show file				h		Ctrl+H
	 *   Convert				c		
	 *   //Add to playlist sub	d
	 *   //Show in playlist sub	w
	 *  <sep>
	 *   Quit					q		Ctrl+Q, Alt+F4  (MenuRole must be set to QAction::QuitRole)
	 */
	
	openFileAct = new QAction(tr("&Open a file...", "File menu"), this);
	//importLibAct->setShortcuts(QKeySequence::New);
	openFileAct->setStatusTip(tr("Temporarily open a file without importing it"));
	connect(openFileAct, SIGNAL(triggered()), this, SLOT(notImplemented()));
	fileMenu->addAction(openFileAct);
	
	openStreamAct = new QAction(tr("Open a &stream or podcast...", "File menu"), this);
	//importLibAct->setShortcuts(QKeySequence::New);
	openStreamAct->setStatusTip(tr("Temporarily open a stream or podcast episode without importing it"));
	connect(openStreamAct, SIGNAL(triggered()), this, SLOT(notImplemented()));
	fileMenu->addAction(openStreamAct);
	
	fileMenu->addSeparator();
	
	importFilesAct = new QAction(tr("&Import files...", "File menu"), this);
	//importLibAct->setShortcuts(QKeySequence::New);
	importFilesAct->setStatusTip(tr("Import new files to your library"));
	connect(importFilesAct, SIGNAL(triggered()), this, SLOT(notImplemented()));
	fileMenu->addAction(importFilesAct);
	
	importWizardAct = new QAction(tr("&Advanced import...","File menu"), this);
	//importLibAct->setShortcuts(QKeySequence::New);
	importWizardAct->setStatusTip(tr("Import new files to your library using the Import Wizard"));
	connect(importWizardAct, SIGNAL(triggered()), this, SLOT(notImplemented()));
	fileMenu->addAction(importWizardAct);
	
	importStreamAct = new QAction(tr("Import s&tream or podcast...", "File menu"), this);
	//importLibAct->setShortcuts(QKeySequence::New);
	importStreamAct->setStatusTip(tr("Import a stream or podcast to your library"));
	connect(importStreamAct, SIGNAL(triggered()), this, SLOT(notImplemented()));
	fileMenu->addAction(importStreamAct);
	
	fileMenu->addSeparator();
	
	itemToolsGroup = new QActionGroup(this);  // Allows these to be easily enabled/disabled
	itemToolsGroup->setExclusive(false);
	itemToolsGroup->setEnabled(false);  // TODO:  Base on whether or not something is selected
	
	propertiesAct = new QAction(tr("&Properties...", "File menu"), this);
	//importLibAct->setShortcuts(QKeySequence::New);
	propertiesAct->setStatusTip(tr("View and edit the properties of selection"));
	connect(propertiesAct, SIGNAL(triggered()), this, SLOT(notImplemented()));
	fileMenu->addAction(propertiesAct);
	itemToolsGroup->addAction(propertiesAct);
	
	showFileAct = new QAction(tr("S&how file...", "File menu"), this);
	//importLibAct->setShortcuts(QKeySequence::New);
	showFileAct->setStatusTip(tr("Show the file in the filesystem"));
	connect(showFileAct, SIGNAL(triggered()), this, SLOT(notImplemented()));
	fileMenu->addAction(showFileAct);
	itemToolsGroup->addAction(showFileAct);
	
	convertAct = new QAction(tr("&Convert...", "File menu"), this);
	//importLibAct->setShortcuts(QKeySequence::New);
	convertAct->setStatusTip(tr("Convert this file to a different file type"));
	connect(convertAct, SIGNAL(triggered()), this, SLOT(notImplemented()));
	fileMenu->addAction(convertAct);
	itemToolsGroup->addAction(convertAct);
	
	fileMenu->addSeparator();
	
	quitAct = new QAction(tr("&Quit", "File menu"), this);
	quitAct->setMenuRole(QAction::QuitRole);
	//importLibAct->setShortcuts(QKeySequence::New);
	quitAct->setStatusTip(tr("Exit Nostalgia"));
	connect(quitAct, SIGNAL(triggered()), this, SLOT(notImplemented()));
	fileMenu->addAction(quitAct);
	
	
	
	/// Edit Menu ///
	editMenu = menuBar()->addMenu(tr("&Edit"));
	
	/*                  Menu Structure
	 * Name			Activator key		Default shortcut
	 * Edit						E
     *   Undo					u		Ctrl+Z
     *   Redo					o		Ctrl+Shift+Z
     *  <sep>
     *   Copy (cut)				c		Ctrl+C, Ctrl+X
     *   Paste					p		Ctrl+V
     *  <sep>
     *   Select all				a		Ctrl+A
     *   Deselect all			d		Ctrl+Shift+A
     *   Invert selection		i		Ctrl+Alt+A
     *   Select by artist		r		Ctrl+Shift+R
     *   Select by album		l		Ctrl+Shift+L
     *   Select by album artist	b		Ctrl+Shift+B
     *   Select by tags			t		Ctrl+Shift+T
     *  <sep>
     *   Remove from list		v		Backspace
     *   Remove from library	e		Delete
     *   Delete file			l		Ctrl+Delete
	 */
		
	//newAct = new QAction(tr("&New"), this);
	//newAct->setShortcuts(QKeySequence::New);
	//newAct->setStatusTip(tr("Create a new file"));
	//connect(newAct, SIGNAL(triggered()), this, SLOT(notImplemented()));
	//libraryMenu->addAction(newAct);
	
	
	/// Playback Menu ///
	playbackMenu = menuBar()->addMenu(tr("Play&back"));
	
	/*                  Menu Structure
	 * Name			Activator key		Default shortcut
	 * Playback					B
	 *   Play/Pause				p		Space
	 *   Play					a		Ctrl+Space
	 *   Pause					u		Alt+Space
	 *   Stop					s		Ctrl+Shift+Space
	 *   Rewind					r		Left, A
	 *   Go to time				g		Ctrl+G
	 *   Next track				n		Right, D
	 *   Previous track			t		Ctrl+Left
	 *  <sep>
	 *   Volume up				v		+, =, Shift+=
	 *   Volume down			d		-
	 *   Equalizer				e		Ctrl+E
	 *  playbackMenu->addSeparator()->setText(tr("Shuffle mode"));
	 *   Shuffle off			o		TBD
	 *   Shuffle all			l		TBD
	 *   Shuffle within list	w		TBD
	 *   Shuffle lists			i		TBD
	 *   Shuffle within list, then shuffle to next list		TBD		TBD
	 *  playbackMenu->addSeparator()->setText(tr("Repeat mode"));
	 *   Repeat off				p		TBD
	 *   Repeat song					TBD
	 *   Repeat list					TBD
	 *   Repeat library					TBD  (disabled when not in a shuffle mode that allows it)
	 */
	
	playPauseAct = new QAction(tr("&Play/Pause", "Playback menu"), this);
	QList<QKeySequence> TEMPLISTOFKEYSEQUENCES; TEMPLISTOFKEYSEQUENCES.append(QKeySequence(Qt::Key_Space));  // TODO:  REMOVE (put in settings)
	playPauseAct->setShortcuts(TEMPLISTOFKEYSEQUENCES);
	playPauseAct->setStatusTip(tr("Toggle playback"));
	connect(playPauseAct, SIGNAL(triggered()), this, SLOT(tbd()));
	playbackMenu->addAction(playPauseAct);
	
	
	/// Playlist Menu ///
	playlistMenu = menuBar()->addMenu(tr("Play&list"));
	
	/*                  Menu Structure
	 * Name			Activator key		Default shortcut 
	 * Playlist					L
	 * 
	 */
	
	//newAct = new QAction(tr("&New"), this);
	//newAct->setShortcuts(QKeySequence::New);
	//newAct->setStatusTip(tr("Create a new file"));
	//connect(newAct, SIGNAL(triggered()), this, SLOT(notImplemented()));
	//libraryMenu->addAction(newAct);
	
	
	/// Tools Menu ///
	toolsMenu = menuBar()->addMenu(tr("&Tools"));
	
	/*                  Menu Structure
	 * Name			Activator key		Default shortcut
	 * Tools					T
	 *	Library sub				L
	 *    Export library		e		
	 *    Move library			m
	 *    Load a library		a
	 *    Create new library	c
	 *    Library options		o
	 *  <sep>
	 *   Equalizer				e		TBD
	 *  <sep>
	 *   Library statistics
	 *   Selection statistics
	 *  <sep>
	 *   Options				p		Ctrl+,  (MenuRole must be set to QAction::PreferencesRole)
	 * 
	 */
	
	
	exportLibAct = new QAction(tr("&Export library...", "Tools menu"), this);
	//exportLibAct->setShortcuts(QKeySequence::New);
	exportLibAct->setStatusTip(tr("Export your library for import elsewhere"));
	connect(exportLibAct, SIGNAL(triggered()), this, SLOT(notImplemented()));
	toolsMenu->addAction(exportLibAct);
	
	moveLibAct = new QAction(tr("&Move library...", "Tools menu"), this);
	//moveLibAct->setShortcuts(QKeySequence::New);
	moveLibAct->setEnabled(false);  // TODO:  Set to rely on the setting whether or not library is automatically organized
	moveLibAct->setStatusTip(tr("Move your library to a new location"));
	connect(moveLibAct, SIGNAL(triggered()), this, SLOT(notImplemented()));
	toolsMenu->addAction(moveLibAct);
	
	loadDiffLibAct = new QAction(tr("&Load a library...", "Tools menu"), this);
	//loadDiffLibAct->setShortcuts(QKeySequence::New);
	loadDiffLibAct->setStatusTip(tr("Select a different library to load and restart Nostalgia"));
	connect(loadDiffLibAct, SIGNAL(triggered()), this, SLOT(notImplemented()));
	toolsMenu->addAction(loadDiffLibAct);
	
	
	//newAct = new QAction(tr("&New"), this);
	//newAct->setShortcuts(QKeySequence::New);
	//newAct->setStatusTip(tr("Create a new file"));
	//connect(newAct, SIGNAL(triggered()), this, SLOT(notImplemented()));
	//libraryMenu->addAction(newAct);
	
	
	/// View Menu ///
	viewMenu = menuBar()->addMenu(tr("&View"));
	
	/*                  Menu Structure
	 * Name			Activator key		Default shortcut
	 * View						V
	 *   Show in shuffled order	TBD		TBD (checkable; disabled in an album view)
	 * 
	 */
	
	//newAct = new QAction(tr("&New"), this);
	//newAct->setShortcuts(QKeySequence::New);
	//newAct->setStatusTip(tr("Create a new file"));
	//connect(newAct, SIGNAL(triggered()), this, SLOT(notImplemented()));
	//libraryMenu->addAction(newAct);
	
	
	/// Help Menu ///
	helpMenu = menuBar()->addMenu(tr("&Help"));
	
	/*                  Menu Structure
	 * Name			Activator key		Default shortcut
	 * Help						H
	 *   Check for new version	c
	 *  <sep>
	 *   Documentation			d		Ctrl+H, F1
	 *   Forums					f
	 *   Report a bug			r
	 *  <sep>
	 *   View on GitHub			g
	 *   About Nostalgia		n		(MenuRole must be set to QAction::AboutRole)
	 *   About Qt				q		(MenuRole must be set to QAction::AboutQtRole)
	 * 
	 */
	
	//newAct = new QAction(tr("&New"), this);
	//newAct->setShortcuts(QKeySequence::New);
	//newAct->setStatusTip(tr("Create a new file"));
	//connect(newAct, SIGNAL(triggered()), this, SLOT(notImplemented()));
	//libraryMenu->addAction(newAct);
	
	
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
	
	
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event) {
	
}

void MainWindow::notImplemented() {
	QMessageBox *notImplementedMessage = new QMessageBox(QMessageBox::Information,
		tr("Feature Not Implemented", "Dialog title"),
		tr("Unfortunately, the item you requested has not yet been implemented.  You "
		   "can either wait until a new version is released (ETA: probably years) or contact the "
		   "developers and harshly demand they implement it now.  Results may vary."),
		   QMessageBox::Ok);
	notImplementedMessage->show();
	statusBar()->showMessage(tr("Feature Not Implemented"));
}

void MainWindow::tbd() {
	QMessageBox *notImplementedMessage = new QMessageBox(QMessageBox::Critical,
		"fuc",
		"fuc",
														 QMessageBox::No);
	notImplementedMessage->show();
	statusBar()->showMessage(tr("Feature Not Implemented"));
}

MainWindow::~MainWindow() {
}
