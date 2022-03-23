#pragma once

#include "Header.h"
#include "Factory.h"
#include "Factory_Hori.h"
#include "CIntN.h"
#include "CIntN_Hori.h"

class Factory_Hori : public Factory
{
public:
    virtual CIntN* Create(int size, const string filename) const override
    {
        return new CIntN_Hori(size, filename);
    }

    Factory_Hori() = default;
    ~Factory_Hori() = default;
};
