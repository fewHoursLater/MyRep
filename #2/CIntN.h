#pragma once

class CIntN
{
protected:

	vector<int> arr;

	string filename;
	
	int size;

public:

	CIntN();

	CIntN(int);

	CIntN(int, const string);

	CIntN(string filename, vector<int> elements);

	virtual ~CIntN();

	CIntN(const CIntN&);

	CIntN& operator=(const CIntN&);

	int& operator[](int);

	virtual void print(const string filename) = 0;

	int get_size();

	string get_filename(void);

};
