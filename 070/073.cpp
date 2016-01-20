/******************************************************************
 * Problem 73 「ある範囲内の分数の数え上げ」  
 * 
 * nとdを正の整数として, 分数 n/d を考えよう.
 * n<d かつ HCF(n,d)=1 のとき, 真既約分数と呼ぶ.
 * d ≤ 8 について既約分数を大きさ順に並べると, 以下を得る:
 *   1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7,
 *   1/2, 4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8
 * 1/3と1/2の間には3つの分数が存在することが分かる.
 * では, d ≤ 12,000 について真既約分数をソートした集合では,
 * 1/3 と 1/2 の間に何個の分数があるか?
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

double div1(int n, int d)
{
	return (double)n / (double)d;
}

int problem73(const int N)
{
	const double t1 = div1(1, 3), t2 = div1(1, 2);
	int count = 0;

	for (int d = 2; d <= N; ++d) {
		for (int n = (double)d*t1; div1(n, d) < t2; ++n) {
			const double tmp = div1(n, d);
			if (t1 < tmp && tmp < t2 && HCF(n, d) == 1)
				++count;
		}
	}
	return count;
}

int main(void)
{
	assert(problem73(8) == 3);

	std::cout << problem73(12000) << std::endl;
}
