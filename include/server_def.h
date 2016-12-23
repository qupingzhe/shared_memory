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
	int numberOfFiles;
	File_t files[ MAX_FILE_NUMBER+1 ];
	void addFile( File_t newFile )
	{
		files[numberOfFiles++] = newFile;
	}

};

#endif
