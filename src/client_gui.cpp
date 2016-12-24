#include <QPushButton>
#include <QTextBrowser>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <stdio.h>
#include "client_gui.h"
#include "error_gui.h"
#include <client.h>

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
	errorDialog = new ErrorDialog( this );
}

void ClientMainWindow::initiateConnection( void )
{
	connect( applyingBlockButton, SIGNAL(clicked()),
			this, SLOT(applyBlock()) );
	connect( releasingBlockButton, SIGNAL(clicked()),
			this, SLOT(releaseBlock()) );
	connect( gettingFileButton, SIGNAL(clicked()),
			this, SLOT(getFile()) );
	connect( puttingFileButton, SIGNAL(clicked()),
			this, SLOT(putFile()) );
	connect( showingDirectoryButton, SIGNAL(clicked()),
			this, SLOT(showDirectory()) );
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
}

void ClientMainWindow::applyBlock( void )
{
	int errorFlag = client->applyBlock();
	if( !errorFlag ) {
		//SuccessWindow( APPLY ).show();

	}
	else {
		errorDialog->setError( errorFlag );
	}
}

void ClientMainWindow::releaseBlock( void )
{
	int errorFlag = client->releaseBlock();;
	if( !errorFlag ) {

	}
	else {
		errorDialog->setError( errorFlag );
	}
}

void ClientMainWindow::getFile( void )
{
	int errorFlag = client->getFile();;
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
	int errorFlag = client->putFile();;
	if( !errorFlag ) {

	}
	else {
		errorDialog->setError( errorFlag );
	}
}

void ClientMainWindow::showDirectory( void )
{
	int errorFlag = client->showDirectory();;
	if( !errorFlag ) {
		client->getFile( file );
		textEdit->setPlainText( QString(file->data) );
		textEdit->show();
	}
	else {
		errorDialog->setError( errorFlag );
	}
}
