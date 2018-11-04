#include "packet.hpp"

Packet::Packet(PacketType type){
    mPacketType = type;
}

PacketType Packet::getType(){
    return mPacketType;
}