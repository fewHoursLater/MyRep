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

	CIntN(string filename, vector<int> elements);

	virtual ~CIntN();

	CIntN(const CIntN&);

	CIntN& operator=(const CIntN&);

	int& operator[](int);

	virtual void print(const string filename) = 0;

	int get_size();

	string get_filename(void);

};
