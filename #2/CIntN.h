#pragma once

class CIntN
{
protected:

	int size;
	string filename;
	vector<int> arr;	
	char sign = '#';

public:

	CIntN(void); 

	CIntN(const int); 

	CIntN(const int, const string, const char); 

	CIntN(const int, const string, const vector<int>, const char); 


	virtual ~CIntN();

	CIntN(const CIntN&);

	CIntN& operator=(const CIntN&);

	int& operator[](int);

	virtual void print(const string) = 0;

	int get_size(void);

	string get_filename(void);

	char get_sign(void);

};
