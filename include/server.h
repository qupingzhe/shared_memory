#ifndef SERVER_H
#define SERVER_H

#include <unistd.h>
#include <sys/types.h>
#include <stdint.h>

#include "shared_memory.h"

struct Block_t
{
	pid_t owner;
	struct File_t file;
};

struct Directory_t
{
	int numberOfFiles;
	File_t files[ MAX_FILE_NUMBER+1 ];
	void addFile( File_t newFile )
	{
		files[numberOfFiles++] = newFile;
	}

};

class Server : public SharedMemory
{
public:
	static size_t size;
	static struct sembuf semZ;
	static struct sembuf semV;
	static struct sembuf semP;

	Server( int shmidDirectory, int semidDirectory );
	~Server( void );

	int applyBlock( void );
	int releaseBlock( void );

	int getFile( void );
	int putFile( void );

	int showDirectory( void );

	bool hasNewCommand( void );
	bool hasOldCommand( void );

private:
	struct Directory_t* directory;
	struct Block_t* blocks[MAX_BLOCK_NUMBER];

	int findBlock( pid_t owner );
	void copyFile( char* destination, char* source );

	int semidDirectory;
};

#endif
