#include "Header.h"
#include "CIntN.h"

CIntN::CIntN(void)
{
	this->size = 1;

	this->sign = '#';
	
	arr.push_back(0);
}

CIntN::CIntN(const int size)
{
	this->size = size;
	
	this->sign = '#';

	for (int a = 0; a < size; a++)
	{
		arr.push_back(0);
	}
}

CIntN::CIntN(const int size, const string filename, const char sign)
{
	this->size = size;

	this->filename = filename;

	this->sign = sign;

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

CIntN::CIntN(const int size, const string filename, const vector<int> elements, const char sign)
{
	this->size = elements.size();

	this->filename = filename;

	this->sign = sign;

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

CIntN::CIntN(const CIntN& other)
{
	this->arr.clear();

	this->size = other.size;
	
	this->filename = other.filename;

	this->sign = other.sign;


	if (!this->arr.empty())
	{
		this->arr.clear();
	}

	for (const auto i : other.arr)
	{
		arr.push_back(i);
	}
}

CIntN& CIntN::operator=(const CIntN& other)
{

	this->arr.clear();

	this->size = other.size;

	this->filename = other.filename;
	
	this->sign = other.sign;

	if (!this->arr.empty())
	{
		this->arr.clear();
	}

	for (const auto i : other.arr)
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

int CIntN::get_size(void)
{
	return size;
}

string CIntN::get_filename(void)
{
	return filename;
}

char CIntN::get_sign(void)
{
	return sign;
}