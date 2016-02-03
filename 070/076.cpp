/******************************************************************
 * Problem 76 「和の数え上げ」  
 * 
 * 5は数の和として6通りに書くことができる:
 * 4 + 1
 * 3 + 2
 * 3 + 1 + 1
 * 2 + 2 + 1
 * 2 + 1 + 1 + 1
 * 1 + 1 + 1 + 1 + 1
 * 2つ以上の正整数の和としての100の表し方は何通りか.
 ******************************************************************/
#include <iostream>
#include <vector>
#include <assert.h>

int problem31(const std::vector<int>& vec, const int sum, const int c)
{
	int count = 0;
	if (!c)
		return 1;

	for (int n = sum; n >= 0; n -= vec[c])
		count += problem31(vec, n, c-1);
	return count;
}

int problem76(const int n)
{
	std::vector<int> vec(n+1);
	for (int i = 0; i <= n; ++i)
		vec[i] = i+1;
	return problem31(vec, n, n) - 1;
}

int main(void)
{
	assert(problem76(5) == 6);

	std::cout << problem76(100) << std::endl;
}
