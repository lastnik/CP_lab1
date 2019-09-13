#pragma once
#include <string>
#include <fstream>
namespace Log
{
enum Level : uint64_t
{
      debug = 0
    , info
    , warning
    , error
    , fatal
    , off
};

//enum Task : uint64_t
//{
//    notask = 0
//};

}

class Logger
{
    static std::string file;
    static std::fstream out;
    static bool isStarted;
public:
    static void start();
    static void print(Log::Level, char* , ... );
    static void stop();
};
