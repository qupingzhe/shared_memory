#ifndef SERVER_DEF_H
#define SERVER_DEF_H

#include <shared_memory.h>

struct Block_t
{
	pid_t owner;
	struct File_t file;
};

struct Directory_t
{
	int numaberOfFiles;
	char nameOfFiles[ MAX_FILE_NUMBER+1 ][ MAX_FILE_NAME+1 ];
};

#endif
