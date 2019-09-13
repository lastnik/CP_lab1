#include "Logger.h"

char const* Logger::file = "log.txt";

std::fstream Logger::out(file, std::ios_base::out);
bool Logger::isStarted = false;
Log::Level Logger::level = Log::Level::warning;
char Logger::buffer[256] = {};

void Logger::start()
{
    if(out.is_open())
    {
        if(level != Log::Level::off)
            isStarted = true;
        else
        {
            out.close();
            return;
        }
    }else
    {
        throw error::ExeptionBase<error::ErrorList::LogError>(std::string("Can not open file: ") + file);
    }
    Logger::print<Log::Level::info>("Logger already started");
}
void Logger::stop()
{
    if(isStarted)
    {
        Logger::print<Log::Level::info>("Logger already finished");
        out.flush();
        out.close();
    }
    isStarted = false;
}

void Logger::setLevel(Log::Level const& logLevel)
{
    level = logLevel;
}

