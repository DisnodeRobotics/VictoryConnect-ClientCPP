#include <iostream>  
#include "victoryconnect.h"
int main(int argc, char** argv) {
    VictoryConnect::Client* client = new VictoryConnect::Client("test-id","Test");
    std::cout<<"----- VictoryConnect Test Client Info -----" << std::endl;
    std::cout<<"Client ID: \t" << client->getId()<<std::endl;
    std::cout<<"Client Name: \t" << client->getName()<<std::endl;

    client->subscribe("test/path", [](Packet packet) -> void {
        std::cout << "\t Packet: \t " << packet.getPath() << std::endl;
    });

    

    return 0;
}