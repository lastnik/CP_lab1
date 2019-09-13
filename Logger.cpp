#include "Logger.h"

std::string Logger::file = "log.txt";
std::fstream Logger::out;
bool Logger::isStarted = false;

void Logger::start()
{
    out.open(file, );
}
void Logger::stop()
{

}

