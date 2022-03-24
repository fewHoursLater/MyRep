#include "Header.h"
#include "Autotests.h"
#include "CIntN.h"
#include "CIntN_Hori.h"
#include "CIntN_Vert.h"

int Auto_test1(void)
{

	int buf;

	char sign = '#';

	vector<int> test_data = { 1,2,3,4,5,6,7,8,9 };

	string name_test = "test1.txt";

	CIntN_Hori alpha(9,name_test, test_data,'+');

	alpha.print(alpha.get_filename());

	ifstream read_test_file(name_test);

	if (!read_test_file.is_open())
	{
		return 0;
	}

	read_test_file >> sign;

	if (sign != '+')
	{
		return 0;
	}

	for (int g = 0; g < 9; g++)
	{
		read_test_file >> buf;

		if (buf != g + 1)
		{
			return 0;
		}
	}

	read_test_file.close();

	if (remove("test1.txt"))
	{
		return 0;
	}

	return 1;

}

int Auto_test2(void)
{

	int buf;

	char sign = '#';

	vector<int> test_data = { 9,8,7,6,5,4,3,2,1 };

	string test_file_name = "test2.txt";

	CIntN_Vert alpha(9,test_file_name, test_data,'+');

	alpha.print(alpha.get_filename());

	ifstream read_test_file(test_file_name);

	if (!read_test_file.is_open())
	{
		return 0;
	}

	read_test_file >> sign;

	if (sign != '-')
	{
		return 0;
	}

	for (int g = 0; g < 9; g++)
	{
		read_test_file >> buf;

		if (buf != 9 - g)
		{
			return 0;
		}
	}

	read_test_file.close();

	if (remove("test2.txt"))
	{
		return 0;
	}

	return 1;

}

int Core_test(void)
{
	if (Auto_test1() * Auto_test2())
	{
		return 1;
	}

	return 0;
}