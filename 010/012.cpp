//////////////////////////////////////////////////////////////////////
// Problem 12
//
// 三角数の数列は自然数の和で表わされ、
// 7番目の三角数は 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28 である。
//
// 三角数の最初の10項は
//     1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
// となる。
//
// 最初の7項について、その約数を列挙すると、以下のとおり。
//     1: 1
//     3: 1,3
//     6: 1,2,3,6
//     10: 1,2,5,10
//     15: 1,3,5,15
//     21: 1,3,7,21
//     28: 1,2,4,7,14,28
// これから、7番目の三角数である28は、6個以上の約数をもつ最初の三角数であることが分る。
// では、501 個以上の約数をもつ最初の三角数はいくらか。
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <assert.h>
#include "../common/common.h"

inline int triangleN(const int n)
{
	return (n * (n+1)) / 2;
}

int factors(int num)
{
	int count = 1;
	for (int i = 2; i <= num; ) {
		int factor = 0;
		while (num % i == 0) {
			factor++;
			num /= i;
		}
		// n = (a^i)+(b^j)+(c^k)...
		// d(n) = (i+1)*(b+1)*(c+1)...
		count *= factor + 1;

		while (!Euler::isPrime(++i))
			;
	}
	return count;
}

int problem12()
{
	for (int n = 1; ; ++n) {
		const int triangle = triangleN(n);
		if (500 < factors(triangle))
			return triangle;
	}
}

int main(void)
{
	assert(triangleN(7) == 28);
	assert(factors(28) == 6);

	std::cout << problem12() << std::endl;
}
