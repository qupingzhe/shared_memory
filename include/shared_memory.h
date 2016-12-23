#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

const key_t SHM_KEY = 0x18;
const key_t SEM_KEY = 0x19;

const int MAX_NAME_LENGTH = 10;
const int MAX_FILE_SIZE = 1000;
const int MAX_FILE_NUMBER = 10;
const int MAX_BLOCK_NUMBER = 4;

enum Error
{
	NO_PID = 1,
	NO_BLOCK = 2,
	NO_FILE = 3,
	NO_DIR = 4
};

enum CommantType
{
	APPLY = 1,
	RELEASE = 2,
	GET = 4,
	PUT = 8,
	SHOW = 16
};

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

struct File_t
{
	char name[MAX_NAME_LENGTH+1];
	char data[ MAX_FILE_SIZE ];
};

class SharedMemory
{
public:
	SharedMemory( int size );
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
