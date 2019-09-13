#pragma once

#include <stdint.h>
#include <string>

namespace error
{
enum ErrorList : uint64_t
{
      InputError = 0
    , Total
};

class Exeption
{
public:
    Exeption(std::string const& _str) : str(_str){};
    std::string str;
};

template<ErrorList value>
class ExeptionBase : public Exeption
{
public:
    ExeptionBase() : Exeption("This last one exeption") {};
};

template <>
class ExeptionBase<InputError> : public Exeption
{
public:
    ExeptionBase() : Exeption("Input error exeption") {};
};


}