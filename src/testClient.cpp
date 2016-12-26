#include <stdio.h>
#include <string.h>

#include "client.h"

char cmd[20];
char name[11];
char data[1000];
int main()
{
	Client client;
	uint8_t errorFlag = 0;
	while( scanf("%s", cmd ) != EOF ) {
		if( !strcmp( cmd, "apply" ) ) {
			if( (errorFlag = client.applyBlock() ) ) {
				printf( "ERROR_%d\n",errorFlag );
			}
		}
		else if( !strcmp( cmd, "release" ) ) {
			if( (errorFlag = client.releaseBlock() ) ) {
				printf( "ERROR_%d\n",errorFlag );
			}
		}
		else if( !strcmp( cmd, "get" ) ) {
			scanf("%s", name );
			client.setFileName( name );
			if( (errorFlag = client.getFile() ) ) {
				printf( "ERROR_%d\n",errorFlag );
			}
			else {
				client.getFileData( data );
				printf("%s\n",data);
			}
		}
		else if( !strcmp( cmd, "put" ) ) {
			scanf("%s", name );
			scanf("%s", data );
			client.setFileName( name );
			client.setFileData( data );
			if( (errorFlag = client.putFile() ) ) {
				printf( "ERROR_%d\n",errorFlag );
			}
		}
		else if( !strcmp( cmd, "show" ) ) {
			if( (errorFlag = client.showDirectory() ) ) {
				printf( "ERROR_%d\n",errorFlag );
			}
			else {
				client.getFileData( data );
				printf("%s",data);
			}
		}
		else {
			printf("ERROR_INPUT\n");
		}
	 }
	return 0;
}
