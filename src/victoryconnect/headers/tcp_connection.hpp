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
#include <thread>
namespace VictoryConnect{
    class TCPConnetion : public Connection{
        private:
            int mSock = -1;
            struct sockaddr_in mServer;

            std::thread* mRecvTread;

            void startListening();
            void revieveLoop();
            void onRecieve(std::string data);
        public:
            TCPConnetion(std::string ip, int port)
            : Connection(ip, port) {}
            
            bool start();
            bool sendString (std::string toSend);
            

            ~TCPConnetion();
    };
}
#endif
