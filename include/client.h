#ifndef CLIENT_H
#define CLIENT_H

#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include "shared_memory.h"

class Client
{
public:
	static struct sembuf semP;
	static struct sembuf semV;

	Client();
	~Client( void );

	void applyBlock( void );
	void releaseBlock( void );

	void putFile( void );
	void getFile( void );

	void showDirectory( void );

	uint8_t getCommandType( void );
	bool waitNewCommand( void );

	void setCommand( uint8_t commandType );
	void resetCommand( void );

	void setFileName( char* name );
	void getFileName( char* name );

	void setFileData( char* data );
	void getFileData( char* data );

	void setFile( File_t* file );
	void getFile( File_t* file );

private:
	int shmid;
	int semid;
	void* address;

	struct File_t* file;
	struct Command_t* command;
};

#endif
