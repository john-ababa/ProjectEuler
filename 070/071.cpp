/******************************************************************
 * Problem 71 「順序分数」  
 * 
 * nとdを正の整数として, 分数 n/d を考えよう.
 * n < d かつ HCF(n,d) = 1 のとき, 真既約分数と呼ぶ.
 * d ≤ 8について既約分数を大きさ順に並べると, 以下を得る:
 *   1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7,
 *   1/2, 4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8
 * 3/7のすぐ左の分数は2/5である.
 * d ≤ 1,000,000について真既約分数を大きさ順に並べたとき, 3/7のすぐ左の分数の分子を求めよ.
 ******************************************************************/
#include <iostream>
#include <assert.h>

int HCF(int n, int d)
{
	for (int k = -1; k != 0; ) {
		k = d % n;
		d = n;
		n = k;
	}
	return d;
}

int problem71(const int N)
{
	double target = 3.0/7.0, left = 0;
	int numer = 0;

	for (int d = 2; d < N; ++d) {
		for (int n = (double)d*3.0/7.0; (double)n/(double)d < target; ++n) {
			const double tmp = (double)n/(double)d;
			if (left < tmp && HCF(n, d) == 1) {
				left = tmp;
				numer = n;
			}
		}
	}
	return numer;
}

int main(void)
{
	assert(problem71(8) == 2);

	std::cout << problem71(1000000) << std::endl;
}
