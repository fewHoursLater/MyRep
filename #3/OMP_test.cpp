#include "Header.h"
#include "OMP_test.h"
#include "CIntN.h"
#include "CIntN_Hori.h"
#include "CIntN_Vert.h"

void OMP_test(const int N, const int dim)
{
	vector<CIntN_Hori> storage1;
	vector<CIntN_Hori> storage2;
	vector<CIntN_Hori> result;

	for (int i = 0; i < N; i++)
	{
		CIntN_Hori a(dim,"a.txt",'+');
		CIntN_Hori b(dim, "b.txt", '+');

		for (int j = 0; j < dim; j++)
		{

			srand(time(NULL));

			if (j == 0)
			{
				if (dim == 1)
				{
					a[j] = rand() % 4;
					b[j] = rand() % 4;

					continue;
				}
				
				if (dim != 1)
				{
					a[j] = rand() % 4 + 1;
					b[j] = rand() % 4 + 1;

					continue;
				}

			}

			a[j] = rand() % 9;
			b[j] = rand() % 9;
		}

		storage1.push_back(a);
		storage2.push_back(b);
	}

	for (int y = 0; y < N; y++)
	{
		CIntN_Hori c(dim, "c.txt", '+');

		result.push_back(c);
	}

	auto start = high_resolution_clock::now();

#pragma omp parallel for

	for (int q = 0; q < N; q++)
	{
		
		result[q] = storage1[q] + storage2[q];
		
	}
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);

	cout << "==================" << endl;
	cout << duration.count() << " microseconds." << endl;
	cout << "==================" << endl;

}