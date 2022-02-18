#include "Header.h"
#include "Autotests.h"
#include "CData.h"
#include "CData0.h"
#include "CData1.h"

int Test1(void)
{
	int buf;

	vector<int> test_data = { 1,2,3,4,5,6,7,8,9 };
	string test_file_name = "test1.txt";

	CData0 alpha(test_file_name, test_data);

	alpha.output(alpha.get_name());

	ifstream read_test_file(test_file_name);

	if (!read_test_file.is_open())
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

	return 1;
}

int Test2(void)
{
	int buf;

	vector<int> test_data = { 9,8,7,6,5,4,3,2,1 };
	string test_file_name = "test2.txt";

	CData1 alpha(test_file_name, test_data);

	alpha.output(alpha.get_name());

	ifstream read_test_file(test_file_name);

	if (!read_test_file.is_open())
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

	return 1;
}

int Core_test(void)
{
	if (Test1() * Test2() == 1)
	{
		return 1;
	}

	return 0;
}