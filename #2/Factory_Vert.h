#pragma once

#include "Header.h"
#include "Factory.h"
#include "Factory_Vert.h"
#include "CIntN.h"
#include "CIntN_Vert.h"

class Factory_Vert : public Factory
{
public:
    virtual CIntN* Create(int size, const string filename) const override
    {
        return new CIntN_Vert(size, filename);
    }

    Factory_Vert() = default;
    ~Factory_Vert() = default;
};
