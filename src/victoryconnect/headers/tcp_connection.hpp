#ifndef _VC_TCPCONNECTION_HEADER__
#define _VC_TCPCONNECTION_HEADER__
#include <vector>
#include <string>
#include "client.hpp"
#include "connection.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

namespace VictoryConnect{
    class TCPConnetion : public Connection{
        private:
            int mSock;
            struct mSockAddIn server;
        public:
            bool connect();
            
    };
}
#endif
