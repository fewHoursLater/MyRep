#pragma once

#include "Header.h"
#include "CIntN.h"

class Factory
{
public:
    virtual shared_ptr<CIntN> Create(const int size, const string filename) const = 0;

    Factory() = default;

    virtual ~Factory() = default;
};
