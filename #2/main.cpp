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
#include <stdexcept>

int main()
{
	if (Core_test())
	{
		try
		{
			map<string, unique_ptr<Factory>> Factory_Map;

			Factory_Map["hori"] = unique_ptr<Factory>(new Factory_Hori);

			Factory_Map["vert"] = unique_ptr<Factory>(new Factory_Vert);

			vector<shared_ptr<CIntN>> storage;

			int cnt = 0;

			string Name_read_file;
			string Cur_line;

			ifstream Read_File;

			std::cout << "Enter a file name:" << endl;
			cin >> Name_read_file;

			Read_File.open(Name_read_file);

			if (!Read_File.is_open())
			{
				throw std::runtime_error("Failed to open file.\n");
			}

			while (getline(Read_File, Cur_line))
			{
				cnt++;
			}

			if (cnt == 0)
			{
				Read_File.close();

				throw std::runtime_error("File is empty.\n");
			}

			Read_File.close();

			Read_File.open(Name_read_file);

			if (!Read_File.is_open())
			{
				storage.clear();

				throw std::runtime_error("Failed to open file.\n");
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
					Read_File.close();

					throw std::runtime_error("Incorrect parameters of printing.\n");
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

			std::cout << endl << "Printing done." << endl;

			return 0;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << endl;
			return 1;
		}
		
	}
	else
	{
	std::cout << "Autotests failed." << endl;
		return 1;
	}
}