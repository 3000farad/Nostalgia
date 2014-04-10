#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	// TODO:  SPLASH SCREEN HERE
	
	// TODO:  OPTIONS LOADING HERE
	
	// TODO:  START AN INSTANCE OF AudioPlayer in new thread
	
	//////////////////////
	// MainWindow Setup //
	//////////////////////
	MainWindow w;
	w.show();
	
	return a.exec();
}
