#ifndef _VC_PACKET_HEADER__
#define _VC_PACKET_HEADER__

#include <string>
#include <vector>
#include "packet_type.hpp"

class Packet{
    private:
        PacketType mPacketType = COMMAND;
        std::string mPath;
        std::vector<std::string> mData;
      //  std::string mProtocol = "DEFAULT";
        std::string mRaw = "";
    public:
        Packet(PacketType type, std::string path);
        Packet(PacketType type, std::string path, std::vector<std::string> data);
        
        void addData(std::string dataToAdd);
        void setProtocol(std::string protocol);
        void setRaw(std::string raw);
        void setPath(std::string path);
        void setType(PacketType type);

        // Get Methods
        std::string getString(); 
        std::string getRaw();
        std::string getProtocol();
        std::string getPath();
        std::vector<std::string> getData();
        PacketType getType();
};

#endif