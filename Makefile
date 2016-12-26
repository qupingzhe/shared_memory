include client_gui.mk
server : src/testServer.cpp src/shared_memory.cpp src/server.cpp src/manager.cpp
	g++ -Wall -o server src/testServer.cpp src/shared_memory.cpp src/server.cpp src/manager.cpp -Iinclude
client : src/testClient.cpp src/shared_memory.cpp src/server.cpp src/manager.cpp
	g++ -Wall -o client src/testClient.cpp src/shared_memory.cpp src/client.cpp src/manager.cpp -Iinclude
