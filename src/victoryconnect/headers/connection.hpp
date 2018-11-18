#ifndef _VC_CONNECTION_HEADER__
#define _VC_CONNECTION_HEADER__
#include <vector>
#include <string>
#include <iostream>
namespace VictoryConnect{
    class Connection{
        protected:
            // Server information
            // TODO: Change this to allow for protocols that don't use IP/PORT. EX: Bluetooth or GPIO
            //       This can possibly take the form of a key/value pair.
            std::string mServerIP;
            int         mServerPort;
            
        public:
            //Constructor of default IP/PORT settings
            Connection(std::string ip, int port);
            
            //Update the server information
            void setServerInfo(std::string ip, int port);

            // Start the client, this will connect as well
            bool start();   

            // This function sends a string over the current connetion
            virtual bool sendString(std::string toSend){
                std::cout << "Default sendString. Override this" << std::endl;
            }

            //Get Functions
            std::string getServerIP();
            int getServerPort();
            
    };
}
#endif
