#include <sys/shm.h>
#include <sys/sem.h>
#include <string.h>
#include "client.h"

#include <stdio.h>

struct sembuf Client::semP = { 0, -1, 0 };
struct sembuf Client::semV = { 0, 1, 0 };

Client::Client( void ) 
{
	semid = semget( SEM_KEY, 1,  IPC_CREAT|0777 );
	shmid = shmget( SHM_KEY, 0, IPC_CREAT|0777 );
	if( semid < 0 ) {
		printf("SEM\n");
	}
	if( shmid < 0 ) {
		printf("SHM\n");
	}
	address = shmat( shmid, NULL, 0 );

	command = (Command_t*)address;
}

Client::~Client( void )
{
	shmdt( address );
}


void Client::applyBlock( void )
{
	setCommand( APPLY );
	waitNewCommand();
	file = (File_t*)((char*)address + command->request );
	resetCommand();
}

void Client::releaseBlock( void )
{
	setCommand( RELEASE );
	waitNewCommand();

	resetCommand();
}


void Client::putFile( void )
{
	setCommand( PUT );
	waitNewCommand();
	resetCommand();
}

void Client::getFile( void )
{
	setCommand( GET );
	waitNewCommand();
	resetCommand();
}


void Client::showDirectory( void )
{
	setCommand( SHOW );
	waitNewCommand();
	resetCommand();
}


uint8_t Client::getCommandType( void )
{
	return command->type;
}

bool Client::waitNewCommand( void )
{
	while( !(command->hasError)  && !(command->request) )
	{
	}
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

