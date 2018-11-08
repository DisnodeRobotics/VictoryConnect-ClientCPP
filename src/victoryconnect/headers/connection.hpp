#ifndef _VC_CONNECTION_HEADER__
#define _VC_CONNECTION_HEADER__
#include <vector>
#include <string>
#include "client.hpp"
namespace VictoryConnect{
    class Connection{
        private:
            Client* mParent;
            std::string mServerIP;
            int         mServerPort;
        public:
            Connection(std::string ip, int port, Client* client);
            
            void setServerInfo(std::string ip, int port);

            bool connect();

            //Get Functions
            std::string getServerIP();
            int getServerPort();
            
    };
}
#endif
