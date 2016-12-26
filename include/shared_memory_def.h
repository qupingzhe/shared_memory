#ifndef SHARED_MEMORY_DEF_H
#define SHARED_MEMORY_DEF_H

const key_t SHM_KEY = 0x18;
const key_t SEM_KEY = 0x19;

const int MAX_NAME_LENGTH = 10;
const int MAX_FILE_SIZE = 1000;
const int MAX_FILE_NUMBER = 10;
const int MAX_BLOCK_NUMBER = 4;

enum Error
{
	NO_PID = 1,
	NO_FREE_BLOCK = 2,
	NO_FILE = 3,
	NO_DIR = 4,
	HAS_BLOCK = 5,
	NO_BLOCK = 6,
	DATA_TOO_LONG = 7,
	NO_NAME = 8,
	NO_DATA = 9
};

const char errorDescription[][50] = {
	"NULL",
	"Your pid is error",
	"Don't have free block,please wait a moment",
	"Don't have this file name ",
	"The directory is fulled",
	"You have applyed a block",
	"You don't have a block",
	"Your file data is too long",
	"Please input file name",
	"Please input file data"
};

enum CommantType
{
	APPLY = 1,
	RELEASE = 2,
	GET = 4,
	PUT = 8,
	SHOW = 16
};

struct File_t
{
	char name[MAX_NAME_LENGTH+1];
	char data[ MAX_FILE_SIZE ];
};

#endif
