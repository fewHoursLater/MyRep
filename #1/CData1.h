#pragma once

#include "Header.h"
#include "CData.h"

class CData1 : public CData // �������
{
public:

	CData1(string, vector<int>);

	void output(const string);

	string get_name(void) override;

};