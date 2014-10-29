/******************************************************************
 * Problem 50 「連続する素数の和」
 * 
 * 素数41は6つの連続する素数の和として表せる:
 * 41 = 2 + 3 + 5 + 7 + 11 + 13.
 * 
 * 100未満の素数を連続する素数の和で表したときにこれが最長になる.
 * 同様に, 連続する素数の和で1000未満の素数を表したときに最長になるのは953で21項を持つ.
 * 100万未満の素数を連続する素数の和で表したときに最長になるのはどの素数か?
 ******************************************************************/
#include <iostream>
#include <vector>
#include <assert.h>
#include "../common/common.h"

int check(const int n, const std::vector<int>& vec)
{
	int max = 0, sum = 0, count = 0;

	for (auto itr = vec.begin(); *itr < n/5; ++itr) {
		for (auto jtr = itr; sum < n; ++jtr, ++count)
			sum += *jtr;
		if (sum == n && max < count)
			max = count;
		--count;
		sum -= *itr;
	}
	return max;
}

int problem50(const int n)
{
	std::vector<int> primes;
	primes.reserve(n);

	for (int i = 2; i < n; ++i) {
		if (Euler::isPrime(i))
			primes.push_back(i);
	}

	int max_num = 0, max_count = 0;
	for (auto itr = primes.begin(); itr != primes.end(); ++itr) {
		const int count = check(*itr, primes);
		if (max_count < count) {
			max_count = count;
			max_num = *itr;
		}
	}
	return max_num;
}

int main(void)
{
	assert(problem50(100) == 41);
	assert(problem50(1000) == 953);

	std::cout << problem50(1000000) << std::endl;
}
