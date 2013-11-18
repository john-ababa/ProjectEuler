//////////////////////////////////////////////////////////////////////
// Problem 6
//
// 最初の10個の自然数について、その和の二乗と、二乗数の和は以下の通り。
// 1^2 + 2^2 + ... + 10^2 = 385
// (1 + 2 + ... + 10)^2 = 3025
// これらの数の差は 3025 - 385 = 2640 となる。
// 同様にして、最初の100個の自然数について和の二乗と二乗の和の差を求めよ。
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <assert.h>

int problem6(const int n)
{
	int square_of_sum = 0;
	int sum_of_square = 0;

	for (int i = 1; i <= n; ++i) {
		square_of_sum += i*i;
		sum_of_square += i;
	}

	return (sum_of_square * sum_of_square) - square_of_sum;
}

int main(void)
{
	assert(problem6(10) == 2640);

	std::cout << problem6(100) << std::endl;
}
