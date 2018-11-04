#ifndef _VC_PACKET_PARSER_HEADER__
#define _VC_PACKET_PARSER_HEADER__

#include "packet.hpp"

class PacketParser{
    public:
    static Packet parse(std::string);
};

#endif