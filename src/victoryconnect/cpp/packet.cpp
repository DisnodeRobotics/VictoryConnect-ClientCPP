#include "packet.hpp"
#include "utils.hpp"
Packet::Packet(PacketType type, std::string path){
    mPacketType = type;
    mPath       = path;
}

Packet::Packet(PacketType type, std::string path, std::vector<std::string> data){
    mPacketType = type;
    mPath       = path;
    mData       = data;
}

void Packet::addData(std::string dataToAdd){
    mData.push_back(dataToAdd);
}

void Packet::setProtocol(std::string protocol){
   // mProtocol = protocol;
}

void Packet::setRaw(std::string raw){
    mRaw = raw;
}

void Packet::setPath(std::string path){
    mPath = path;
}

void Packet::setType(PacketType type){
    mPacketType = type;
}
// Get Functions
std::string Packet::getString(){
    std::string final = std::to_string(mPacketType);
    final += " " + mPath + " " + "{";
    final += VCUtils::vectorJoin(mData);
    final += "}~\n";
    return final;
}

std::string Packet::getPath(){
    return mPath;
}

std::string Packet::getRaw(){
    return mRaw;
}

std::string Packet::getProtocol(){
    return "";
    //return mProtocol;
}

std::vector<std::string> Packet::getData(){
    return mData;
}

PacketType Packet::getType(){
    return mPacketType;
}