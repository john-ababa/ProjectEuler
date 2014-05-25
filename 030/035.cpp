/******************************************************************
 * Problem 35 「巡回素数」
 * 
 * 197は巡回素数と呼ばれる.桁を回転させたときに得られる数 197, 971, 719 が全て素数だからである.
 * 100未満には巡回素数が13個ある:2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, および97である.
 * 100万未満の巡回素数はいくつあるか?
 ******************************************************************/
#include <iostream>
#include <algorithm>
#include <assert.h>
#include "../common/common.h"

bool isCircularPrime(int n)
{
	const std::string num_org = std::to_string(n);
	std::string num = std::to_string(n);

	do {
		if (!Euler::isPrime(stoi(num)))
			return false;
		std::rotate(num.begin(), num.begin()+1, num.end());
	} while (num != num_org);

	return true;
}

int problem35()
{
	int count = 0;
	for (int i = 0; i < 1000000; ++i)
		count += isCircularPrime(i);
	return count;
}

int main(void)
{
	assert(isCircularPrime(197) == true);

	std::cout << problem35() << std::endl;
}
