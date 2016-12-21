#include "server.h"

int Server::findBlock( Pid_t owner )
{
	int tmp = -1;
	for( int i=0; i<MAX_BLOCKS_NUMBER; i++ ) {
		if( blocks[i]->owner == owner ) {
			tmp = i;
			break;
		}
	}
	return tmp;
}

void Server::applyBlock( void )
{
	if( numberOfBlocks > MAX_BLOCKS_NUMBER ) {
		command->hasError = true;
	}
	else {
		int ptr = -1;
		if( (ptr = findBlock(0)) >= 0 ) {
			blocks[ptr]->owner = command->pid;
			numberOfBlocks++;
			command->request = (char*)blocks[ptr] - (char*)address;
		}
		else {
			command->hasError = true;
		}
	}
}

void Server::releaseBlock( void )
{
	int ptr = -1;
	if( (ptr = findBlock(command->owner) ) >= 0 ) {
		blocks[i]->owner = 0;
		command->request = 1;
	}
	else {
		command->hasError = true;
	}
}

void Server::showDirectory( void )
{
	int pBlock = findBlock( command->pid );
	if( ptr < 0 ) {
		command->hasError = true;
		return ;
	}

	char* j = (blocks[pBlock]->file).data;
	for( int i=0; i<directory.numberOfFiles; i++ ) {
		char* pName = nameOfFile[i];

		while( j++ = pName++ );
		j++ = '\n';
	}
	j = '\0';
	blocks[pBlock]->file).length = short( j - (blocks[pBlock]->file).data );

	command->request = 1;
}



