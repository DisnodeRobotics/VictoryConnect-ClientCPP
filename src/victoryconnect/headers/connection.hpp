#ifndef _VC_CONNECTION_HEADER__
#define _VC_CONNECTION_HEADER__
#include <vector>
#include <string>
namespace VictoryConnect{
    class Connection{
        protected:
            std::string mServerIP;
            int         mServerPort;
            
        public:
            Connection(std::string ip, int port);
            
            void setServerInfo(std::string ip, int port);

            bool start();

            bool sendString(std::string toSend);

            //Get Functions
            std::string getServerIP();
            int getServerPort();
            
    };
}
#endif
