#include "Header.h"
#include "CIntN.h"

CIntN::CIntN()
{
	this->size = 1;
	arr.push_back(0);
}

CIntN::CIntN(int size)
{
	this->size = size;

	for (int a = 0; a < size; a++)
	{
		arr.push_back(0);
	}
}

CIntN::CIntN(string filename)
{
	this->filename = filename;
}

CIntN::CIntN(int size, const string filename)
{
	this->size = size;

	this->filename = filename;

	ofstream file;
	file.open(filename, ios_base::trunc);

	if (!file.is_open())
	{
		throw std::runtime_error("Failed to open file.\n");
	}

	file.close();

	for (unsigned int i = 0; i < size; i++)
	{
		arr.push_back(0);
	}

}

CIntN::CIntN(string filename, vector<int> elements)
{
	this->filename = filename;

	this->size = elements.size();

	ofstream file;
	file.open(filename, ios_base::trunc);

	if (!file.is_open())
	{
		throw std::runtime_error("Failed to open file.\n");
	}

	file.close();

	for (const auto i : elements)
	{
		arr.push_back(i);
	}
}

CIntN::~CIntN()
{
	size = 0;

	arr.clear();
}

CIntN::CIntN(const CIntN& x)
{
	this->size = x.size;

	if (!arr.empty())
	{
		arr.clear();
	}

	for (const auto i : x.arr)
	{
		arr.push_back(i);
	}
}

CIntN& CIntN::operator=(const CIntN& x)
{
	this->size = x.size;

	if (!this->arr.empty())
	{
		this->arr.clear();
	}

	for (const auto i : x.arr)
	{
		this->arr.push_back(i);
	}

	return *this;
}

int& CIntN::operator[](int index)
{
	if (index < arr.size())
	{
		return arr[index];
	}
}

int CIntN::get_size()
{
	return size;
}

string CIntN::get_filename(void)
{
	return filename;
}