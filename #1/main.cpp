#include "Header.h"
#include "CIntN.h"
#include "CIntN_Hori.h"
#include "CIntN_Vert.h"
#include "Autotests.h"

int main()
{
	if (Core_test())
	{
		int cnt = 0;

		string Name_read_file;
		string Cur_line;
		string tmp;

		CIntN** storage;

		ifstream Read_File;

		cout << "Enter a file name:" << endl;
		cin >> Name_read_file;

		Read_File.open(Name_read_file);

		if (!Read_File.is_open())
		{
			cout << "Failed to open file." << endl;
			return 1;
		}

		while (getline(Read_File, Cur_line))
		{
			cnt++;
		}

		if (cnt == 0)
		{
			cout << "File is empty." << endl;

			Read_File.close();

			return 1;
		}

		Read_File.close();

		storage = new CIntN * [cnt];

		if (storage == nullptr)
		{
			cout << "Failed to allocate memory." << endl;
			
			return 1;
		}

		Read_File.open(Name_read_file);

		if (!Read_File.is_open())
		{
			cout << "Failed to open file." << endl;

			delete[] storage;

			return 1;
		}

		for (int a = 0; a < cnt; a++)
		{
			getline(Read_File, Cur_line);

			stringstream strStream;

			strStream << Cur_line;

			string type;

			strStream >> type;

			string filename;

			strStream >> filename;

			int element;

			vector<int> elements;

			while (strStream >> element)
			{
				elements.push_back(element);
			}

			if (type == "hori")
			{
				storage[a] = new CIntN_Hori(filename, elements);
			}

			if (type == "vert")
			{
				storage[a] = new CIntN_Vert(filename, elements);
			}

			if (type != "hori" && type != "vert")
			{
				cout << "Incorrect parameters." << endl;
				
				delete[] storage;

				Read_File.close();

				return 1;
			}
		}

		Read_File.close();

		for (int g = 0; g < cnt; g++)
		{
			storage[g]->print(storage[g]->get_filename());
		}

		delete[] storage;

		cout << endl<< "Printing done." << endl;

		return 0;
	}
	else
	{
		cout << "Autotests failed." << endl;
		return 1;
	}	
}



//CIntN operator+(const CIntN& other)
//{
//	if (this->size == other.size)
//	{
//		CIntN rez(this->size);
//
//		for (int b = 0; b < this->size; b++)
//		{
//			rez[b] = this->arr[b] + other.arr[b];
//		}
//
//		return rez;
//	}
//}
//
//CIntN operator-(const CIntN& other)
//{
//	if (this->size == other.size)
//	{
//		CIntN rez(this->size);
//
//		for (int b = 0; b < this->size; b++)
//		{
//			rez[b] = this->arr[b] - other.arr[b];
//		}
//
//		return rez;
//	}
//}