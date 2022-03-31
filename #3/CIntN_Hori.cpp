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

	file << this->sign<<" ";

	for (const auto i : this->arr)
	{
		file << i << " ";
	}

	file << endl << endl;

	file.close();
}


CIntN_Hori operator+(CIntN& first_member, CIntN& second_member)
{
	if (first_member.get_size() != second_member.get_size())
	{
		throw std::runtime_error("An attempt to perform calculations with vectors of different dimensions.\n");
	}

	CIntN_Hori rez(first_member.get_size());

	rez.filename = first_member.get_filename(); 


	if (first_member.get_sign() == '+' && second_member.get_sign() == '+')
	{
		int elder = 0;

		for (int c = first_member.get_size() - 1; c >= 0; c--)
		{
			rez[c] = first_member[c] + second_member[c];
			rez[c] = rez[c] + elder;

			if (c == 0)
			{
				if (rez[c] > 9)
				{
					throw std::runtime_error("Overflow.\n");
				}
			}

			if (rez[c] > 9)
			{
				rez[c] = rez[c] - 10;
				elder = 1;
				continue;
			}

			elder = 0;
		}

		rez.sign = '+';

		return rez;
	}			

	if (first_member.get_sign() == '+' && second_member.get_sign() == '-')
	{

		int who_is_greater = 0;
		bool they_are_equal = true;

		for (int j = 0; j < first_member.get_size(); j++)
		{
			if (first_member[j] != second_member[j])
			{
				they_are_equal = false;
				break;
			}
		}

		if (they_are_equal && first_member.get_size()==1)
		{
			rez[0] = 0;

			rez.sign = '#';

			return rez;
		}

		if (they_are_equal && first_member.get_size() > 1)
		{
			throw std::runtime_error("left the limits of the set boundaries.\n");
		}

		if (they_are_equal == false)
		{
			
			for (int i = 0; i < first_member.get_size(); i++)
			{
				if (second_member[i] > first_member[i])
				{
					who_is_greater = 2;
					break;
				}

				who_is_greater = 1;
			}
		}
		
		if (who_is_greater == 1)
		{

			int credit = 0;
			int tmp = 0;

			for (int a = first_member.get_size() - 1; a >= 0; a--)
			{
				if (a == first_member.get_size() - 1)
				{
					if (first_member[a] >= second_member[a])
					{
						rez[a] = first_member[a] - second_member[a];
					}

					if (first_member[a] < second_member[a])
					{
						credit = 1;
						rez[a] = (first_member[a] + 10) - second_member[a];
					}

					continue;
				}

				if (first_member[a] == 0)
				{
					if (second_member[a] != 0)
					{
						if (credit == 1)
						{
							credit = 1;
							rez.arr[a] = 9 - second_member[a];
						}

						if (credit == 0)
						{
							credit = 1;
							rez[a] = 10 - second_member[a];
						}
					}

					if (second_member[a] == 0)
					{
						if (credit == 1)
						{
							rez[a] = 9;
						}

						if (credit == 0)
						{
							rez[a] = 0;
						}
					}
				}

				if (first_member[a] > 0)
				{
					tmp = first_member[a];
					tmp = tmp - credit;

					if (tmp == 0)
					{
						credit = 1;
						rez[a] = 10 - second_member[a];
					}

					if (tmp != 0 && tmp < second_member[a])
					{
						credit = 1;
						rez[a] = (tmp + 10) - second_member[a];
					}

					if (tmp >= second_member[a])
					{
						credit = 0;
						rez[a] = tmp - second_member[a];
					}
				}
			}

			if (rez.get_size() > 1 && rez[0] == 0)
			{
				throw std::runtime_error("left the limits of the set boundaries.\n");
			}

			rez.sign = '+';

			return rez;

		}

		if (who_is_greater == 2)
		{
			int credit = 0;
			int tmp = 0;

			for (int a = second_member.get_size() - 1; a >= 0; a--)
			{
				if (a == second_member.get_size() - 1)
				{
					if (second_member[a] >= first_member[a])
					{
						rez[a] = second_member[a] - first_member[a];
					}

					if (second_member[a] < first_member[a])
					{
						credit = 1;
						rez[a] = (second_member[a] + 10) - first_member[a];
					}

					continue;
				}

				if (second_member[a] == 0)
				{
					if (first_member[a] != 0)
					{
						if (credit == 1)
						{
							credit = 1;
							rez[a] = 9 - first_member[a];
						}

						if (credit == 0)
						{
							credit = 1;
							rez[a] = 10 - first_member[a];
						}
					}

					if (first_member[a] == 0)
					{
						if (credit == 1)
						{
							rez[a] = 9;
						}

						if (credit == 0)
						{
							rez[a] = 0;
						}
					}
				}

				if (second_member[a] > 0)
				{
					tmp = second_member[a];
					tmp = tmp - credit;

					if (tmp == 0)
					{
						credit = 1;
						rez[a] = 10 - first_member[a];
					}

					if (tmp != 0 && tmp < first_member[a])
					{
						credit = 1;
						rez[a] = (tmp + 10) - first_member[a];
					}

					if (tmp >= first_member[a])
					{
						credit = 0;
						rez[a] = tmp - first_member[a];
					}
				}
			}

			if (rez.get_size() > 1 && rez[0] == 0)
			{
				throw std::runtime_error("left the limits of the set boundaries.\n");
			}

			if (rez[0] == 0)
			{
				rez.sign = '#';
				return rez;
			}

			rez.sign = '-';

			return rez;

		}
	}			

	if (first_member.get_sign() == '-' && second_member.get_sign() == '+')
	{
		int who_is_greater = 0;
		bool they_are_equal = true;

		for (int j = 0; j < first_member.get_size(); j++)
		{
			if (first_member[j] != second_member[j])
			{
				they_are_equal = false;
				break;
			}
		}

		if (they_are_equal && first_member.get_size() == 1)
		{
			rez[0] = 0;

			rez.sign = '#';

			return rez;
		}

		if (they_are_equal && first_member.get_size() > 1)
		{
			throw std::runtime_error("left the limits of the set boundaries.\n");
		}

		if (they_are_equal == false)
		{

			for (int i = 0; i < first_member.get_size(); i++)
			{
				if (second_member[i] > first_member[i])
				{
					who_is_greater = 2;
					break;
				}

				who_is_greater = 1;
			}
		}

		if (who_is_greater == 1)
		{

			int credit = 0;
			int tmp = 0;

			for (int a = first_member.get_size() - 1; a >= 0; a--)
			{
				if (a == first_member.get_size() - 1)
				{
					if (first_member[a] >= second_member[a])
					{
						rez[a] = first_member[a] - second_member[a];
					}

					if (first_member[a] < second_member[a])
					{
						credit = 1;
						rez[a] = (first_member[a] + 10) - second_member[a];
					}

					continue;
				}

				if (first_member[a] == 0)
				{
					if (second_member[a] != 0)
					{
						if (credit == 1)
						{
							credit = 1;
							rez[a] = 9 - second_member[a];
						}

						if (credit == 0)
						{
							credit = 1;
							rez[a] = 10 - second_member[a];
						}
					}

					if (second_member[a] == 0)
					{
						if (credit == 1)
						{
							rez[a] = 9;
						}

						if (credit == 0)
						{
							rez[a] = 0;
						}
					}
				}

				if (first_member[a] > 0)
				{
					tmp = first_member[a];
					tmp = tmp - credit;

					if (tmp == 0)
					{
						credit = 1;
						rez[a] = 10 - second_member[a];
					}

					if (tmp != 0 && tmp < second_member[a])
					{
						credit = 1;
						rez[a] = (tmp + 10) - second_member[a];
					}

					if (tmp >= second_member[a])
					{
						credit = 0;
						rez[a] = tmp - second_member[a];
					}
				}
			}

			if (rez.get_size() > 1 && rez[0] == 0)
			{
				throw std::runtime_error("left the limits of the set boundaries.\n");
			}

			rez.sign = '-';

			return rez;

		}

		if (who_is_greater == 2)
		{
			int credit = 0;
			int tmp = 0;

			for (int a = second_member.get_size() - 1; a >= 0; a--)
			{
				if (a == second_member.get_size() - 1)
				{
					if (second_member[a] >= first_member[a])
					{
						rez[a] = second_member[a] - first_member[a];
					}

					if (second_member[a] < first_member[a])
					{
						credit = 1;
						rez[a] = (second_member[a] + 10) - first_member[a];
					}

					continue;
				}

				if (second_member[a] == 0)
				{
					if (first_member[a] != 0)
					{
						if (credit == 1)
						{
							credit = 1;
							rez[a] = 9 - first_member[a];
						}

						if (credit == 0)
						{
							credit = 1;
							rez[a] = 10 - first_member[a];
						}
					}

					if (first_member[a] == 0)
					{
						if (credit == 1)
						{
							rez[a] = 9;
						}

						if (credit == 0)
						{
							rez[a] = 0;
						}
					}
				}

				if (second_member[a] > 0)
				{
					tmp = second_member[a];
					tmp = tmp - credit;

					if (tmp == 0)
					{
						credit = 1;
						rez[a] = 10 - first_member[a];
					}

					if (tmp != 0 && tmp < first_member[a])
					{
						credit = 1;
						rez[a] = (tmp + 10) - first_member[a];
					}

					if (tmp >= first_member[a])
					{
						credit = 0;
						rez[a] = tmp - first_member[a];
					}
				}
			}

			if (rez.get_size() > 1 && rez[0] == 0)
			{
				throw std::runtime_error("left the limits of the set boundaries.\n");
			}

			if (rez[0] == 0)
			{
				rez.sign = '#';
				return rez;
			}

			rez.sign = '+';

			return rez;

		}
	}

	if (first_member.get_sign() == '-' && second_member.get_sign() == '-')
	{
		int elder = 0;

		for (int c = first_member.get_size() - 1; c >= 0; c--)
		{
			rez[c] = first_member[c] + second_member[c];
			rez[c] = rez[c] + elder;

			if (c == 0)
			{
				if (rez[c] > 9)
				{
					throw std::runtime_error("Overflow.\n");
				}
			}

			if (rez[c] > 9)
			{
				rez[c] = rez[c] - 10;
				elder = 1;
				continue;
			}

			elder = 0;
		}

		rez.sign = '-';

		return rez;
	}

	if (first_member.get_sign() == '#')
	{
		return second_member;
	}

	if (second_member.get_sign() == '#')
	{
		return first_member;
	}

}

