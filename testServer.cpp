#include "server.h"
#include <stdio.h>

int main()
{
	Server server;
	while( server.hasNewCommand() ) {
		switch( server.getCommandType() ) {
			case APPLY:
				server.applyBlock();
				break;
			case RELEASE:
				server.releaseBlock();
				break;
			case GET:
				server.getFile();
				break;
			case PUT:
				server.putFile();
				break;
			case SHOW:
				server.showDirectory();
				break;
			default:
				break;
		}
		printf("END---------\n");
	}
	return 0;
}
