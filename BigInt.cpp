#include "BigInt.h"
#include ""
namespace details
{

inline uint8_t convert(char const& a)
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
        throw ;
    }
}

}


BigInt::BigInt():number(0)
{}

BigInt::BigInt(std::string const& str)
{
    uint64_t biteSize = 0;
    for(auto i : str)
    {
        if(biteSize % 8 == 0)
        {
            number.push_back(0);

        }else
        {

        }
        biteSize += 4;
    }
}