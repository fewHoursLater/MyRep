#include "Header.h"
#include "CData.h"
#include "CData0.h"
#include "CData1.h"
#include "Autotests.h"

int main()
{
	if (Core_test())
	{
		int cnt = 0;
		char data;

		vector<int> numbers;
		vector<char> full_data;
		vector<char> Name_to_print_vector;

		string File_Name;
		string line;

		CData** storage;

		ifstream Read_File;

		cout << "Enter a file name:" << endl;
		cin >> File_Name;

		Read_File.open(File_Name);

		if (!Read_File.is_open())
		{
			cout << "Something went wrong." << endl;
			return 1;
		}

		while (getline(Read_File, line))
		{
			cnt++;
		}

		Read_File.close();

		storage = new CData * [cnt];

		Read_File.open(File_Name);

		for (int a = 0; a < cnt; a++)
		{
			while (Read_File >> data)
			{
				full_data.push_back(data);

				if (Read_File.peek() == '\n' || Read_File.peek() == EOF)
				{
					break;
				}
			}

			int dot_pos = 0;

			for (int p = 0; p < full_data.size(); p++)
			{
				if (full_data[p] == '.')
				{
					dot_pos = p;
				}
			}

			int param = full_data[0] - 48;

			for (int y = 1; y < dot_pos + 4; y++)
			{
				Name_to_print_vector.push_back(full_data[y]);
			}

			for (int k = dot_pos + 4; k < full_data.size(); k++)
			{
				int tmp = full_data[k] - 48;
				numbers.push_back(tmp);
			}

			string Name_to_print(Name_to_print_vector.begin(), Name_to_print_vector.end());

			if (param == 0)
			{
				storage[a] = new CData0(Name_to_print, numbers);
			}

			if (param == 1)
			{
				storage[a] = new CData1(Name_to_print, numbers);
			}

			if (param != 1 && param != 0)
			{
				cout << "Something went wrong." << endl;

				full_data.clear();
				Name_to_print_vector.clear();
				numbers.clear();
				Read_File.close();

				delete[] storage;

				return 1;
			}

			full_data.clear();
			Name_to_print_vector.clear();
			numbers.clear();

			cout << endl << endl;
		}

		Read_File.close();

		for (int g = 0; g < cnt; g++)
		{
			storage[g]->output(storage[g]->get_name());
		}

		delete[] storage;

		return 0;
	}

	cout << "Something went wrong." << endl;
	return 1;

}