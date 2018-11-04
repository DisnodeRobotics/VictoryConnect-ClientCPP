#include <gtest/gtest.h>
#include "packet.hpp"
#include "utils.hpp"
TEST(VictoryConnectTest, UtilsVectorJoin){
  std::vector<std::string> testVector = {"test1", "test2", "test3"};
  std::string joined = VCUtils::vectorJoin(testVector);
  EXPECT_EQ(joined, "test1,test2,test3");
}

TEST(VictoryConnectTest, PacketClassCreateCheck) {
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

TEST(VictoryConnectTest, PacketClassStringCheck){
  std::vector<std::string> mockData = {"test1", "test2", "test3"};
  Packet p1(PacketType::COMMAND,"test/path", mockData);
  EXPECT_EQ(p1.getString(), "2 test/path {test1,test2,test3}~\n");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}