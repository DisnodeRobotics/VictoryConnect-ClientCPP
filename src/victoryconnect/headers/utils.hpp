#ifndef _VC_UTILS_HEADER__
#define _VC_UTILS_HEADER__
#include <vector>
#include <string>
namespace VictoryConnect{
    class Utils{
        public:
        static std::string vectorJoin(std::vector<std::string> in, std::string joiner);
        static std::vector<std::string> strSplit(std::string input, std::string delim);
        static int calcPing(std::string timestamp);
    };
    
}
#endif
