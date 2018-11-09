#include "connection.hpp"
using namespace VictoryConnect;

Connection::Connection(std::string ip, int port){
    mServerIP = ip;
    mServerPort = port;
}


void Connection::setServerInfo(std::string ip, int port){
    mServerIP   = ip;
    mServerPort = port;
}

std::string Connection::getServerIP(){
    return mServerIP;
}

int Connection::getServerPort(){
    return mServerPort;
}