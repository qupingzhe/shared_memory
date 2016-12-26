#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <string.h>

#include "shared_memory.h"

union semun
{
	int val;
	struct semid_ds* buf;
	unsigned short* array;
};

SharedMemory::SharedMemory( int size )
{
	semid = semget( SEM_KEY, 1, IPC_CREAT|0777);
	semun arg;
	arg.val = 1;
	semctl( semid, 0, SETVAL, arg );

	shmid = shmget( SHM_KEY, size, IPC_CREAT|0777 );
	address = shmat( shmid, NULL, 0 );
	if( size > 0 ) {
		memset( address, 0, size );
	}

	command = (Command_t*)address;
	information = (Information_t*)((char*)address + sizeof(Command_t) );
}

SharedMemory::~SharedMemory( void )
{
	command = NULL;
	information = NULL;
}
uint8_t SharedMemory::getCommandType( void )
{
	return command->type;
}

Information_t SharedMemory::getInformation( void )
{
	return *information;
}
