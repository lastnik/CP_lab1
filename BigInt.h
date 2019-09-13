#pragma once
#include <string>
#include <cstdint>
#include <vector>
#include "Field.h"

class BigInt {

public:
    explicit BigInt();
    explicit BigInt(std::string const&); //values should be in hex format
    explicit BigInt(BigInt const&);
    //friend Field::operator
private:
    std::vector<uint8_t> number;
};