#include <sys/shm.h>
#include <sys/sem.h>
#include <string.h>
#include <stdio.h>

#include "server.h"

size_t Server::size = sizeof(Command_t) + 
						 sizeof(Information_t) +
						 sizeof(Block_t)*MAX_BLOCK_NUMBER;
sembuf Server::semZ = { 0, 0, 0 };
sembuf Server::semP = { 0, -1, 0 };
sembuf Server::semV = { 0, 1, 0 };

Server::Server( int shmidDirectory, int semidDirectory )
	:SharedMemory( size )
{
	char* pMemory = (char*)address;
	
	pMemory += sizeof(Command_t);
	pMemory += sizeof(Information_t);

	for( int i=0; i<MAX_BLOCK_NUMBER; i++ ) {
		blocks[i] = (Block_t*)pMemory;
		pMemory += sizeof(Block_t);
	}

	this->semidDirectory = semidDirectory;

	directory = (Directory_t*)shmat( shmidDirectory, NULL, 0 );
	semop( semidDirectory, &semP, 1 );
	memset( directory, 0, sizeof(Directory_t) );
	semop( semidDirectory, &semV, 1 );

}

Server::~Server( void )
{
	shmdt( address );
	shmctl( shmid, IPC_RMID, NULL );
	semctl( semid, 0, IPC_RMID );

	shmdt( directory );
}


int Server::applyBlock( void )
{
	int ptr = -1;
	errorFlag = 0;
	if( (ptr = findBlock(0)) >= 0 ) {
		blocks[ptr]->owner = command->pid;
		command->request = (char*)( &(blocks[ptr]->file) ) - (char*)address ;
	}
	else {
		errorFlag = NO_FREE_BLOCK;
		command->hasError = NO_FREE_BLOCK;
	}
	hasOldCommand();
	return errorFlag;
}

int Server::releaseBlock( void )
{
	int ptr = -1;
	errorFlag = 0;
	if( (ptr = findBlock(command->pid) ) >= 0 ) {
		blocks[ptr]->owner = 0;
		command->request = 1;
	}
	else {
		errorFlag = NO_PID;
		command->hasError = NO_PID;
	}
	hasOldCommand();
	return errorFlag;
}


int Server::putFile( void )
{
	errorFlag = 0;
	semop( semidDirectory, &semP, 1 );
	if( directory->numberOfFiles < MAX_FILE_NUMBER ) {
		int pBlock = findBlock( command->pid );
		if( pBlock >= 0 ) {
			directory->addFile( blocks[pBlock]->file );
			command->request = 1;
		}
		else {
			errorFlag = NO_PID;
			command->hasError = NO_PID;
		}
	}
	else {
		errorFlag = NO_DIR;
		command->hasError = NO_DIR;
	}
	semop( semidDirectory, &semV, 1 );
	hasOldCommand();
	return errorFlag;
}

int Server::getFile( void )
{
	int pBlock = findBlock( command->pid );
	errorFlag = 0;
	semop( semidDirectory, &semP, 1 );
	if( pBlock >= 0 ) {
		int i = 0;
		for( i=0; i<directory->numberOfFiles; i++ ) {
			if( !strcmp( (blocks[pBlock]->file).name, (directory->files[i]).name ) ) {
			   copyFile( (blocks[pBlock]->file).data, (directory->files[i]).data );
			   break;
			}
		}

		if( i == directory->numberOfFiles ) {
			errorFlag = NO_FILE;
			command->hasError = NO_FILE;
		}
		else {
			command->request = 1;
		}
	}
	else {
		errorFlag = NO_PID;
		command->hasError = NO_PID;
	}
	semop( semidDirectory, &semV, 1 );
	hasOldCommand();
	return errorFlag;
}


int Server::showDirectory( void )
{
	int pBlock = findBlock( command->pid );
	errorFlag = 0;
	semop( semidDirectory, &semP, 1 );
	if( pBlock >= 0 ) {
		char* j = (blocks[pBlock]->file).data;
		for( int i=0; i<directory->numberOfFiles; i++ ) {
			char* pName = (directory->files[i]).name;

			while( (*j++ = *pName++) != '\0' );
			*(j-1) = '\n';
		}
		*j = '\0';
		command->request = 1;
	}
	else {
		errorFlag = NO_PID;
		command->hasError = NO_PID;
	}
	semop( semidDirectory, &semV, 1 );
	hasOldCommand();
	return errorFlag;
}


bool Server::hasNewCommand( void ) 
{
	semop( semid, &semZ, 1 );
	while( command->type == 0 ) {
		putchar( 0 );
	}
	return true;
}

bool Server::hasOldCommand( void )
{
	while( command->pid != 0 ) {
		putchar( 0 );
	}
	return false;
}


int Server::findBlock( pid_t owner )
{
	int tmp = -1;
	for( int i=0; i<MAX_BLOCK_NUMBER; i++ ) {
		if( blocks[i]->owner == owner ) {
			tmp = i;
			break;
		}
	}
	return tmp;
}

void Server::copyFile( char* destination, char* source )
{
	while( (*destination++ = *source++) != '\0' ) ;
}


