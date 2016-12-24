#include "client.h"
#include <stdio.h>

char name[11];
char data[1000];
int main()
{
	Client client;
	int cmd;
	uint8_t errorFlag = 0;
	while( scanf("%d", &cmd ) != EOF ) {
		switch(cmd) {
			case APPLY:
				if( (errorFlag = client.applyBlock() ) ) {
					printf( "ERROR_%d\n",errorFlag );
				}
				break;
			case RELEASE:
				if( (errorFlag = client.releaseBlock() ) ) {
					printf( "ERROR_%d\n",errorFlag );
				}
				break;
			case GET:
				scanf("%s", name );
				client.setFileName( name );
				if( (errorFlag = client.getFile() ) ) {
					printf( "ERROR_%d\n",errorFlag );
				}
				else {
					client.getFileData( data );
					printf("%s\n",data);
				}
				break;
			case PUT:
				scanf("%s", name );
				scanf("%s", data );
				client.setFileName( name );
				client.setFileData( data );
				if( (errorFlag = client.putFile() ) ) {
					printf( "ERROR_%d\n",errorFlag );
				}
				break;
			case SHOW:
				if( (errorFlag = client.showDirectory() ) ) {
					printf( "ERROR_%d\n",errorFlag );
				}
				else {
					client.getFileData( data );
					printf("%s",data);
				}
				break;
			default:
				printf("ERROR_INPUT\n");
				break;
		}
		printf("END---------\n");
	 }
	return 0;
}
