//////////////////////////////////////////////////////////////////////
// Problem 7
//
// 素数を小さい方から6つ並べると 2, 3, 5, 7, 11, 13 であり
// 6番目の素数は 13 である。10001 番目の素数を求めよ。
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cmath>
#include <assert.h>

bool isPrime(int n)
{
	if ((n != 2 && n % 2 == 0) || n <= 1)
		return false;
	const int limit = std::sqrt(n);
	for (int i = 3; i <= limit; i += 2)
		if (n % i == 0)
			return false;
	return true;
}

int problem7(int n)
{
	int i, count = 1; // skip prim number 2
	for (i = 3; count != n; i+=2) {
		if (isPrime(i))
			++count;
	}
	return i-2;
}

int main(void)
{
	assert(problem7(6) == 13);

	std::cout << problem7(10001) << std::endl;
}
