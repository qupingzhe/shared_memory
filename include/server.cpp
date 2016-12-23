#include <sys/shm.h>
#include <sys/sem.h>
#include <string.h>
#include "server.h"

#include <stdio.h>

union semun
{
	int val;
	struct semid_ds* buf;
	unsigned short * array;
};

Server::Server( void )
{
	semid = semget( SEM_KEY, 1,  IPC_CREAT|0777 );
	semun arg;
	arg.val = 1;
	semctl( semid, 0,SETVAL, arg );
	
	size_t size = 0;
	size += sizeof(Command_t);
	size += sizeof(Information_t);
	size += sizeof(Block_t)*MAX_BLOCK_NUMBER;
	shmid = shmget( SHM_KEY, size, IPC_CREAT|0777 );

	address = shmat( shmid, NULL, 0 );
	memset( address, 0, size );

	char* pMemory = (char*)address;
	
	pMemory += 0;

	command = (Command_t*)pMemory;
	pMemory += sizeof(Command_t);

	information = (Information_t*)pMemory;
	pMemory += sizeof(Information_t);

	for( int i=0; i<MAX_BLOCK_NUMBER; i++ ) {
		blocks[i] = (Block_t*)pMemory;
		pMemory += sizeof(Block_t);
	}
}

Server::~Server( void )
{
	shmdt( address );
	shmctl( shmid, IPC_RMID, NULL );
	semctl( semid, 0, IPC_RMID );
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

void Server::applyBlock( void )
{
	int ptr = -1;
	if( (ptr = findBlock(0)) >= 0 ) {
		blocks[ptr]->owner = command->pid;
		command->request = (char*)( &(blocks[ptr]->file) ) - (char*)address ;
	}
	else {
		command->hasError = NO_BLOCK;
	}
	while( command->pid != 0 );
}

void Server::releaseBlock( void )
{
	int ptr = -1;
	if( (ptr = findBlock(command->pid) ) >= 0 ) {
		blocks[ptr]->owner = 0;
		command->request = 1;
	}
	else {
		command->hasError = NO_PID;
	}
	while( command->pid != 0 );
}

void Server::showDirectory( void )
{
	int pBlock = findBlock( command->pid );
	if( pBlock >= 0 ) {
		char* j = (blocks[pBlock]->file).data;
		for( int i=0; i<directory.numberOfFiles; i++ ) {
			char* pName = (directory.files[i]).name;

			while( (*j++ = *pName++) != '\0' );
			*(j-1) = '\n';
		}
		*j = '\0';
		command->request = 1;
	}
	else {
		command->hasError = NO_PID;
	}

	while( command->pid != 0 );
}

void Server::putFile( void )
{
	if( directory.numberOfFiles < MAX_FILE_NUMBER ) {
		int pBlock = findBlock( command->pid );
		if( pBlock >= 0 ) {
			directory.addFile( blocks[pBlock]->file );
			command->request = 1;
			while( command->pid != 0 );
		}
		else {
			command->hasError = NO_PID;
		}
	}
	else {
		command->hasError = NO_DIR;
	}
}

void Server::getFile( void )
{
	int pBlock = findBlock( command->pid );
	if( pBlock >= 0 ) {
		int i = 0;
		for( i=0; i<directory.numberOfFiles; i++ ) {
			if( !strcmp( (blocks[pBlock]->file).name, (directory.files[i]).name ) ) {
			   copyFile( (blocks[pBlock]->file).data, (directory.files[i]).data );
			   break;
			}
		}

		if( i == directory.numberOfFiles ) {
			command->hasError = NO_FILE;
		}
		else {
			command->request = 1;
			while( command->pid != 0 );
		}
	}
	else {
		command->hasError = NO_PID;
	}
}

void Server::copyFile( char* destination, char* source )
{
	while( (*destination++ = *source++) != '\0' ) ;
}

bool Server::hasNewCommand( void ) 
{
	struct sembuf sem;
	memset( &sem, 0, sizeof(sem) );
	semop( semid, &sem, 1 );
	while( command->type == 0 ) ;
	return true;
}

int Server::getCommandType( void )
{
	return command->type;
}
