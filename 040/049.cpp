/******************************************************************
 * Problem 49 「素数数列」
 * 
 * 項差3330の等差数列1487, 4817, 8147は次の2つの変わった性質を持つ.
 *   (i) 3つの項はそれぞれ素数である.
 *   (ii) 各項は他の項の置換で表される.
 * 1, 2, 3桁の素数にはこのような性質を持った数列は存在しないが,
 * 4桁の増加列にはもう1つ存在する.
 * 
 * それではこの数列の3つの項を連結した12桁の数を求めよ.
 ******************************************************************/
#include <iostream>
#include <vector>
#include <assert.h>
#include "../common/common.h"

std::vector<int> sprit(int n)
{
	std::vector<int> v(10, 0);
	while (n != 0) {
		++v[n % 10];
		n /= 10;
	}
	return v;
}

bool check(int a, int b, int c)
{
	if (Euler::isPrime(a) && Euler::isPrime(b) && Euler::isPrime(c) &&
		(b - a == c - b) && (sprit(a) == sprit(b)) && (sprit(a) == sprit(c)))
		return true;
	return false;
}

long problem49()
{
	std::vector<int> primes;
	primes.reserve(10000);
	for (int i = 1001; i < 10000; i+=2) {
		if (Euler::isPrime(i))
			primes.push_back(i);
	}

	for (auto itr = primes.begin(); itr != primes.end()-2; ++itr) {
		for (auto jtr = itr+1; jtr != primes.end()-1; ++jtr) {
			const int k = *jtr + (*jtr - *itr);
			if (k < 10000 && *itr != 1487 && check(*itr, *jtr, k))
				return ((long)*itr * 100000000L) + (*jtr * 10000) + k;
		}
	}
	return -1;
}

int main(void)
{
	assert(check(1487, 4817, 8147) == true);
	std::cout << problem49() << std::endl;
}
