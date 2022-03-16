#include"Header.h"
#include "CIntN.h"
#include "CIntN_Hori.h"

CIntN_Hori::~CIntN_Hori() {}

void CIntN_Hori::print(const string filename)
{
	ofstream file;

	file.open(filename, std::ios::app);

	if (!file.is_open())
	{
		throw std::runtime_error("Failed to open file.\n");
	}

	for (const auto i : this->arr)
	{
		file << i << " ";
	}

	file << endl << endl;

	file.close();
}

CIntN_Hori operator+(CIntN& A, CIntN& B)
{
	if (A.get_size() != B.get_size())
	{
		throw std::runtime_error("Trying to sum vectors with different lengths.\n");
	}

	CIntN_Hori rez(A.get_size());

	rez.filename = A.get_filename();

	for (int b = 0; b < A.get_size(); b++)
	{
		rez[b] = A[b] + B[b];
	}

	return rez;
}

CIntN_Hori operator-(CIntN& A, CIntN& B)
{

	if (A.get_size() != B.get_size())
	{
		throw std::runtime_error("Trying to sum vectors with different lengths.\n");
	}
	
	CIntN_Hori rez(A.get_size());

	rez.filename = A.get_filename();

	for (int b = 0; b < A.get_size(); b++)
	{
		rez[b] = A[b] - B[b];
	}

	return rez;
	
}