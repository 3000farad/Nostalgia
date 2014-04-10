#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListWidget>  // TODO:  REMOVE THIS

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent)
	//ui(new Ui::MainWindow)
{
	// See http://qt-project.org/doc/qt-4.8/mainwindow.html
	
	/////////////////////////
	// VIEW TABLE BUILDING //
	/////////////////////////
	
				// Song Table //
	TEMPTBD = new QListWidget(this);
	new QListWidgetItem("Test", TEMPTBD);
	new QListWidgetItem("Test2", TEMPTBD);
	new QListWidgetItem("Hey buddy", TEMPTBD);
	TEMPTBD2 = new QListWidget(this);
	new QListWidgetItem("Completely New", TEMPTBD2);
	new QListWidgetItem("Gamechanging", TEMPTBD2);
	new QListWidgetItem("Hey buddy", TEMPTBD2);
				// Artist Table //
				// Album Table //
				// Genre Table //
	
				// Table Stack //
	tableStack = new QStackedWidget(this);
	tableStack->addWidget(TEMPTBD);
	tableStack->addWidget(TEMPTBD2);
	statusBar()->showMessage(QString("Counted %1 widgets").arg(tableStack->count()));
	
	setCentralWidget(tableStack);
	
	///////////////////
	// MENU BUILDING //
	///////////////////
	
				// Library Menu //
	newAct = new QAction(tr("&New"), this);
	newAct->setShortcuts(QKeySequence::New);
	newAct->setStatusTip(tr("Create a new file"));
	connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));
	
	libraryMenu = menuBar()->addMenu(tr("&Library"));
	libraryMenu->addAction(newAct);
	//libraryMenu->addSeparator();
	
	
				// Playlist Menu //
	//newAct = new QAction(tr("&New"), this);
	//newAct->setShortcuts(QKeySequence::New);
	//newAct->setStatusTip(tr("Create a new file"));
	//connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));
	
	playlistMenu = menuBar()->addMenu(tr("&Playlist"));
	//libraryMenu->addAction(newAct);
	//libraryMenu->addSeparator();
	
	
				// Edit Menu //
	//newAct = new QAction(tr("&New"), this);
	//newAct->setShortcuts(QKeySequence::New);
	//newAct->setStatusTip(tr("Create a new file"));
	//connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));
	
	editMenu = menuBar()->addMenu(tr("&Edit"));
	//libraryMenu->addAction(newAct);
	//libraryMenu->addSeparator();
	
	
				// Controls Menu //
	playPauseAct = new QAction(tr("&Play/Pause"), this);
	QList<QKeySequence> TEMPLISTOFKEYSEQUENCES; TEMPLISTOFKEYSEQUENCES.append(QKeySequence(Qt::Key_Space));  // TODO:  REMOVE
	playPauseAct->setShortcuts(TEMPLISTOFKEYSEQUENCES);
	playPauseAct->setStatusTip(tr("Toggle playback"));
	connect(playPauseAct, SIGNAL(triggered()), this, SLOT(newFile()));
	
	controlsMenu = menuBar()->addMenu(tr("&Controls"));
	libraryMenu->addAction(newAct);
	//libraryMenu->addSeparator();
	
	
				// Data Menu //
	//newAct = new QAction(tr("&New"), this);
	//newAct->setShortcuts(QKeySequence::New);
	//newAct->setStatusTip(tr("Create a new file"));
	//connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));
	
	dataMenu = menuBar()->addMenu(tr("&Data"));
	//libraryMenu->addAction(newAct);
	//libraryMenu->addSeparator();
	
	
				// Options Menu //
	//newAct = new QAction(tr("&New"), this);
	//newAct->setShortcuts(QKeySequence::New);
	//newAct->setStatusTip(tr("Create a new file"));
	//connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));
	
	optionsMenu = menuBar()->addMenu(tr("&Options"));
	//libraryMenu->addAction(newAct);
	//libraryMenu->addSeparator();
	
	
				// Help Menu //
	//newAct = new QAction(tr("&New"), this);
	//newAct->setShortcuts(QKeySequence::New);
	//newAct->setStatusTip(tr("Create a new file"));
	//connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));
	
	helpMenu = menuBar()->addMenu(tr("&Help"));
	//libraryMenu->addAction(newAct);
	//libraryMenu->addSeparator();
	
	
	///////////////////
	// DOCK BUILDING //
	///////////////////
	
				// List Selector Dock //
	listSelectorDock = new QDockWidget(tr("Playback Controls"), this);
	listSelectorDock->setAllowedAreas(Qt::LeftDockWidgetArea |
									 Qt::RightDockWidgetArea);
	addDockWidget(Qt::LeftDockWidgetArea, listSelectorDock);
	
	listSelector = new QTreeWidget(listSelectorDock);
	listSelectorDock->setWidget(listSelector);
	
				// Playback Controls Grid //
				// Song Info Grid //
				// Search Layout //
				// Main Bar Dock //
	
	
	//////////////////
	// WINDOW SETUP //
	//////////////////
	setWindowTitle(tr("Nostalgia"));
	setMinimumSize(600,300);
	resize(600,300);
	
	//ui->setupUi(this);
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event) {
	
}

void MainWindow::newFile()
{
	statusBar()->showMessage(tr("Invoked <b>File|New</b>"));
	if (tableStack->currentIndex()) tableStack->setCurrentIndex(0);
	else tableStack->setCurrentIndex(1);
}

MainWindow::~MainWindow()
{
	//delete ui;
}
