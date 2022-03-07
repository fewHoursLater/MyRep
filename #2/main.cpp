#include "Header.h"
#include "CIntN.h"
#include "CIntN_Hori.h"
#include "CIntN_Vert.h"
#include "Autotests.h"
#include "Factory.h"
#include "Factory_Hori.h"
#include "Factory_Vert.h"
#include <map>
#include <memory>
#include <vector>
#include <list>
#include <map>

int main()
{
	if (Core_test())
	{
		map<string, unique_ptr<Factory>> Factory_Map;
		
		Factory_Map["hori"] = unique_ptr<Factory>(new Factory_Hori);
		
		Factory_Map["vert"] = unique_ptr<Factory>(new Factory_Vert);

		vector<shared_ptr<CIntN>> storage;

		int cnt = 0;

		string Name_read_file;
		string Cur_line;

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

		Read_File.open(Name_read_file);

		if (!Read_File.is_open())
		{
			cout << "Failed to open file." << endl;

			storage.clear();

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

			auto cur_Factory = Factory_Map.find(type);

			if (cur_Factory == Factory_Map.end())
			{
				cout << "Incorrect parameters." << endl;

				Read_File.close();

				return 1;
			}

			auto cur_Vect = cur_Factory->second->Create(static_cast<int>(elements.size()), filename);
			
			unsigned int i = 0;
			
			for (const auto it : elements)
			{
				(*cur_Vect)[i] = it;

				i++;
			}

			storage.push_back(cur_Vect);
		}

		Read_File.close();

		for (const auto i : storage)
		{
			i->print(i->get_filename());
		}

		storage.clear();

		cout << endl<< "Printing done." << endl;

		return 0;
	}
	else
	{
		cout << "Autotests failed." << endl;
		return 1;
	}	
}