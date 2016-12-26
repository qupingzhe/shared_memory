#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <stdint.h>

#include "shared_memory_def.h"

#include "success_gui.h"

SuccessDialog::SuccessDialog( QWidget* parent )
	:QDialog( parent )
{
	label = new QLabel( "" );
	button = new QPushButton( "OK" );
	
	connect( button, SIGNAL(clicked()),
			this, SLOT(close()) );

	QVBoxLayout* layout = new QVBoxLayout;
	layout->addWidget( label );
	layout->addWidget( button );
	setLayout( layout );

	setWindowTitle( "SUCCESS" );
}

SuccessDialog::~SuccessDialog( void )
{
	delete label;
	delete button;
}

void SuccessDialog::setSuccess( int type )
{
	QString* tmp;
	if( type == APPLY ) {
		tmp = new QString( "apply successfully" );
	}
	else if( type == RELEASE ) {
		tmp = new QString( "release successfully" );
	}
	else {
		tmp = new QString( "" );
	}
	label->setText( *tmp );
	show();
	raise();
}
