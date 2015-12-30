/******************************************************************
 * Problem 69  
 * 
 * オイラーのトーティエント関数、Φ(n)[時々ファイ関数とも呼ばれる]は、
 * nと互いに素なn未満の数の数を定める。
 * たとえば、1,2,4,5,7 そして8はみな9未満で9と互いに素であり、Φ(9)=6.
 *   | n  | 互いに素な数 | Φ(n) | n/Φ(n)
 *   | 2  | 1            | 1     | 2
 *   | 3  | 1,2          | 2     | 1.5
 *   | 4  | 1,3          | 2     | 2
 *   | 5  | 1,2,3,4      | 4     | 1.25
 *   | 6  | 1,5          | 2     | 3
 *   | 7  | 1,2,3,4,5,6  | 6     | 1.1666...
 *   | 8  | 1,3,5,7      | 4     | 2
 *   | 9  | 1,2,4,5,7,8  | 6     | 1.5
 *   | 10 | 1,3,7,9      | 4     | 2.5
 * n ≤ 10ではn/Φ(n)の最大値はn=6であることがわかる。
 * n ≤ 1,000,000で n/Φ(n) が最大となる値を見つけよ。
 ******************************************************************/
#include <iostream>
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

int problem69(void)
{
	int maxn = 0;
	double maxpn = 0;

	for (int i = 1; i < 1000000 ; ++i) {
		const double tmp = (double)i / (double)phi(i);
		if (maxpn < tmp) {
			maxpn = tmp;
			maxn = i;
		}
	}
	return maxn;
}

int main(void)
{
	assert((6 / phi(6)) == 3);

	std::cout << problem69() << std::endl;
}
