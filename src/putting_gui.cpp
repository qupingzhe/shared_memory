#include <QtGui>
#include <string.h>
#include <stdint.h>

#include "shared_memory_def.h"
#include "error_gui.h"

#include "putting_gui.h"

PuttingDialog::PuttingDialog( File_t* file, QWidget* parent )
	:QDialog( parent )
{
	this->file = file;

	label = new QLabel( "file name:" );
	nameEdit = new QLineEdit();
	dataEdit = new QTextEdit();
	okButton = new QPushButton( "OK" );
	closeButton = new QPushButton( "close" );
	errorDialog = new ErrorDialog( parent );

	connect( okButton, SIGNAL(clicked()),
			this, SLOT(check()) );
	connect( closeButton, SIGNAL(clicked()),
			this, SLOT(close()) );
	
	QHBoxLayout* topLayout = new QHBoxLayout;
	topLayout->addWidget( label );
	topLayout->addWidget( nameEdit );
	topLayout->addWidget( okButton );
	topLayout->addWidget( closeButton );

	QVBoxLayout* mainLayout = new QVBoxLayout;
	mainLayout->addLayout( topLayout );
	mainLayout->addWidget( dataEdit );

	setLayout( mainLayout );

	nameEdit->setMaxLength( MAX_NAME_LENGTH );
	setWindowTitle( "PUTTING" );
}

PuttingDialog::~PuttingDialog( void )
{
	delete label;
	delete nameEdit;
	delete dataEdit;
	delete okButton;
	delete closeButton;
	delete errorDialog;
	file = NULL;
}

void PuttingDialog::openDialog( void )
{
	nameEdit->setText("");
	dataEdit->setText("");
	show();
	raise();
}

//void PuttingDialog::finishInput( void ) { }

void PuttingDialog::check( void )
{
	QByteArray tmpName = (nameEdit->text()).toAscii();
	QByteArray tmpData = (dataEdit->toPlainText()).toAscii();

	if( tmpName.length() > 0 && tmpData.length() > 0 && tmpData.length() <= MAX_FILE_SIZE ) {

		strcpy( file->name, tmpName.data() );
		strcpy( file->data, tmpData.data() );
		finishInput();
		close();
	}
	else if( tmpName.length() == 0 ) {
		errorDialog->setError( NO_NAME );
	}
	else if( tmpData.length() == 0 ) {
		errorDialog->setError( NO_DATA );
	}
	else {
		errorDialog->setError( DATA_TOO_LONG );
	}
}

