#ifndef CLIENT_H
#define CLIENT_H

class Client
{
public:
	Clinet();
	~Client( void );
	void applyBlock( void );
	void releaseBlock( void );
	void setCommand( uint8_t commandType );

private:
	int shmid;
	int semid;
	void* address;

	struct File_t* file;
	struct Command_t* command;

	const struct sembuf semP = { 0,-1,0 };
	const struct sembuf semV = { 0,1,0 };


};

#endif
