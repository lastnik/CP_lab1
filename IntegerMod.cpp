#include "IntegerMod.h"
namespace Field
{

BigInt IntegerMod::prime;

BigInt const& IntegerMod::getIntegerMod()
{
    return prime;
}
void IntegerMod::setIntegerMod(BigInt const& _prime)
{
    prime = _prime;
}

}