#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netdb.h>

using namespace std;

class TCPClient
{
	public:

	int Connection;
	int Port; 

	struct sockaddr_in 	Client;
	struct hostent 		*Server;
	char buffer[100];
	
	bool Setup(char* server, int port);
	bool Connect();
	bool Write();
	bool Listen();
};