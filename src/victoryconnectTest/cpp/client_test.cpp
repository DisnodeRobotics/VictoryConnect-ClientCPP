#include "client.hpp"
#include <gtest/gtest.h>

using namespace VictoryConnect;

TEST(VCClientTest, CreateCheck){
    Client c("test-client","Test Client!");
    EXPECT_EQ(c.getName(), "Test Client!");
    EXPECT_EQ(c.getId(), "test-client");
}

TEST(VCClientTest, NewTopicCheck){
    Client c("test-client","Test Client!");
    c.newTopic("Test Topic", "test/topic", "TCP");
    EXPECT_EQ(c.getSendQueue()[0].getType(), COMMAND);
    EXPECT_EQ(c.getSendQueue()[0].getPath(), "server/new_topic");
    EXPECT_EQ(c.getSendQueue()[0].getData()[0], "Test Topic");
    EXPECT_EQ(c.getSendQueue()[0].getData()[1], "test/topic");
    EXPECT_EQ(c.getSendQueue()[0].getData()[2], "TCP");
}
TEST(VCClientTest, SetTopicSingleValueCheck){
    Client c("test-client","Test Client!");
    c.setTopic("test/topic", "test_value");
    EXPECT_EQ(c.getSendQueue()[0].getType(), SUBMIT);
    EXPECT_EQ(c.getSendQueue()[0].getPath(), "test/topic");
    EXPECT_EQ(c.getSendQueue()[0].getData()[0], "test_value");
}

TEST(VCClientTest, SetTopicMultiValueCheck){
    Client c("test-client","Test Client!");
    std::vector<std::string> testData = {"test_value", "test_value2"};
    c.setTopic("test/topic", testData);
    EXPECT_EQ(c.getSendQueue()[0].getType(), SUBMIT);
    EXPECT_EQ(c.getSendQueue()[0].getPath(), "test/topic");
    EXPECT_EQ(c.getSendQueue()[0].getData()[0], "test_value");
    EXPECT_EQ(c.getSendQueue()[0].getData()[1], "test_value2");
}

TEST(VCClientTest, TickCheck){
    Client c("test-client","Test Client!");
    c.setTickRate(10);
    EXPECT_EQ(c.getTickRate(), 10);
    EXPECT_EQ(c.getSendQueue()[0].getType(), COMMAND);
    EXPECT_EQ(c.getSendQueue()[0].getPath(), "server/tickrate");
    EXPECT_EQ(c.getSendQueue()[0].getData()[0], "10");
}

TEST(VCClientTest, SendQueueCheck){
    Client c("test-client","Test Client!");
    Packet p(COMMAND, "test/path1", {"test_data"});
    Packet p2(SUBMIT, "test/path2", {"test_data"});
    c.sendPacket(p);
    EXPECT_EQ(c.getSendQueueLength(), 1);
    EXPECT_EQ(c.getSendQueue()[0].getType(), COMMAND);
    EXPECT_EQ(c.getSendQueue()[0].getPath(), "test/path1");
    EXPECT_EQ(c.getSendQueue()[0].getData()[0], "test_data");
    c.sendPacket(p2);
    EXPECT_EQ(c.getSendQueueLength(), 2);
    EXPECT_EQ(c.getSendQueue()[1].getType(), SUBMIT);
    EXPECT_EQ(c.getSendQueue()[1].getPath(), "test/path2");
    EXPECT_EQ(c.getSendQueue()[1].getData()[0], "test_data");
}

TEST(VCClientTest, RegisterCheck){
    Client c("test-client","Test Client!");
    c.registerCommand("test/path",[](Packet packet) -> void {
        
    });
    EXPECT_EQ(c.verifyCommandListener("test/path"), true);
    EXPECT_EQ(c.getSendQueue()[0].getPath(), "server/command");
    EXPECT_EQ(c.getSendQueue()[0].getData()[0], "test/path");
}

TEST(VCClientTest, SubscribeCheck){
    Client c("test-client","Test Client!");
    c.subscribe("test/path",[](Packet packet) -> void {
        
    });
    EXPECT_EQ(c.verifySubscribeListener("test/path"), true);
    EXPECT_EQ(c.getSendQueue()[0].getType(), COMMAND);
    EXPECT_EQ(c.getSendQueue()[0].getPath(), "server/subscribe");
    EXPECT_EQ(c.getSendQueue()[0].getData()[0], "test/path");
}
