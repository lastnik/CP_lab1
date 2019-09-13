#pragma once
#include <exception>
#include <cstdint>
#include <string>
#include <utility>

namespace error
{
enum ErrorList : uint64_t
{
      InputError = 0
    , LogError
    , FatalTrace
    , Total
};

class Exeption : public std::exception
{
    std::string str;
    std::string desc;
public:
    explicit Exeption(std::string _str, std::string _desc) : str(std::move(_str)),  desc(std::move(_desc)) {};
    const char* what() const noexcept final
    {
        return (str + " " + desc).c_str();
    }
};

template<ErrorList value>
class ExeptionBase;

template <>
class ExeptionBase<LogError> : public Exeption
{
public:
    explicit ExeptionBase(const std::string& _desc) : Exeption("Log error exeption", _desc){};
};

template <>
class ExeptionBase<InputError> : public Exeption
{
public:
    explicit ExeptionBase(const std::string& _desc) : Exeption("Input error exeption", _desc){};

};

template <>
class ExeptionBase<FatalTrace> : public Exeption
{
public:
    explicit ExeptionBase(const std::string& _desc) : Exeption("Fatal trace exeption", _desc){};

};

template<ErrorList value>
class ExeptionBase : public Exeption
{
public:
    explicit ExeptionBase(const std::string& _desc) : Exeption("This last one exeption", _desc){};
};


}