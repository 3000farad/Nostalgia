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
