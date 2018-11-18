#include "tcp_connection.hpp"

using namespace VictoryConnect;
using namespace std;

bool TCPConnetion::start()
{
	if (mSock == -1)
	{
		mSock = socket(AF_INET, SOCK_STREAM, 0);
		if (mSock == -1)
		{
			cout << "Could not create socket" << endl;
			return false;
		}
	}
	if (inet_addr(mServerIP.c_str()) == -1)
	{
		struct hostent *he;
		struct in_addr **addr_list;
		if ((he = gethostbyname(mServerIP.c_str())) == NULL)
		{
			//herror("gethostbyname");
			std::cout << "Failed to resolve hostname\n";
			return false;
		}
		addr_list = (struct in_addr **)he->h_addr_list;
		for (int i = 0; addr_list[i] != NULL; i++)
		{
			mServer.sin_addr = *addr_list[i];
			break;
		}
	}
	else
	{
		mServer.sin_addr.s_addr = inet_addr(mServerIP.c_str());
	}
	mServer.sin_family = AF_INET;
	mServer.sin_port = htons(mServerPort);
	int result =  connect(mSock, (struct sockaddr *)&mServer, sizeof(mServer)) < 0;
	if (result != 0)
	{
		cout << "LOL WUT" << endl;
		perror("connect failed. Error");
		return false;
	}

	return true;
}

bool TCPConnetion::sendString(string toSend)
{
	if (mSock != -1)
	{
		if (send(mSock, toSend.c_str(), strlen(toSend.c_str()), 0) < 0)
		{
			cout << "Send failed : " << toSend << endl;
			return false;
		}
	}
	else
		cout << "Socket Null. Not sending" << endl;
		return false;
	std::cout << "Sent Packet: " << toSend << std::endl;
	return true;
}