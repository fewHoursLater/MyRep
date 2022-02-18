#include "Header.h"
#include "CData.h"
#include "CData0.h"



CData0::CData0(string File_Name, vector<int> data)
{

	this->filename = File_Name;

	CIntN tmp(data);

	this->data = tmp;
}

void CData0::output(const string FileName) 
{
	ofstream file(FileName);

	for (int a = 0; a < data.get_power(); a++)
	{
		file << data[a] << " ";
	}

	file.close();
}

string CData0::get_name() 
{
	return filename;
}