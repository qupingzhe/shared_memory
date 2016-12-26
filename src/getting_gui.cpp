#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <stdint.h>
#include <string.h>

#include "client.h"
#include "shared_memory_def.h"
#include "error_gui.h"

#include "getting_gui.h"

GettingDialog::GettingDialog( File_t* file, QWidget* parent )
	: QDialog( parent )
{
	this->file = file;

	label = new QLabel("File name:");
	edit = new QLineEdit;
	okButton = new QPushButton("OK");
	closeButton = new QPushButton( "close" );

	errorDialog = new ErrorDialog( parent );

	connect( okButton, SIGNAL(clicked()),
			this, SLOT(check()) );
	connect( closeButton, SIGNAL(clicked()),
			this, SLOT(close()) );

	QHBoxLayout* layout = new QHBoxLayout;
	layout->addWidget( label );
	layout->addWidget( edit );
	layout->addWidget( okButton );
	layout->addWidget( closeButton );
	setLayout( layout );

	edit->setMaxLength( MAX_NAME_LENGTH );
	setWindowTitle( "GETTING" );
}

GettingDialog::~GettingDialog( void )
{
	delete label;
	delete edit;
	delete okButton;
	delete closeButton;
	delete errorDialog;
	file = NULL;
}

//void GettingDialog::finishInput( void ) { }

void GettingDialog::openDialog( void )
{
	edit->setText("");
	show();
	raise();
}

void GettingDialog::check( void )
{
	QByteArray tmp = (edit->text()).toAscii();
	strcpy( file->name, tmp.data() );
	if( strlen( file->name ) > 0 ) {
		finishInput();
		close();
	}
	else {
		errorDialog->setError( NO_NAME );
	}
}

