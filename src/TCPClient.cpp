#include "TCPClient.h"

bool TCPClient::Setup(char *server, int port)
{
	Port = port;
	
	Server = gethostbyname(server);
	
	if(Server == NULL)
	{
		cout << "Error host" << endl;
		return false;
	}
	
	// Create socket
	Connection = socket(AF_INET, SOCK_STREAM, 0);
	// Fill struct with 0´s
	bzero((char *)&Client, sizeof((char *)&Client)); //Rellena toda la estructura de 0's  
    // Setup Server struct
	Client.sin_family = AF_INET;
	Client.sin_port = htons(Port);
	bcopy((char *)Server->h_addr, (char *)&Client.sin_addr.s_addr, sizeof(Server->h_length));

	return true;
}

bool TCPClient::Connect()
{
	// Connecting with the host
	if(connect(Connection, (struct sockaddr *)&Client, sizeof(Client)) < 0)
	{ 
		cout << "Error connecting to the host" << endl;
		close(Connection);
		return false;
	}
	
	cout << "Connected with " << inet_ntoa(Client.sin_addr) << " : " << htons(Client.sin_port) << endl;
	
	return true;
}

bool TCPClient::Write()
{
	cout << "Write a message: " << endl;
	fgets(buffer, 100, stdin);
	send(Connection, buffer, 100, 0);
	
	return true;
}

bool TCPClient::Listen()
{
	bzero(buffer, 100);
	recv(Connection, buffer, 100, 0);
	cout << buffer << endl;
	
	return true;
}
