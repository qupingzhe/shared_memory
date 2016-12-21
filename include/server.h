#ifndef SERVER_H
#define SERVER_H

#include <server_def.h>

class Server
{
public:
	Server();
	void applyBlock( void );
	void releaseBlock( void );
	void getFile( void );
	void putFile( void );
	void show( void );

private:
	int shmid;
	int semid;
	void* address;
	struct Directory_t directory;

	struct Command_t* command;
	struct Information* information;
	struct Block_t* blocks[MAX_BLOCKS_NUMBER];
	int numberOfBlocks;
};

#endif
