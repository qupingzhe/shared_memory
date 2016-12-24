#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include "error_gui.h"

#include <stdio.h>

ErrorDialog::ErrorDialog( QWidget* parent = 0 ) : QDialog(parent)
{
	label = new QLabel( "error" );
	button = new QPushButton( "OK" );

	QVBoxLayout* layout = new QVBoxLayout;
	layout->addWidget( label );
	layout->addWidget( button );

	setLayout( layout );

	connect( button, SIGNAL(clicked()), this, SLOT(close()) );

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
	label->setText( a );

	show();
	raise();
}
