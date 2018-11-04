#ifndef _VC_UTILS_HEADER__
#define _VC_UTILS_HEADER__
#include <vector>
#include <string>
class VCUtils{
    public:
    static std::string vectorJoin(std::vector<std::string> in, std::string joiner);

    static std::vector<std::string> strSplit(std::string input, std::string delim);
};

#endif