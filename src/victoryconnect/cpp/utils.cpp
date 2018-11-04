#include "utils.hpp"

std::string VCUtils::vectorJoin(std::vector<std::string> in){
    std::string result = "";
    for(int i=0;i<in.size();i++){
        if(i<in.size() -1){
            result+= in[i] +",";
        }else{
            result += in[i];
        }
    }
    return result;
}