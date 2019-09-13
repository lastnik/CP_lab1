#pragma once

#include <string>
#include <utility>

namespace json
{

class JsonObject
{
public:
    explicit JsonObject() = default;
    JsonObject(JsonObject const&) = delete;
    explicit JsonObject(std::string  _str) : str(std::move(_str)){};

private:
    std::string str;
};

class JsonValue
{
public:
    JsonValue() = default;
    JsonValue(JsonValue const&) = delete;
    explicit JsonValue(std::string  _str) : str(std::move(_str)){};

private:
    std::string str;

};

class JsonParser
{
public:
    explicit JsonParser() = delete;
    JsonParser(JsonParser const&) = delete;
    static JsonObject const parse(JsonValue const&);
};

}