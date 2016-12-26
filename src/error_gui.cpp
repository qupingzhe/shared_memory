#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

#include "shared_memory_def.h"

#include "error_gui.h"

ErrorDialog::ErrorDialog( QWidget* parent )
	:QDialog( parent )
{
	label = new QLabel( "error" );
	button = new QPushButton( "OK" );

	QVBoxLayout* layout = new QVBoxLayout;
	layout->addWidget( label );
	layout->addWidget( button );

	setLayout( layout );

	connect( button, SIGNAL(clicked()), this, SLOT(close()) );

	setWindowTitle( "ERROR" );

}

ErrorDialog::~ErrorDialog( void )
{
	delete label;
	delete button;
}

void ErrorDialog::setError( int type )
{
	QString a("error_");
	a += QString("%1").arg(type);
	a += QString(":");
	a += QString(errorDescription[type]);
	label->setText( a );

	show();
	raise();
}
