#include"Header.h"
#include "CIntN.h"
#include "CIntN_Vert.h"

CIntN_Vert::~CIntN_Vert() {}

void CIntN_Vert::print(const string filename) 
{
	ofstream file;

	file.open(filename, std::ios::app);

	for (int a = 0; a < size; a++)
	{
		file << arr[a] << " ";
	}

	file.close();
}

CIntN_Vert operator+(CIntN& A, CIntN& B)
{
	
	if (A.get_size() == B.get_size())
	{
		CIntN_Vert rez(A.get_size());

		rez.filename = A.get_filename();

		for (int b = 0; b < A.get_size(); b++)
		{
			rez[b] = A[b] + B[b];
		}

		return rez;
	}

}

CIntN_Vert operator-(CIntN& A, CIntN& B)
{
	if (A.get_size() == B.get_size())
	{
		CIntN_Vert rez(A.get_size());

		rez.filename = A.get_filename();

		for (int b = 0; b < A.get_size(); b++)
		{
			rez[b] = A[b] - B[b];
		}

		return rez;
	}
}


