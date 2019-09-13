#include "BigInt.h"
#include "Exeptions.h"
#include "Logger.h"
#include <cstdint>

namespace details
{

inline uint16_t convert(char const& a)
{
    if(a >= '0' && a <= '9')
    {
        return a - '0';
    }else if(a >= 'A' && a <= 'F')
    {
        return a - 'A' + 10;
    } else if(a >= 'a' && a <= 'f')
    {
        return a - 'a' + 10;
    } else
    {
        throw error::ExeptionBase<error::ErrorList::InputError>(std::string("Can't convert value: ") + a);
    }
}

}

BigInt::BigInt():number(0)
{}

void BigInt::setByString(std::string const& str)
{
    uint64_t biteSize = 0;
    for(auto i : str)
    {
        try
        {
            number.push_back((biteSize % 8 == 0 ? details::convert(i) : (details::convert(i) << 4)));
        }
        catch(error::Exeption& exp)
        {
            number.clear();
            Logger::print<Log::Level::fatal>(exp.what());
            throw error::ExeptionBase<error::ErrorList::FatalTrace>("Fail function BigInt::setByString()");
        }
        biteSize += 4;
    }
}