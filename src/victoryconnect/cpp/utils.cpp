#include "utils.hpp"
using namespace VictoryConnect;
std::string Utils::vectorJoin(std::vector<std::string> in, std::string joiner){
    std::string result = "";
    for(int i=0;i<in.size();i++){
        if(i<in.size() -1){
            result+= in[i] +joiner;
        }else{
            result += in[i];
        }
    }
    return result;
}

std::vector<std::string> Utils::strSplit(std::string input, std::string delim){
    std::vector<std::string> result ;
    
    while(input.size()){
        int index = input.find(delim);
        if(index!=std::string::npos){
            result.push_back(input.substr(0,index));
            input = input.substr(index+delim.size());
            if(input.size()==0)result.push_back(input);
        }else{
            result.push_back(input);
            input = "";
        }
    }

    return result;
}