#include "client.h"

void Client::setCommand( uint8_t commandType )
{
	semop( semid, &semP, 1 );
	command->pid = getpid();
	command->type = commandType;
}

void Client::resetCommand( void )
{
	memset( command, 0, sizeof(command) );
	semop( semid, &semV, 1 );
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
	waitCommand();

	resetCommand();
}


