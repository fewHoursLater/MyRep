#pragma once

#include "Header.h"
#include "CData.h"

class CData0 : public CData // Строка
{
public:

	CData0(string, vector<int>);

	void output(const string);

	string get_name(void) override;

};
