#include <sys/shm.h>
#include <sys/sem.h>
#include <stdio.h>
#include <string.h>

#include "manager.h"

sembuf Manager::semP = { 0, -1, 0 };
sembuf Manager::semV = { 0, 1, 0 };

Manager::Manager( int shmid, int semid )
{
	this->semid = semid;
	directory = (Directory_t*)shmat( shmid, NULL, 0 );

	semop( semid, &semP, 1 );
	memset( directory, 0, sizeof(Directory_t) );
	semop( semid, &semV, 1 );
}

Manager::~Manager( void )
{
	shmdt( directory );
}

void Manager::showAll( void )
{
	semop( semid, &semP, 1 );
	for( int i=0; i<directory->numberOfFiles; i++ ) {
		printf( "START====================\n" );
		printf( "FileName: %s\n",(directory->files[i]).name );
		printf( "------------------------\n" );
		printf( "%s\n",(directory->files[i]).data );
		printf( "\n" );
		printf( "END=====================\n" );
	}
	semop( semid, &semV, 1 );
}

void Manager::deleteFile( char* name )
{
	semop( semid, &semP, 1 );
	for( int i=0; i<directory->numberOfFiles; i++ ) {
		if( !strcmp( (directory->files[i]).name, name ) ) {
			for( int j=i+1; j<directory->numberOfFiles; j++ ) {
				strcpy( (directory->files[j-1]).name, 
						(directory->files[j]).name );
				strcpy( (directory->files[j-1]).data, 
						(directory->files[j]).data );
			}
			directory->numberOfFiles--;
			i--;
		}
	}
	semop( semid, &semV, 1 );
}

void Manager::addFile( File_t file )
{
	semop( semid, &semP, 1 );
	directory->addFile( file );
	semop( semid, &semV, 1 );
}



