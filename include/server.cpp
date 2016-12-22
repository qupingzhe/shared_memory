#include <sys/shm.h>
#include <sys/sem.h>
#include <string.h>
#include "server.h"

Server::Server( void )
{
	semid = semget( SEM_KEY, 1,  IPC_CREAT|0777 );
	size_t size = 0;
	size += sizeof(Command_t);
	size += sizeof(Information_t);
	size += sizeof(Block_t)*MAX_BLOCK_NUMBER;

	shmid = shmget( SHM_KEY, size, IPC_CREAT|0777 );
	address = shmat( shmid, NULL, 0 );

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
		command->request = (char*)blocks[ptr] - (char*)address;
		command->type = 0;
	}
	else {
		command->hasError = true;
	}
}

void Server::releaseBlock( void )
{
	int ptr = -1;
	if( (ptr = findBlock(command->pid) ) >= 0 ) {
		blocks[ptr]->owner = 0;
		command->request = 1;
		command->type = 0;
	}
	else {
		command->hasError = true;
	}
}

void Server::showDirectory( void )
{
	int pBlock = findBlock( command->pid );
	if( pBlock < 0 ) {
		command->hasError = true;
		return ;
	}

	char* j = (blocks[pBlock]->file).data;
	for( int i=0; i<directory.numberOfFiles; i++ ) {
		char* pName = (directory.files[i]).name;

		while( (*j++ = *pName++) != '\0' );
		*j++ = '\n';
	}
	*j = '\0';
	command->request = 1;
	command->type = 0;
}

void Server::putFile( void )
{
	if( directory.numberOfFiles >= MAX_FILE_NUMBER ) {
		command->hasError = true;
	}
	else {
		int pBlock = findBlock( command->pid );
		if( pBlock >= 0 ) {
			directory.addFile( blocks[pBlock]->file );
		}
		else {
			command->hasError = true;
		}
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
			command->hasError = true;
		}
		else {
			command->request = 1;
		}
	}
	else {
		command->hasError = true;
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
	while( command->type != 0 ) ;
	return true;
}

int Server::getCommandType( void )
{
	return command->type;
}
