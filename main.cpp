#include <iostream>
#include "Logger.h"
#include "BigInt.h"
#include "Field.h"
#include "IntegerMod.h"
#include "Rand.h"
#include "EllipticCurve.h"
constexpr char const* file = "config.json";
struct config
{
    std::string prime;
    std::string A;
    std::string B;
    std::string LogLevel;
};
std::string find(std::string const& str, std::string const& key)
{
    auto k = str.find(key);
    if(k == std::string::npos)
    {
        throw error::ExeptionBase<error::ErrorList::InputError>("Lose mandatory field " + key);
    }
    k = str.find(':', k + 1);
    if(k == std::string::npos)
    {
        throw error::ExeptionBase<error::ErrorList::InputError>("Lose mandatory value of field " + key);
    }
    auto start = str.find("\"",k + 1);
    auto end   = str.find( "\"", start + 1);
    if(end == str.size())
        end  = str.find( "\n", start + 1);

    return str.substr(start + 1, end - start - 1);
};
config parse(std::string const& str)
{
    config cfg;
    cfg.prime = find(str,"prime");
    cfg.A = find(str,"A");
    cfg.B = find(str,"B");
    cfg.LogLevel = find(str,"LogLevel");
    return cfg;
}

int main() {
    Logger::setLevel(Log::Level::debug);
    bool crash = false;
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
        crash = true;
    }

    std::stringstream buf;
    buf << in.rdbuf();
    std::string json = buf.str();
    BigInteger::BigInt a, b, prime;
    Field::BigInt A, B;
    EllipticCurve curve;
    try
    {
        auto cfg = parse(json);
        Logger::setLevel(cfg.LogLevel);
        a.setByString(cfg.A);
        b.setByString(cfg.B);
        prime.setByString(cfg.prime);
        Field::IntegerMod::setIntegerMod(prime);
        A = Field::BigInt(a);
        B = Field::BigInt(b);
        curve.set(A, B);
    }
    catch(error::Exeption& exp)
    {
        Logger::print<Log::Level::fatal>(exp.what().c_str());
        std::cout << exp.what() << std::endl;
        crash = true;
    }

    Logger::setLevel(Log::Level::debug);

    if(crash)
    {
        Logger::stop();
        return -1;
    }

    Logger::print<Log::Level::debug>((std::string("Json config input: \n") + json).c_str());

    bool exit = false;
    while (!crash && !exit)
    {
        try
        {
            std::cout << "1. Get randomized point of elliptic curve\n default. Exit\n Write number and pressed enter\n";
            int k;
            std::cin >> k;
            Field::BigInt x,y;
            switch(k)
            {
                case 1:
                    x = Rand::rand(Field::IntegerMod::getIntegerMod().getBitSize());
                    y = curve.getY(x);
                    std::cout << "(" << x.toString() + " ; " + y.toString() << ")- point of curve\n";
                    Logger::print<Log::Level::info>("(%s,%s) - point of curve", x.toString().c_str(), y.toString().c_str());
                    break;
                default :
                    exit = true;
                    break;
            }
        }
        catch (error::ExeptionBase<error::ArithmeticError>& exp)
        {
            std::cout << exp.what() << std::endl;
            Logger::print<Log::Level::info>(exp.what().c_str());
        }
        catch(error::Exeption& exp)
        {
            Logger::print<Log::Level::fatal>(exp.what().c_str());
            crash = true;
        }
    }
    Logger::stop();
    return 0;
}