#include "client.hpp"
#include <gtest/gtest.h>

using namespace VictoryConnect;

TEST(VCPacketTest, PacketClassCreateCheck) {
    std::vector<std::string> mockData = {"test1", "test2", "test3"};
    Packet p1(PacketType::COMMAND,"test/path", mockData);
    EXPECT_EQ(p1.getType(), PacketType::COMMAND);
    EXPECT_EQ(p1.getPath(), "test/path");
    EXPECT_EQ(p1.getData(),mockData);
    
    p1.addData("test4");
    EXPECT_EQ(p1.getData().size(), mockData.size()+1);

    p1.setRaw("raw text");
    EXPECT_EQ(p1.getRaw(), "raw text");

}

TEST(VCPacketTest, PacketClassStringCheck){
  std::vector<std::string> mockData = {"test1", "test2", "test3"};
  Packet p1(PacketType::COMMAND,"test/path", mockData);
  EXPECT_EQ(p1.getString(), "2 test/path {test1;test2;test3}~\n");
}

TEST(VCPacketTest, PacketClassProtocolCheck){
  
  Packet p1(PacketType::COMMAND,"test/path", {"TEST"});
  p1.setProtocol("TCP");
  EXPECT_EQ(p1.getProtocol(), "TCP");
  p1.setProtocol("UDP");
  EXPECT_EQ(p1.getProtocol(), "UDP");
}