#include "packet_parser.hpp"
#include "utils.hpp"

using namespace VictoryConnect;

Packet PacketParser::parse(std::string rawString){

    std::vector<std::string> strSegments;
    std::vector<std::string> strDataArr;

    std::string strType;
    std::string strPath;
    std::string strFullData;

    strSegments = Utils::strSplit(rawString, " ");

    strType = strSegments[0];
    strPath = strSegments[1];
    
    int startDataIndex = rawString.find("{",0) + 1;
    int endDataIndex   = rawString.find("}",0);

    strFullData = rawString.substr(startDataIndex, endDataIndex-startDataIndex);
    strDataArr  = Utils::strSplit(strFullData, ";");

    strDataArr.pop_back();
    Packet p(COMMAND,strPath, strDataArr);

    return p;
}