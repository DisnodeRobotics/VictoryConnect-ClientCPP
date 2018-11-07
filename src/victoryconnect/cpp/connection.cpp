#include "connection.hpp"
using namespace VictoryConnect;

Connection::Connection(std::string ip, int port, Client* client){
    mServerIP = ip;
    mServerPort = port;
    mParent = client;
}


void Connection::setServerInfo(std::string ip, int port){
    mServerIP   = ip;
    mServerPort = port;
}