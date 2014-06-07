/******************************************************************
 * Problem 46 「もうひとつのゴールドバッハの予想」

 * Christian Goldbachは全ての奇合成数は平方数の2倍と素数の和で表せると予想した.
 *   9 = 7 + 2×1^2
 *   15 = 7 + 2×2^2
 *   21 = 3 + 2×3^2
 *   25 = 7 + 2×3^2
 *   27 = 19 + 2×2^2
 *   33 = 31 + 2×1^2
 *
 * 後に, この予想は誤りであることが分かった.
 * 平方数の2倍と素数の和で表せない最小の奇合成数はいくつか?
 ******************************************************************/
#include <iostream>
#include <cmath>
#include <assert.h>
#include "../common/common.h"

bool isGoldbach(const int n)
{
	for (int i = 2; i < n; ++i) {
		const int prime = (n - i);
		if (!Euler::isPrime(prime))
			continue;

		const int diff = (n - prime) / 2;
		const int square = (int)std::sqrt(diff) * (int)std::sqrt(diff);
		if (prime + 2*square == n)
			return true;
	}
	return false;
}

int problem46(void)
{
	for (int n = 3; ; n += 2) {
		if (Euler::isPrime(n))
			continue;
		if (!isGoldbach(n))
			return n;
	}
	return -1;
}

int main(void)
{
	assert(isGoldbach(33) == true);

	std::cout << problem46() << std::endl;
}
