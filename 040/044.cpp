/******************************************************************
 * Problem 44 「五角数」
 * 
 * 五角数は Pn = n(3n-1)/2 で生成される. 最初の10項は
 *   1, 5, 12, 22, 35, 51, 70, 92, 117, 145, ...
 * である.
 * 
 * P4 + P7 = 22 + 70 = 92 = P8 である.
 * しかし差 70 - 22 = 48 は五角数ではない.
 * 
 * 五角数のペア Pj と Pk について, 差と和が五角数になるものを考える.
 * 差を D = |Pk - Pj| と書く. 差 D の最小値を求めよ.
 ******************************************************************/
#include <iostream>
#include <cmath>
#include <assert.h>

bool isPentagon(int p)
{
	// p=n*(3*n-1)/2 => n=(1+(1+24*p)^(1/2))/6
	double n = (1.0 + std::sqrt(1 + 24*p)) / 6.0;
	if (n - (int)n < 0.0001)
		return true;
	else
		return false;
}

#define p(n) ((n * (3*n - 1)) / 2)

int problem44(void)
{
	int min = 99999999;

	for (int j = 1; j < 10000; ++j) {
		for (int k = j + 1; k < 10000; ++k) {
			const int diff = p(k) - p(j);
			if (min < diff)
				break;
			if (isPentagon(diff) && isPentagon(p(j) + p(k)))
				min = diff;
		}
	}
	return min;
}

int main(void)
{
	assert(p(4) + p(7) == 92);
	assert(isPentagon(p(4) + p(7)) == true);
	assert(isPentagon(p(7) - p(4)) == false);

	std::cout << problem44() << std::endl;
}
