#include "Header.h"
#include "CIntN.h"

CIntN::CIntN()
{
	this->size = 1;
	arr = new int[this->size];
	arr[0] = 0;
}

CIntN::CIntN(int size)
{
	this->size = size;
	arr = new int[size];

	for (int a = 0; a < size; a++)
	{
		arr[a] = 0;
	}
}

CIntN::CIntN(string filename, vector<int> elements)
{
	this->filename = filename;

	this->size = elements.size();

	arr = new int[size];

	for (int a = 0; a < size; a++)
	{
		arr[a] = elements[a];
	}
}

CIntN::~CIntN()
{
	size = 0;
	delete[] this->arr;
}

CIntN::CIntN(const CIntN& x)
{
	this->size = x.size;

	if (this->arr != nullptr)
	{
		delete[] this->arr;
	}

	this->arr = new int[this->size];

	for (int a = 0; a < this->size; a++)
	{
		this->arr[a] = x.arr[a];
	}
}

CIntN& CIntN::operator=(const CIntN& x)
{
	this->size = x.size;

	if (this->arr != nullptr)
	{
		delete[] this->arr;
	}

	this->arr = new int[x.size];

	for (int a = 0; a < this->size; a++)
	{
		this->arr[a] = x.arr[a];
	}

	return *this;
}

int& CIntN::operator[](int index)
{
	return arr[index];
}

int CIntN::get_size()
{
	return size;
}

string CIntN::get_filename(void)
{
	return filename;
}