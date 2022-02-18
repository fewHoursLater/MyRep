#include "Header.h"
#include "CIntN.h"

CIntN::CIntN()
{
	this->power = 1;
	arr = new int[this->power];
	arr[0] = 0;
}

CIntN::CIntN(int power)
{
	this->power = power;
	arr = new int[power];

	for (int a = 0; a < power; a++)
	{
		arr[a] = 2;
	}
}

CIntN::CIntN(vector<int> line)
{

	this->power = line.size();

	arr = new int[power];

	for (int a = 0; a < power; a++)
	{
		arr[a] = line[a];
	}
}

CIntN::~CIntN()
{
	delete[] this->arr;
}

CIntN::CIntN(const CIntN& x) // Конструктор копирования
{
	this->power = x.power;

	if (this->arr != nullptr)
	{
		delete[] this->arr;
	}

	this->arr = new int[this->power];

	for (int a = 0; a < this->power; a++)
	{
		this->arr[a] = x.arr[a];
	}
}

CIntN& CIntN::operator=(const CIntN& x) //Конструктор присваивания копированием
{
	this->power = x.power;

	if (this->arr != nullptr)
	{
		delete[] this->arr;
	}

	this->arr = new int[x.power];

	for (int a = 0; a < this->power; a++)
	{
		this->arr[a] = x.arr[a];
	}

	return *this;
}

CIntN CIntN::operator+(const CIntN& other)
{
	if (this->power == other.power)
	{
		CIntN rez(this->power);

		for (int b = 0; b < this->power; b++)
		{
			rez[b] = this->arr[b] + other.arr[b];
		}

		return rez;
	}
}

CIntN CIntN::operator-(const CIntN& other)
{
	if (this->power == other.power)
	{
		CIntN rez(this->power);

		for (int b = 0; b < this->power; b++)
		{
			rez[b] = this->arr[b] - other.arr[b];
		}

		return rez;
	}
}

int& CIntN::operator[](int index)
{
	return arr[index];
}


void CIntN::print()
{
	for (int a = 0; a < power; a++)
	{
		cout << this->arr[a] << " ";
	}

	cout << endl << endl;
}

int CIntN::get_power()
{
	return power;
}