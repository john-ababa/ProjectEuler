/******************************************************************
 * Problem 70 「トーティエント関数の置換」  
 * 
 * オイラーのトーティエント関数 φ(n) (ファイ関数とも呼ばれる) とは,
 * n 未満の正の整数で n と互いに素なものの個数を表す.
 * 例えば 1,2,4,5,7,8 は9未満で9と互いに素であるので, φ(9) = 6 となる. 
 * 1 は全ての正の整数と互いに素であるとみなされる. よって φ(1) = 1 である.
 * 面白いことに, φ(87109)=79180 であり, 87109は79180を置換したものとなっている.
 *
 * 1 < n < 10^7 で φ(n) が n を置換したものになっているもののうち,
 * n/φ(n) が最小となる n を求めよ.
 ******************************************************************/
#include <iostream>
#include <string>
#include <algorithm>
#include <assert.h>

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

bool isPermutation(int n1, int n2)
{
	std::string s1 = std::to_string(n1);
	std::sort(s1.begin(), s1.end());

	std::string s2 = std::to_string(n2);
	std::sort(s2.begin(), s2.end());

	return (s1 == s2) ? true : false;
}

int problem70(void)
{
	int minn = 0;
	double minpn = 10000000;

	for (int i = 2; i < 10000000; ++i) {
		const double p = phi(i);
		const double tmp = (double)i / p;
		if (minpn > tmp && isPermutation(i, p)) {
			minpn = tmp;
			minn = i;
		}
	}
	return minn;
}

int main(void)
{
	assert(isPermutation(87109, phi(87109)) == true);

	std::cout << problem70() << std::endl;
}
