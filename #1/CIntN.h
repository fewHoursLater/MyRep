#pragma once

class CIntN
{
protected:

	int* arr = nullptr;
	string filename;
	int size;
	

public:

	CIntN();

	CIntN(int);

	CIntN(string);

	CIntN(string, vector<int>);

	virtual ~CIntN();

	CIntN(const CIntN&);

	CIntN& operator=(const CIntN&);

	int& operator[](int);

	virtual void print(const string) = 0;

	int get_size();

	string get_filename(void);

};
