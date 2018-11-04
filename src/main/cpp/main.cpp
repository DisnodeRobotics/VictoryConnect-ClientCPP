#include <iostream>  
#include "packet.hpp"

int main(int argc, char** argv) {
    Packet testpacket(PacketType::COMMAND,"test");
    std::cout << testpacket.getType() << std::endl;
    return 0;
}