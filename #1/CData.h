#pragma once

#include "Header.h"
#include "CIntN.h"

class CData // ����������� ����� �� ����� ����� ����????
{
protected:

	string filename;
	CIntN data;

public:

	virtual void output(const string FileName = NULL) = 0;
	virtual string get_name(void) = 0;
};
