/******************************************************************
 * Problem 77 「素数の和」  
 * 
 * 10は素数の和として5通りに表すことができる:
 * 7 + 3
 * 5 + 5
 * 5 + 3 + 2
 * 3 + 3 + 2 + 2
 * 2 + 2 + 2 + 2 + 2
 * 素数の和としての表し方が5000通り以上になる最初の数を求めよ.
 ******************************************************************/
#include <iostream>
#include <vector>
#include <assert.h>
#include "../common/common.h"

int problem31(const std::vector<int>& vec, const int sum, const int c)
{
	int count = 0;
	if (sum == 0)
		return 1;

	for (int n = sum; c >= 0 && n >= 0; n -= vec[c])
		count += problem31(vec, n, c-1);
	return count;
}

int problem77(const int N)
{
	std::vector<int> vec;
	for (int i = 2; i <= N; ++i) {
		if (Euler::isPrime(i))
			vec.push_back(i);
	}
	
	for (int n = 2; n <= N; ++n) {
		if (problem31(vec, n, vec.size()-1) >= 5000)
			return n;
	}
	return -1;
}

int main(void)
{
	std::cout << problem77(5000) << std::endl;
}
