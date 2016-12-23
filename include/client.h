#ifndef CLIENT_H
#define CLIENT_H

#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>

#include <shared_memory.h>

class Client : public SharedMemory
{
public:
	static struct sembuf semP;
	static struct sembuf semV;

	Client();
	~Client( void );

	int applyBlock( void );
	int releaseBlock( void );

	int putFile( void );
	int getFile( void );

	int showDirectory( void );

	bool hasNewCommand( void );

	void setCommand( uint8_t commandType );
	void resetCommand( void );

	void setFileName( char* name );
	void getFileName( char* name );

	void setFileData( char* data );
	void getFileData( char* data );

	void setFile( File_t* file );
	void getFile( File_t* file );

private:

	struct File_t* file;
};

#endif
