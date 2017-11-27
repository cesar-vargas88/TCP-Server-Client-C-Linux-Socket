#include "TCPServer.h"

bool TCPServer::Setup(int port)
{
	Port = port;
	// Create socket
	ServerConnection = socket(AF_INET, SOCK_STREAM, 0); 
	// Fill struct with 0´s 
	bzero((char *)&Server, sizeof(Server)); 
	// Setup Server struct
	Server.sin_family = AF_INET; 
	Server.sin_port = htons(Port);
	Server.sin_addr.s_addr = INADDR_ANY; 
  
	// Assign a socket to the port
	if(bind(ServerConnection, (struct sockaddr *)&Server, sizeof(Server)) < 0)
	{
		cout << "Failed to associate the port with the connection" << endl;
		close(ServerConnection);
		return false;
	}
	
	return true;
}

bool TCPServer::Connect()
{
	// Start listening
	listen(ServerConnection, 3); 
	cout << "Listening to the port " << ntohs(Server.sin_port) << endl;
	longc = sizeof(Client); 
	
	// Wait the connection
	ClientConnection = accept(ServerConnection, (struct sockaddr *)&Client, &longc); 
  
	if(ClientConnection < 0)
	{
		cout << "Error accepting traffic" << endl;
		close(ServerConnection);
		return false;
	}
	
	cout << "Connecting with " << inet_ntoa(Client.sin_addr) << " : " << htons(Client.sin_port) << endl; 
	
	return true;
}

bool TCPServer::Listen()
{
	if(recv(ClientConnection, buffer, 100, 0) < 0)
	{ 
		// We started receiving Client data
		// If recv() receives 0 the Client has closed the connection
		// If it is less than 0 there has been some error
		cout << "Error receiving data" << endl;
		close(ServerConnection);
		return false;
	}
	else
	{
		cout << buffer << endl;
		bzero((char *)&buffer, sizeof(buffer));
		send(ClientConnection, "Received\n", 13, 0);
	}
	
	close(ServerConnection);
	
	return true;
}
