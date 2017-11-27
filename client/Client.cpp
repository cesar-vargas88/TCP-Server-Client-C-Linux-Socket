#include "TCPClient.h"

TCPClient Client;

int main(int argc, char **argv)
{
	if(argc<2)
	{
		printf("<host> <puerto>\n");
		return 1;
	}
	
	if(Client.Setup(argv[1], atoi(argv[2])))
	{
		if(Client.Connect())
		{
			if(Client.Write())
			{
				if(!Client.Listen())
					return 1;
			}
			else	
				return 1;
		}
		else 
			return 1;
	}
	else
		return 1;

	return 0;
}