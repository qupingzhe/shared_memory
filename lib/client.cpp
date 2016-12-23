#include <sys/shm.h>
#include <sys/sem.h>
#include <string.h>

#include <client.h>

struct sembuf Client::semP = { 0, -1, 0 };
struct sembuf Client::semV = { 0, 1, 0 };

Client::Client( void ) : SharedMemory( 0 ) { }


Client::~Client( void )
{
	shmdt( address );
}


int Client::applyBlock( void )
{
	errorFlag = 0;
	setCommand( APPLY );
	hasNewCommand();
	if( !command->hasError ) {
		file = (File_t*)((char*)address + command->request );
	}
	else {
		errorFlag = command->hasError;
	}
	resetCommand();
	return errorFlag;
}

int Client::releaseBlock( void )
{
	errorFlag = 0;
	setCommand( RELEASE );
	hasNewCommand();
	if( !command->hasError ) {

	}
	else {
		errorFlag = command->hasError;
	}
	resetCommand();
	return errorFlag;
}


int Client::putFile( void )
{
	errorFlag = 0;
	setCommand( PUT );
	hasNewCommand();
	if( !command->hasError ) {

	}
	else {
		errorFlag = command->hasError;
	}
	resetCommand();
	return errorFlag;
}

int Client::getFile( void )
{
	errorFlag = 0;
	setCommand( GET );
	hasNewCommand();
	if( !command->hasError ) {

	}
	else {
		errorFlag = command->hasError;
	}
	resetCommand();
	return errorFlag;
}


int Client::showDirectory( void )
{
	errorFlag = 0;
	setCommand( SHOW );
	hasNewCommand();
	if( !command->hasError ) {

	}
	else {
		errorFlag = command->hasError;
	}
	resetCommand();
	return errorFlag;
}


bool Client::hasNewCommand( void )
{
	while( !(command->hasError)  && !(command->request) );
	return true;
}


void Client::setCommand( uint8_t commandType )
{
	semop( semid, &semP, 1 );
	command->pid = getpid();
	command->type = commandType;
}

void Client::resetCommand( void )
{
	memset( command, 0, sizeof(Command_t) );
	semop( semid, &semV, 1 );
}


void Client::setFileName( char* name )
{
	if( this->file != NULL ) {
		strcpy( (this->file)->name, name );
	}
}

void Client::getFileName( char* name )
{
	if( this->file != NULL ) {
		strcpy( name, (this->file)->name );
	}
}


void Client::setFileData( char* data )
{
	if( this->file != NULL ) {
		strcpy( (this->file)->data, data );
	}
}

void Client::getFileData( char* data )
{
	if( this->file != NULL ) {
		strcpy( data, (this->file)->data );
	}
}


void Client::setFile( File_t* file )
{
	if( this->file != NULL ) {
		setFileName( file->name );
		setFileData( file->data );
	}
}

void Client::getFile( File_t* file )
{
	if( this->file != NULL ) {
		getFileName( file->name );
		getFileData( file->data );
	}
}

