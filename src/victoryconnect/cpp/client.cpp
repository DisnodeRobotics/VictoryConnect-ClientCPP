#include "client.hpp"
#include <string>
using namespace VictoryConnect;
#include "tcp_connection.hpp"
Client::Client(std::string id, std::string name){
        mId = id;
        mName = name;
}
bool Client::enableTCP(std::string serverIP, int serverPort){
    TCPConnetion* tcp = new TCPConnetion(serverIP, serverPort);
    mConnections["TCP"] = tcp;

    bool startRes = tcp->start();
    std::cout << "Start Result: " << startRes << std::endl;
    if(startRes){
        sendPacket(Packet(COMMAND,"server/register",{getId(), getName()}));
        return true;
    }

    return false;
   
}
// Until Functions
void Client::sendPacket(Packet toSend){
    sendPacket(toSend, mDefaultConnection);
}

void Client::sendPacket(Packet toSend, std::string connection){
    toSend.setProtocol(connection);
    mSendQueue.push_back(toSend);
}


// Protocol Functions
void Client::newTopic(std::string name, std::string path, std::string connection){
    Packet newTopicPacket(COMMAND, "server/new_topic", {name, path,connection});
    sendPacket(newTopicPacket);
}

void Client::setTopic(std::string path, std::string value){
    Packet setTopicPacket(SUBMIT, path, {value});
    sendPacket(setTopicPacket);
}

void Client::setTopic(std::string path, std::vector<std::string> values){
    Packet setTopicPacket(SUBMIT, path, values);
    sendPacket(setTopicPacket);
}

void Client::subscribe(std::string path, void (*cb) (Packet packet)){
    subscribeListeners[path] = cb;
    Packet subPacket(PacketType::COMMAND, "server/subscribe", {path});
    sendPacket(subPacket);
}

void Client::registerCommand(std::string path, void (*cb) (Packet packet)){
    commandListeners[path] = cb;
    Packet regPacket(PacketType::COMMAND, "server/command", {path});
    sendPacket(regPacket);
}

void Client::callCommand(std::string path, std::string value){

}

void Client::callCommand(std::string path, std::vector<std::string> values){

}

void Client::setTickRate(int tickRate){
    mTickRate = tickRate;
    Packet tickPacket(COMMAND, "server/tickrate", {std::to_string(mTickRate)});
    sendPacket(tickPacket);
}

std::string Client::getId(){
    return mId;
}

std::string Client::getName(){
    return mName;
}

int Client::getTickRate(){
    return mTickRate;
}

std::vector<Packet> Client::getSendQueue(){
    return mSendQueue;
}

int Client::getSendQueueLength(){
    return mSendQueue.size();
}

bool Client::verifySubscribeListener(std::string path){
    if(subscribeListeners[path]){
        return true;
    }

    return false;
}

bool Client::verifyCommandListener(std::string path){
    if(commandListeners[path]){
        return true;
    }

    return false;
}
