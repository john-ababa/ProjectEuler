//////////////////////////////////////////////////////////////////////
// Problem 10
//
// 10以下の素数の和は2 + 3 + 5 + 7 = 17である.
// 200万以下の全ての素数の和を計算しなさい.
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <assert.h>
#include "../common/common.h"

long problem10(const int n)
{
	long sum = 2; // skip number 2
	for (int i = 3; i < n; i+=2) {
		if (Euler::isPrime(i))
			sum += i;
	}
	return sum;
}

int main(void)
{
	assert(problem10(10) == 17);

	std::cout << problem10(2000000) << std::endl;
}
