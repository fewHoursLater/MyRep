#pragma once

#include "Header.h"
#include "Factory.h"
#include "Factory_Hori.h"
#include "CIntN.h"
#include "CIntN_Hori.h"

class Factory_Hori : public Factory
{
public:
    virtual CIntN* Create(int size, const string filename, const char sign) const override
    {
        return new CIntN_Hori(size, filename, sign);
    }

    Factory_Hori() = default;
    ~Factory_Hori() = default;
};
