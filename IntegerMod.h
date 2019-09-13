#pragma once
#include "BigInt.h"

namespace Field
{

class IntegerMod
{
    static BigInt prime;
    IntegerMod();
public:
    static void setIntegerMod(BigInt const&);
    static BigInt const& getIntegerMod();
};

}