#ifndef _VC_CLIENT_HEADER__
#define _VC_CLIENT_HEADER__
#include <vector>
#include <string>
#include <map>
#include "packet.hpp"
#include "tcp_connection.hpp"
#include "connection.hpp"
namespace VictoryConnect{

    class Client{
        private: 
            //Vars
            std::string mId;   // ID of the client
            std::string mName; // Readable name of the client

            //Connection default for the client
            //This is used when a packet does not describe a protocol
            //When a connection first starts up, it will set this field to it (IE: First con started becomes the default)
            //This can be set using setDefaultConnection
            std::string mDefaultConnection = "DEFAULT";

            bool mASAP     = false; // Send packets as soon as possible (skip the tick loop)
            int mTickRate  = 50;    // standard tick rate for the client, this controls sending of packets from the queue
            bool isTicking = false; // Is the client tick loop currently runing

            //Event listeners mappings for topic paths, both for commands and stanard data types (subscribe)
            //Key: Path for the event, be it data or a command
            //Value: Function callback with the param. of Packet (packet.hpp)
            std::map<std::string, void (*) (Packet packet)> commandListeners;
            std::map<std::string, void (*) (Packet packet)> subscribeListeners; 

            // Store all active connections using the CONTYPE as a key (only one connection per type ATM)
            std::map<std::string, VictoryConnect::Connection*> mConnections; 

            // Send Queue. All packets being sent are first buffered in the queue and are sent on each tick
            // This can later be compressed to avoid duplicate packets.
            std::vector<Packet> mSendQueue;

            // Functions
            void offloadQueue();
            void onCommand();
            void onRequest();
            void onSubmit();
            void onError();
            void startTickLoop();
            void stopTickLoop();
            void onTick();
            void resetTickLoop();

        public:
            Client(std::string id, std::string name);

            bool enableUDP(std::string serverIP, int serverPort);
            bool enableTCP(std::string serverIP, int serverPort);

            void setDefaultConnection(std::string connnection);
            void setASAP(bool asap);

            void sendPacket(Packet toSend);
            void sendPacket(Packet toSend, std::string connection);

            void newTopic(std::string name, std::string path, std::string connection);
            void setTopic(std::string path, std::string value);
            void setTopic(std::string path, std::vector<std::string> values);
            void subscribe(std::string path, void (*cb) (Packet packet));
            void registerCommand(std::string path, void (*cb)(Packet packet));
            void callCommand(std::string path, std::string value);
            void callCommand(std::string path, std::vector<std::string> values);
            void setTickRate(int tickRate);

            //Get Functions
            std::string getId();
            std::string getName();
            std::string getDefaultConnection();
            bool getASAP();
            int getTickRate();
            std::vector<Packet> getSendQueue();
            int getSendQueueLength();

            bool verifySubscribeListener(std::string path);
            bool verifyCommandListener(std::string path);
    };
}
#endif