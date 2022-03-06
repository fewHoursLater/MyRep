#include"Header.h"
#include "CIntN.h"
#include "CIntN_Hori.h"

CIntN_Hori::~CIntN_Hori() {}

void CIntN_Hori::print(const string filename) 
{
	ofstream file(filename);

	for (int a = 0; a < size; a++)
	{
		file << arr[a] << " ";
	}
}