#include"Header.h"
#include "CIntN.h"
#include "CIntN_Vert.h"

CIntN_Vert::~CIntN_Vert() {}

void CIntN_Vert::print(const string filename)
{
	ofstream file;

	file.open(filename, std::ios::app);

	if (!file.is_open())
	{
		throw std::runtime_error("Failed to open file.\n");
	}

	file << this->sign;

	for (const auto i : this->arr)
	{
		file << i << '\n';
	}

	file << endl << endl;

	file.close();

}
