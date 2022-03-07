#include"Header.h"
#include "CIntN.h"
#include "CIntN_Vert.h"

CIntN_Vert::~CIntN_Vert() {}

void CIntN_Vert::print(const string filename) 
{
	ofstream file(filename);

	for (const auto i : arr)
	{
		file << i << '\n';
	}
}


