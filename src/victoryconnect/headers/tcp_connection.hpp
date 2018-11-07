#ifndef _VC_CONNECTION_HEADER__
#define _VC_CONNECTION_HEADER__
#include <vector>
#include <string>
#include "client.hpp"
#include "connection.hpp"
namespace VictoryConnect{
    class TCPConnetion : public Connection{
       
        public:
             bool overrideconnect() {}
            
    };
}
#endif
