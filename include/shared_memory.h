#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

const int KEY = 0x18;
const int MAX_FILE_NAME = 10;
const int MAX_FILE_SIZE = 1000;
const int MAX_FILE_NUMBER = 10;

enum CommantType
{
	CONNECT,
	RELEASE,
	GET,
	PUT,
	SHOW
};

struct Command_t
{
	uint8_t type;
	pid_t pid;
	int request;
};

struct Information_t
{
	short sizeOfBlocks;
};

struct File_t
{
	short length;
	char data[ MAX_FILE_SIZE ];
};

#endif
