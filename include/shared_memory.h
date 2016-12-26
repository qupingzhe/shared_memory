#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

#include "shared_memory_def.h"

struct Command_t
{
	uint8_t type;
	pid_t pid;
	uint8_t hasError;
	int request;
};

struct Information_t
{
	short sizeOfBlocks;
};

class SharedMemory
{
public:
	SharedMemory( int size );
	virtual ~SharedMemory( void );
	virtual int applyBlock( void )=0;
	virtual int releaseBlock( void )=0;

	virtual int putFile( void )=0;
	virtual int getFile( void )=0;

	virtual int showDirectory( void )=0;

	virtual bool hasNewCommand( void )=0;

	uint8_t getCommandType( void );
	Information_t getInformation( void );
protected:
	int shmid;
	int semid;
	void* address;
	struct Command_t* command;
	struct Information_t* information;
	uint8_t errorFlag;
};

#endif
