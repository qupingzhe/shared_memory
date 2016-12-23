#ifndef SERVER_H
#define SERVER_H

#include <unistd.h>
#include <sys/types.h>
#include <stdint.h>

#include <server_def.h>

class Server : public SharedMemory
{
public:
	static size_t size;
	static struct sembuf semZ;

	Server( void );
	~Server( void );

	int applyBlock( void );
	int releaseBlock( void );

	int getFile( void );
	int putFile( void );

	int showDirectory( void );

	bool hasNewCommand( void );
	bool hasOldCommand( void );

private:
	struct Directory_t directory;
	struct Block_t* blocks[MAX_BLOCK_NUMBER];

	int findBlock( pid_t owner );
	void copyFile( char* destination, char* source );
};

#endif
