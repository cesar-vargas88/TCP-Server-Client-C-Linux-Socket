#include "TCPServer.h"

TCPServer Server;

int main(int argc, char **argv)
{
	if(argc<2)
	{
		cout << argv[0] << " port" << endl;
		return 1;
	}
  
	if(Server.Setup(atoi(argv[1])))
	{
		if(Server.Connect())
		{
			if(!Server.Listen())
				return 1;
		}
		else
			return 1;
	}
	else
		return 1;
	
	return 0;
}