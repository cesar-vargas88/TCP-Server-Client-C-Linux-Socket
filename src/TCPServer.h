#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>

using namespace std;

class TCPServer
{
	public:
	
	int ServerConnection;
	int ClientConnection;
	int Port; 
  
	socklen_t longc; 
	struct sockaddr_in Server;
	struct sockaddr_in Client;
	char buffer[100];

	bool Setup(int port);
	bool Connect();
	bool Listen();
};
 