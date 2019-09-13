#pragma once
#include <string>
#include <cstdint>
#include <vector>
#include "Field.h"

class BigInt {

public:
    explicit BigInt();
    BigInt(BigInt const&) = default;
    BigInt& operator=(BigInt const&) = default;

    void setByString(std::string const&); //values should be in hex format
private:
    std::vector<uint8_t> number;
};