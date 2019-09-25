#include "Exeptions.h"
#include "EllipticCurve.h"
#include "Logger.h"
#include "IntegerMod.h"

void EllipticCurve::set(Field::BigInt const& a, Field::BigInt const& b)
{
    using namespace Field;
    A = a; B = b;
    if(("4"_BigIntMod * (a ^ "3"_BigIntMod) + "1B"_BigIntMod * (b ^ "2"_BigIntMod)) != "0"_BigIntMod)
    {
        Logger::print<Log::Level::info>("Create elliptic curve with A = %s and B = %s" , A.toString().c_str(), B.toString().c_str());
    }else
    {
        A = "0"_BigIntMod; B = "0"_BigIntMod;
        throw error::ExeptionBase<error::ErrorList::InputError>("Can't create elliptic curve with A = " + A.toString() + " and B = " + B.toString());
    }
}

Field::BigInt EllipticCurve::getY(Field::BigInt x)
{
    using namespace Field;
    Field::BigInt Y = (x ^ "3"_BigIntMod) + A * x + B;
    Logger::print<Log::Level::info>("X = %s",x.toString().c_str());
    Logger::print<Log::Level::info>("Y^2 = %s",Y.toString().c_str());

    if(Field::IntegerMod::check(Y))
    {
        return sqrt(Y);
    }else
    {
        throw error::ExeptionBase<error::ErrorList::ArithmeticError>("X = " + x.toString() + " and Y = " + Y.toString() + " is quadratic non-deduction in Field by prime = " + Field::IntegerMod::getIntegerMod().toString());
    }
}