CIntN_Hori operator-(CIntN& first_member, CIntN& second_member)
{
	if (first_member.get_size() != second_member.get_size())
	{
		throw std::runtime_error("An attempt to perform calculations with vectors of different dimensions.\n");
	}

	CIntN_Hori rez(first_member.get_size()); 

	rez.filename = first_member.get_filename();

	if (first_member.get_sign() == '+' && second_member.get_sign() == '+') 
	{
		int who_is_greater = 0;
		bool they_are_equal = true;

		for (int j = 0; j < first_member.get_size(); j++)
		{
			if (first_member[j] != second_member[j])
			{
				they_are_equal = false;
				break;
			}
		}

		if (they_are_equal && first_member.get_size() == 1)
		{
			rez[0] = 0;

			rez.sign = '#';

			return rez;
		}

		if (they_are_equal && first_member.get_size() > 1)
		{
			throw std::runtime_error("left the limits of the set boundaries.\n");
		}

		if (they_are_equal == false)
		{

			for (int i = 0; i < first_member.get_size(); i++)
			{
				if (second_member[i] > first_member[i])
				{
					who_is_greater = 2;
					break;
				}

				who_is_greater = 1;
			}
		}

		if (who_is_greater == 1)
		{
			
			int credit = 0;
			int tmp = 0;

			for (int a = first_member.get_size() - 1; a >= 0; a--)
			{
				if (a == first_member.get_size() - 1)
				{
					if (first_member[a] >= second_member[a])
					{
						rez[a] = first_member[a] - second_member[a];
					}

					if (first_member[a] < second_member[a])
					{
						credit = 1;
						rez[a] = (first_member[a] + 10) - second_member[a];
					}

					continue;
				}

				if (first_member[a] == 0)
				{
					if (second_member[a] != 0)
					{
						if (credit == 1)
						{
							credit = 1;
							rez[a] = 9 - second_member[a];
						}

						if (credit == 0)
						{
							credit = 1;
							rez[a] = 10 - second_member[a];
						}
					}

					if (second_member[a] == 0)
					{
						if (credit == 1)
						{
							rez[a] = 9;
						}

						if (credit == 0)
						{
							rez[a] = 0;
						}
					}
				}

				if (first_member[a] > 0)
				{
					tmp = first_member[a];
					tmp = tmp - credit;

					if (tmp == 0)
					{
						credit = 1;
						rez[a] = 10 - second_member[a];
					}

					if (tmp != 0 && tmp < second_member[a])
					{
						credit = 1;
						rez[a] = (tmp + 10) - second_member[a];
					}

					if (tmp >= second_member[a])
					{
						credit = 0;
						rez[a] = tmp - second_member[a];
					}
				}
			}

			if (rez.get_size() > 1 && rez[0] == 0)
			{
				throw std::runtime_error("left the limits of the set boundaries.\n");
			}

			rez.sign = '+';

			return rez;

		}

		if (who_is_greater == 2)
		{
			int credit = 0;
			int tmp = 0;

			for (int a = second_member.get_size() - 1; a >= 0; a--)
			{
				if (a == second_member.get_size() - 1)
				{
					if (second_member[a] >= first_member[a])
					{
						rez[a] = second_member[a] - first_member[a];
					}

					if (second_member[a] < first_member[a])
					{
						credit = 1;
						rez[a] = (second_member[a] + 10) - first_member[a];
					}

					continue;
				}

				if (second_member[a] == 0)
				{
					if (first_member[a] != 0)
					{
						if (credit == 1)
						{
							credit = 1;
							rez[a] = 9 - first_member[a];
						}

						if (credit == 0)
						{
							credit = 1;
							rez[a] = 10 - first_member[a];
						}
					}

					if (first_member[a] == 0)
					{
						if (credit == 1)
						{
							rez[a] = 9;
						}

						if (credit == 0)
						{
							rez[a] = 0;
						}
					}
				}

				if (second_member[a] > 0)
				{
					tmp = second_member[a];
					tmp = tmp - credit;

					if (tmp == 0)
					{
						credit = 1;
						rez[a] = 10 - first_member[a];
					}

					if (tmp != 0 && tmp < first_member[a])
					{
						credit = 1;
						rez[a] = (tmp + 10) - first_member[a];
					}

					if (tmp >= first_member[a])
					{
						credit = 0;
						rez[a] = tmp - first_member[a];
					}
				}
			}

			if (rez.get_size() > 1 && rez[0] == 0)
			{
				throw std::runtime_error("left the limits of the set boundaries.\n");
			}

			if (rez[0] == 0)
			{
				rez.sign = '#';
				return rez;
			}

			rez.sign = '-';

			return rez;

		}
	}

	if (first_member.get_sign() == '+' && second_member.get_sign() == '-')
	{
		int elder = 0;

		for (int c = first_member.get_size() - 1; c >= 0; c--)
		{
			rez[c] = first_member[c] + second_member[c];
			rez[c] = rez[c] + elder;

			if (c == 0)
			{
				if (rez[c] > 9)
				{
					throw std::runtime_error("Overflow.\n");
				}
			}

			if (rez[c] > 9)
			{
				rez[c] = rez[c] - 10;
				elder = 1;
				continue;
			}

			elder = 0;
		}

		rez.sign = '+';

		return rez;
	} 

	if (first_member.get_sign() == '-' && second_member.get_sign() == '+') 
	{
		int elder = 0;

		for (int c = first_member.get_size() - 1; c >= 0; c--)
		{
			rez[c] = first_member[c] + second_member[c];
			rez[c] = rez[c] + elder;

			if (c == 0)
			{
				if (rez.arr[c] > 9)
				{
					throw std::runtime_error("Overflow.\n");
				}
			}

			if (rez[c] > 9)
			{
				rez[c] = rez.arr[c] - 10;
				elder = 1;
				continue;
			}

			elder = 0;
		}

		rez.sign = '-';

		return rez;
	} 

	if (second_member.get_sign() == '-' && first_member.get_sign() == '-')
	{
		int who_is_greater = 0;
		bool they_are_equal = true;

		for (int j = 0; j < first_member.get_size(); j++)
		{
			if (first_member[j] != second_member[j])
			{
				they_are_equal = false;
				break;
			}
		}

		if (they_are_equal && first_member.get_size() == 1)
		{
			rez[0] = 0;

			rez.sign = '#';

			return rez;
		}

		if (they_are_equal && first_member.get_size() > 1)
		{
			throw std::runtime_error("left the limits of the set boundaries.\n");
		}

		if (they_are_equal == false)
		{

			for (int i = 0; i < first_member.get_size(); i++)
			{
				if (second_member[i] > first_member[i])
				{
					who_is_greater = 2;
					break;
				}

				who_is_greater = 1;
			}
		}

		if (who_is_greater == 1)
		{

			int credit = 0;
			int tmp = 0;

			for (int a = first_member.get_size() - 1; a >= 0; a--)
			{
				if (a == first_member.get_size() - 1)
				{
					if (first_member[a] >= second_member[a])
					{
						rez[a] = first_member[a] - second_member[a];
					}

					if (first_member[a] < second_member[a])
					{
						credit = 1;
						rez[a] = (first_member[a] + 10) - second_member[a];
					}

					continue;
				}

				if (first_member[a] == 0)
				{
					if (second_member[a] != 0)
					{
						if (credit == 1)
						{
							credit = 1;
							rez[a] = 9 - second_member[a];
						}

						if (credit == 0)
						{
							credit = 1;
							rez[a] = 10 - second_member[a];
						}
					}

					if (second_member[a] == 0)
					{
						if (credit == 1)
						{
							rez[a] = 9;
						}

						if (credit == 0)
						{
							rez[a] = 0;
						}
					}
				}

				if (first_member[a] > 0)
				{
					tmp = first_member[a];
					tmp = tmp - credit;

					if (tmp == 0)
					{
						credit = 1;
						rez[a] = 10 - second_member[a];
					}

					if (tmp != 0 && tmp < second_member[a])
					{
						credit = 1;
						rez[a] = (tmp + 10) - second_member[a];
					}

					if (tmp >= second_member[a])
					{
						credit = 0;
						rez[a] = tmp - second_member[a];
					}
				}
			}

			if (rez.get_size() > 1 && rez[0] == 0)
			{
				throw std::runtime_error("left the limits of the set boundaries.\n");
			}

			rez.sign = '-';

			return rez;

		}

		if (who_is_greater == 2)
		{
			int credit = 0;
			int tmp = 0;

			for (int a = second_member.get_size() - 1; a >= 0; a--)
			{
				if (a == second_member.get_size() - 1)
				{
					if (second_member[a] >= first_member[a])
					{
						rez[a] = second_member[a] - first_member[a];
					}

					if (second_member[a] < first_member[a])
					{
						credit = 1;
						rez[a] = (second_member[a] + 10) - first_member[a];
					}

					continue;
				}

				if (second_member[a] == 0)
				{
					if (first_member[a] != 0)
					{
						if (credit == 1)
						{
							credit = 1;
							rez[a] = 9 - first_member[a];
						}

						if (credit == 0)
						{
							credit = 1;
							rez[a] = 10 - first_member[a];
						}
					}

					if (first_member[a] == 0)
					{
						if (credit == 1)
						{
							rez[a] = 9;
						}

						if (credit == 0)
						{
							rez[a] = 0;
						}
					}
				}

				if (second_member[a] > 0)
				{
					tmp = second_member[a];
					tmp = tmp - credit;

					if (tmp == 0)
					{
						credit = 1;
						rez[a] = 10 - first_member[a];
					}

					if (tmp != 0 && tmp < first_member[a])
					{
						credit = 1;
						rez[a] = (tmp + 10) - first_member[a];
					}

					if (tmp >= first_member[a])
					{
						credit = 0;
						rez[a] = tmp - first_member[a];
					}
				}
			}

			if (rez.get_size() > 1 && rez[0] == 0)
			{
				throw std::runtime_error("left the limits of the set boundaries.\n");
			}

			if (rez[0] == 0)
			{
				rez.sign = '#';
				return rez;
			}

			rez.sign = '+';

			return rez;

		}
	}

	if (first_member.get_sign() == '#')
	{
		return second_member;
	}

	if (second_member.get_sign() == '#')
	{
		return first_member;
	}
}