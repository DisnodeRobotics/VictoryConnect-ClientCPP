#ifndef _VC_LOGGER_HEADER__
#define _VC_LOGGER_HEADER__
#include <iostream>
#include <string>
namespace VictoryConnect{
    class Logger{
        enum LogLevel {
        DISABLED,
        ERROR,
        WARNING,
        LOG,
        DEBUG
    };
        private:
            static LogLevel mLogLevel;
            static bool saveToFile;
        public:
            static void setLogLevel(LogLevel level);
            static void setSaveToFile(bool save);
            static std::string debug(std::string caller, std::string method, std::string message);
            static std::string log(std::string caller, std::string method, std::string message);
            static std::string warning(std::string caller, std::string method, std::string message);
            static std::string error(std::string caller, std::string method, std::string message);
    };
}
#endif
