#include <gtest/gtest.h>
#include "packet.hpp"
#include "packet_parser.hpp"
#include "utils.hpp"

using namespace VictoryConnect;

TEST(VCUtilsTest, UtilsVectorJoined){
  std::vector<std::string> testVector = {"test1", "test2", "test3"};
  std::string joined = Utils::vectorJoin(testVector, ",");
  EXPECT_EQ(joined, "test1,test2,test3");
  std::string joined2 = Utils::vectorJoin(testVector, ";");
  EXPECT_EQ(joined2, "test1;test2;test3");
}

TEST(VCUtilsTest, UtilsStringSplit){
  std::string testStr = "this is a test";
  std::vector<std::string> result = Utils::strSplit(testStr," ");
  std::vector<std::string> expected =  {"this", "is", "a", "test"};
  EXPECT_EQ(result,expected);
}

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

TEST(VCPacketParserTest, PacketParserCheck){
  std::string inputString = "2 test/path {test1;test2;test3;}~";
 
  std::vector<std::string> expectedData = {"test1", "test2", "test3"};
  Packet expectedP(COMMAND, "test/path", expectedData);
  Packet parsed = PacketParser::parse(inputString);
  EXPECT_EQ(parsed.getString(), expectedP.getString());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}