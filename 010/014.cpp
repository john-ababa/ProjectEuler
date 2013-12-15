//////////////////////////////////////////////////////////////////////
// Problem 14
//
// 正の整数に以下の式で繰り返し生成する数列を定義する。
//     n → n/2 (n が偶数)
//     n → 3n + 1 (n が奇数)
// 13からはじめるとこの数列は以下のようになる。
//     13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
// 13から1まで10個の項になる。
// この数列はどのような数字からはじめても最終的には 1 になると考えられているが、
// まだそのことは証明されていない(コラッツ問題)
//
// さて、100万未満の数字の中でどの数字からはじめれば一番長い数列を生成するか。
// 注意: 数列の途中で100万以上になってもよい
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cmath>
#include <assert.h>

int collatz(long long n)
{
	int count;
	for (count = 1; n != 1; ++count) {
		if (n % 2 == 0)
			n /= 2;
		else
			n = 3*n + 1;
	}
	return count;
}

int problem14()
{
	int max_number = 0, max_count = 0;

	for (int n = 1; n < 1000000; ++n) {
		const int count = collatz(n);
		if (max_count < count) {
			max_count = count;
			max_number = n;
		}
	}
	return max_number;
}


int main(void)
{
	assert(collatz(13) == 10);

	std::cout << problem14() << std::endl;
}
