#pragma once
#include "Field.h"

// odd Field only

class EllipticCurve
{
public:
    EllipticCurve() = default;
    EllipticCurve(EllipticCurve const&) = default;
    void set(Field::BigInt const& A, Field::BigInt const& B);
    Field::BigInt getY(Field::BigInt x);
private:
    Field::BigInt A, B;
};
