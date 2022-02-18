#pragma once

#include "Header.h"

class CIntN
{
private:

	int* arr = nullptr;
	int power;

public:

	CIntN();

	CIntN(int);

	CIntN(vector<int>);

	~CIntN(void);

	CIntN(const CIntN&);

	CIntN& operator=(const CIntN&);

	CIntN operator+(const CIntN&);

	CIntN operator-(const CIntN&);

	int& operator[](int);

	void print();

	int get_power();

};
