#include <QApplication>
#include "client_gui.h"

int main( int argc, char** argv )
{
	QApplication app( argc, argv );
	ClientMainWindow* clientMainWindow = new ClientMainWindow();
	clientMainWindow->show();
	return app.exec();
}

