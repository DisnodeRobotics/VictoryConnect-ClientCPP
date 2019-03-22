#include <iostream>  
#include "victoryconnect.hpp"

void decodePacket(char packet[]){
    char sender, recv, type, protocol;

    memcpy((char*)&sender,   packet, 1);
    memcpy((char*)&recv,     packet + 1, 1);
    memcpy((char*)&type,     packet + 2, 1);
    memcpy((char*)&protocol, packet + 3, 1);

    std::cout<<"SenderID: " << (int)sender << std::endl;
    std::cout<<"recv: " << (int)recv << std::endl;
    std::cout<<"type: " << (int)type << std::endl;
    std::cout<<"protocol: " << (int)protocol << std::endl;
    
    uint8_t pathLength;
    memcpy((char*)&pathLength, packet + 4, 1);
    std::cout<<"pathLength: " <<(int)pathLength << std::endl;

    char path[9];
    std::cout<<(int)pathLength<<std::endl;
    memcpy((char*)&path, packet + 5, 9);
   
    std::cout<<"path: " << path << std::endl;
    std::cout<<strlen(path)<<std::endl;

    
}

int main(int argc, char** argv) {
    VictoryConnect::Client* client = new VictoryConnect::Client("test-id","Test");
    std::cout<<"----- VictoryConnect Test Client Info -----" << std::endl;
    std::cout<<"Client ID: \t" << client->getId()<<std::endl;
    std::cout<<"Client Name: \t" << client->getName()<<std::endl;

    client->subscribe("test/path", [](Packet packet) -> void {
        std::cout << "\t Packet: \t " << packet.getPath() << std::endl;
    });

    client->enableTCP("127.0.0.1", 5000);

    char sender = 12;
    char recvier = 4;
    char type     = 1;
    char protocol = 4;
    char* path = "test/path";
    uint8_t path_len = strlen(path);
    char* data = "test;test;test;test";
    uint32_t data_len = strlen(data);
    
    

    char packet[1+1+1+1+path_len+data_len+1];
    
    memcpy(packet,    (char*) &sender,  1);
    memcpy(packet + 1,(char*) &recvier, 1);
    memcpy(packet + 2,(char*) &type, 1);
    memcpy(packet + 3,(char*) &protocol, 1);

    memcpy(packet + 4,(char*) &path_len, 1);
    memcpy(packet + 5, path, path_len);

    memcpy(packet + 5 + path_len + 1,(char*) &data_len, 4);
    memcpy(packet + 5 + path_len + 2, data, data_len);
    memset(packet + sizeof(packet) -1, 0x00,1);


    ////////////////////////////////////////
    decodePacket(packet);

    
    
    return 0;
}