#include <iostream>
#include <fstream>
#include "Logger.h"

constexpr char const* file = "config.json";

int main() {
    Logger::setLevel(Log::Level::debug);
    try
    {
        Logger::start();
    }
    catch(error::Exeption& exp)
    {
        std::cout << exp.what() << std::endl;
        return -1;
    }

    std::fstream in(file, std::ios_base::in);

    if(!in.is_open())
    {
        Logger::print<Log::Level::fatal>((std::string("Can't open file: ") + file).c_str());
    }

    std::stringstream buf;
    buf << in.rdbuf();
    std::string json = buf.str();
    Logger::print<Log::Level::debug>((std::string("Json config input: \n") + json).c_str());



    Logger::setLevel(Log::Level::debug);
    Logger::stop();
}