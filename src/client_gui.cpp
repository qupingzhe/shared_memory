#include <QPushButton>
#include <QTextBrowser>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "success_gui.h"
#include "error_gui.h"
#include "putting_gui.h"
#include "getting_gui.h"
#include "client.h"

#include "client_gui.h"

ClientMainWindow::ClientMainWindow( void )
{
	initiate();
	initiateConnection();
	initiateLayout();

}

void ClientMainWindow::initiate( void )
{
	mainWidget = new QWidget();

	applyingBlockButton = new QPushButton( "apply" );
	releasingBlockButton = new QPushButton( "release" );

	gettingFileButton = new QPushButton( "getFile" );
	puttingFileButton = new QPushButton( "putFile" );

	showingDirectoryButton = new QPushButton( "showDirectory" );

	textEdit = new QTextEdit();
	textEdit->setEnabled( false );

	client = new Client();
	file = new File_t();
	successDialog = new SuccessDialog( this );
	errorDialog = new ErrorDialog( this );
	gettingDialog = new GettingDialog( file, this );
	puttingDialog = new PuttingDialog( file, this );

}

void ClientMainWindow::initiateConnection( void )
{
	connect( applyingBlockButton, SIGNAL(clicked()),
			this, SLOT(applyBlock()) );
	connect( releasingBlockButton, SIGNAL(clicked()),
			this, SLOT(releaseBlock()) );
	connect( showingDirectoryButton, SIGNAL(clicked()),
			this, SLOT(showDirectory()) );

	connect( gettingFileButton, SIGNAL(clicked()),
			gettingDialog, SLOT(openDialog()) );
	connect( gettingDialog, SIGNAL(finishInput()),
			this, SLOT(getFile()) );

	connect( puttingFileButton, SIGNAL(clicked()),
			puttingDialog, SLOT(openDialog()) );
	connect( puttingDialog, SIGNAL(finishInput()),
			this, SLOT(putFile()) );
}

void ClientMainWindow::initiateLayout( void )
{
	QVBoxLayout* layout1 = new QVBoxLayout();
	layout1->addWidget( applyingBlockButton );
	layout1->addWidget( releasingBlockButton );

	QVBoxLayout* layout2 = new QVBoxLayout();
	layout2->addWidget( showingDirectoryButton );

	QVBoxLayout* layout3 = new QVBoxLayout();
	layout3->addWidget( puttingFileButton );
	layout3->addWidget( gettingFileButton );

	QHBoxLayout* layout4 = new QHBoxLayout();
	layout4->addLayout( layout1 );
	layout4->addLayout( layout2 );
	layout4->addLayout( layout3 );

	QVBoxLayout* layout5 = new QVBoxLayout();
	layout5->addLayout( layout4 );
	layout5->addWidget( textEdit );

	mainWidget->setLayout( layout5 );
	setCentralWidget( mainWidget );
}

ClientMainWindow::~ClientMainWindow( void )
{
	delete applyingBlockButton;
	delete releasingBlockButton;
	delete gettingFileButton;
	delete puttingFileButton;
	delete showingDirectoryButton;
	delete textEdit;

	delete client;
	delete successDialog;
	delete errorDialog;
	delete gettingDialog;
	delete puttingDialog;

	delete mainWidget;
}

void ClientMainWindow::applyBlock( void )
{
	int errorFlag = client->applyBlock();
	if( !errorFlag ) {
		successDialog->setSuccess( APPLY );
	}
	else {
		errorDialog->setError( errorFlag );
	}
}

void ClientMainWindow::releaseBlock( void )
{
	int errorFlag = client->releaseBlock();
	if( !errorFlag ) {
		successDialog->setSuccess( RELEASE );
	}
	else {
		errorDialog->setError( errorFlag );
	}
}

void ClientMainWindow::getFile( void )
{
	client->setFile( file );
	int errorFlag = client->getFile();
	if( !errorFlag ) {
		client->getFile( file );
		textEdit->setPlainText( QString(file->data) );
		textEdit->show();
	}
	else {
		errorDialog->setError( errorFlag );
	}
}

void ClientMainWindow::putFile( void )
{
	client->setFile( file );
	int errorFlag = client->putFile();
	if( !errorFlag ) {
		//SuccessWindow( APPLY ).show();
	}
	else {
		errorDialog->setError( errorFlag );
	}
}

void ClientMainWindow::showDirectory( void )
{
	int errorFlag = client->showDirectory();
	if( !errorFlag ) {
		client->getFile( file );
		textEdit->setPlainText( QString(file->data) );
		textEdit->show();
	}
	else {
		errorDialog->setError( errorFlag );
	}
}
