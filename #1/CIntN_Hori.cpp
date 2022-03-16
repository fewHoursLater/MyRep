#include"Header.h"
#include "CIntN.h"
#include "CIntN_Hori.h"

CIntN_Hori::~CIntN_Hori() {}

void CIntN_Hori::print(const string filename) 
{
	ofstream file;

	file.open(filename, std::ios::app);

	for (int a = 0; a < size; a++)
	{
		file << arr[a] << " ";
	}

	file.close();
}

CIntN_Hori operator+(CIntN& A, CIntN& B)
{
	if (A.get_size() == B.get_size())
	{
		CIntN_Hori rez(A.get_size());

		rez.filename = A.get_filename();

		for (int b = 0; b < A.get_size(); b++)
		{
			rez[b] = A[b] + B[b];
		}

		return rez;
	}
}

CIntN_Hori operator-(CIntN& A, CIntN& B)
{
	if (A.get_size() == B.get_size())
	{
		CIntN_Hori rez(A.get_size());

		rez.filename = A.get_filename();

		for (int b = 0; b < A.get_size(); b++)
		{
			rez[b] = A[b] + B[b];
		}

		return rez;
	}
}
