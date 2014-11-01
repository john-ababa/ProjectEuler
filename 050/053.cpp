/******************************************************************
 * Problem 53 「組み合わせ選択」
 * 
 * 12345から3つ選ぶ選び方は10通りである.
 * 123, 124, 125, 134, 135, 145, 234, 235, 245, 345.
 * 
 * 組み合わせでは, 以下の記法を用いてこのことを表す: 5C3 = 10.
 * 一般に, r <= n について nCr = n!/(r!(n-r)!) である
 * ここで, n! = n*(n−1)*...*3*2*1, 0! = 1 と階乗を定義する.
 * 
 * n = 23 になるまで, これらの値が100万を超えることはない: 23C10 = 1144066.
 * 1 <= n <= 100 について, 100万を超える nCr は何通りあるか?
 ******************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

std::vector<int> factorization(int n)
{
	std::vector<int> vec;

	for (int i = 2; n != 1 && i != n; i+=1) {
		while (n % i == 0) {
			vec.push_back(i);
			n /= i;
		}
	}
	vec.push_back(n);
	return vec;
}

long double combination(const int N, const int R)
{
	std::vector<int> ns;
	for (int i = 0; i < N - R; ++i) {
		std::vector<int> tmp = factorization(N - i);
		ns.insert(ns.end(), tmp.begin(), tmp.end());
	}

	std::vector<int> ds;
	for (int i = 2; i <= N - R; ++i) {
		std::vector<int> tmp = factorization(i);
		ds.insert(ds.end(), tmp.begin(), tmp.end());
	}

	long double d = 1.0;
	for (auto itr = ds.begin(); itr != ds.end(); ++itr) {
		auto p = std::find(ns.begin(), ns.end(), *itr);
		if (p != ns.end())
			*p = 1;
		else
			d *= *itr;
	}

	long double n = 1.0;
	for (auto itr = ns.begin(); itr != ns.end(); ++itr)
		n *= *itr;

	return n / d;
}

int problem53()
{
	int count = 0;

	for (int n = 1; n <= 100; ++n) {
		for (int r = 1; r <= n; ++r) {
			if (combination(n, r) >= 1000000.0)
				count++;
		}
	}
	return count;
}

int main(void)
{
	assert(combination(5, 3) == 10);
	assert(combination(23, 10) == 1144066);

	std::cout << problem53() << std::endl;
}
