#pragma once

#include "Header.h"
#include "CIntN.h"

class Factory
{
public:
    virtual CIntN* Create(const int size, const string filename, const char sign) const = 0;

    Factory() = default;

    virtual ~Factory() = default;
};
