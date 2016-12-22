#ifndef SERVER_H
#define SERVER_H

#include <unistd.h>
#include <sys/types.h>
#include <stdint.h>
#include "server_def.h"

class Server
{
public:
	Server( void );
	~Server( void );
	void applyBlock( void );
	void releaseBlock( void );
	void getFile( void );
	void putFile( void );
	void showDirectory( void );
	bool hasNewCommand( void );
	int getCommandType( void );

private:
	int shmid;
	int semid;
	void* address;
	struct Directory_t directory;

	struct Command_t* command;
	struct Information_t* information;
	struct Block_t* blocks[MAX_BLOCK_NUMBER];

	int findBlock( pid_t owner );
	void copyFile( char* destination, char* source );
};

#endif
