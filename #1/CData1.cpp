#include "Header.h"
#include "CData.h"
#include "CData1.h"


CData1::CData1(string File_Name, vector<int> data)
{
	this->filename = File_Name;

	CIntN tmp(data);

	this->data = tmp;
}

void CData1::output(const string FileName) 
{
	ofstream file(FileName);

	for (int a = 0; a < data.get_power(); a++)
	{
		file << data[a] << '\n';
	}

	file.close();
}

string CData1::get_name() 
{
	return filename;
}