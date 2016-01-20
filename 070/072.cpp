/******************************************************************
 * Problem 72 「分数の数え上げ」  
 * 
 * nとdを正の整数として, 分数 n/d を考えよう.
 * n < d かつ HCF(n,d)=1 のとき, 真既約分数と呼ぶ.
 * d ≤ 8について真既約分数を大きさ順に並べると, 以下を得る:
 *   1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7,
 *   1/2, 4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8
 * この集合は21個の要素をもつことが分かる.
 * d ≤ 1,000,000について, 真既約分数の集合は何個の要素を持つか?
 ******************************************************************/
#include <iostream>
#include <assert.h>
#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;

int phi(int n)
{
	int result = n;
	for (int i = 2; i*i <= n; ++i) {
		if (n % i == 0)
			result -= result / i;
		while (n % i == 0)
			n /= i;
	}
	if (n > 1)
		result -= result / n;
	return result;
}

cpp_int problem72(const int N)
{
	cpp_int count = 0;
	for (int d = 2; d <= N; ++d)
		count += phi(d);
	return count;
}

int main(void)
{
	assert(problem72(8) == 21);

	std::cout << problem72(1000000) << std::endl;
}
