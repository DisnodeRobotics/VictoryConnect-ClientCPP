#ifndef _VC_PACKET_HEADER__
#define _VC_PACKET_HEADER__

#include <string>
#include "packet_type.hpp"

class Packet{
    private:
        PacketType mPacketType = COMMAND;
    public:
        Packet(PacketType type);
        PacketType getType();
};

#endif