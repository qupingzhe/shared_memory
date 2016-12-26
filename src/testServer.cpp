#include <stdio.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/sem.h>

#include "server.h"
#include "manager.h"

char input[20];
File_t file;

union semun
{
	int val;
	struct semid_ds* buf;
	unsigned short* array;
};

int main()
{
	int shmid = shmget( 0x1818, sizeof(Directory_t), IPC_CREAT|0700 );
	int semid = semget( 0x1819, 1, IPC_CREAT|0700 );

	semun arg;
	arg.val = 1;
	semctl( semid, 0, SETVAL, arg );

	pid_t pid = 0;
	if( (pid = fork()) > 0 ) {
		Manager manager( shmid, semid );
		while( scanf( "%s", input ) != EOF ) {
			if( !strcmp( input, "show" ) ) {
				manager.showAll();
			}
			else if( !strcmp( input, "delete" ) ) {
				scanf( "%s", file.name );
				manager.deleteFile( file.name );
			}
			else if( !strcmp( input, "add" ) ) {
				scanf( "%s%s",file.name, file.data );
				manager.addFile( file );
			}
			else if( !strcmp( input, "quit" ) ) {
			}
			else {
			}
		}
	}

	else if( pid == 0 ) {
		Server server( shmid, semid );
		while( server.hasNewCommand() ) {
			switch( server.getCommandType() ) {
				case APPLY:
					server.applyBlock();
					break;
				case RELEASE:
					server.releaseBlock();
					break;
				case GET:
					server.getFile();
					break;
				case PUT:
					server.putFile();
					break;
				case SHOW:
					server.showDirectory();
					break;
				default:
					break;
			}
		}
	}
	else {
		fprintf( stderr, "Error_Fork\n" );
	}
	shmctl( shmid, IPC_RMID, NULL );
	semctl( semid, 0, IPC_RMID );
	return 0;
}
