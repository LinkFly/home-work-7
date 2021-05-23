#include "mylib.h"
#include <cstdlib>
#include <iostream>

namespace ns_arrays {

using namespace std;

void init_array(float ar[], size_t size)
{
	static auto gen = []() {
		return 1.f * ((rand() % 3) - 1);
	};
	for (size_t i = 0; i < size; i++)
	{
		ar[i] = gen(); 
	}
}

void print_array(float ar[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << ar[i] << " ";
	}
}

void neg_pos_count(float ar[], size_t size, unsigned& negc, unsigned& posc)
{
	negc = 0, posc = 0;
	for (size_t i = 0; i < size; ++i)
	{
		if (ar[i] != 0)
			ar[i] < 0 ? ++negc : ++posc;
	}
}

} // ns_arrays namespace