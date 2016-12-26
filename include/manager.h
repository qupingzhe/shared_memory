#ifndef MANAGER_H
#define MANAGER_H

#include "server.h"

class Manager
{
public:
	Manager( int shmid, int semid );
	~Manager( void );
	static sembuf semP;
	static sembuf semV;

	void showAll( void );
	void deleteFile( char* name );
	void addFile( File_t file );
private:
	int semid;
	Directory_t* directory;
};

#endif
