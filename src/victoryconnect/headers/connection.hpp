#ifndef _VC_CONNECTION_HEADER__
#define _VC_CONNECTION_HEADER__
#include <vector>
#include <string>
#include <iostream>
namespace VictoryConnect{
    class Connection{
        protected:
            std::string mServerIP;
            int         mServerPort;
            
        public:
            Connection(std::string ip, int port);
            
            void setServerInfo(std::string ip, int port);

            bool start();

            virtual bool sendString(std::string toSend){
                std::cout << "Default sendString. Override this" << std::endl;
            }

            //Get Functions
            std::string getServerIP();
            int getServerPort();
            
    };
}
#endif
