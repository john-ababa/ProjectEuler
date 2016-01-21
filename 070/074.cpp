/******************************************************************
 * Problem 74 「桁の階乗による連鎖」  
 * 
 * 145は各桁の階乗の和が145と自分自身に一致することで有名である.
 *   1! + 4! + 5! = 1 + 24 + 120 = 145
 * 169の性質はあまり知られていない. これは169に戻る数の中で最長の列を成す.
 * このように他の数を経て自分自身に戻るループは3つしか存在しない.
 *   169 → 363601 → 1454 → 169
 *   871 → 45361 → 871
 *   872 → 45362 → 872
 * どのような数からスタートしてもループに入ることが示せる. 例を見てみよう.
 *   69 → 363600 → 1454 → 169 → 363601 (→ 1454)
 *   78 → 45360 → 871 → 45361 (→ 871)
 *   540 → 145 (→ 145)
 * 69から始めた場合, 列は5つの循環しない項を持つ.  また100万未満の
 * 数から始めた場合最長の循環しない項は60個であることが知られている.
 * 100万未満の数から開始する列の中で, 60個の循環しない項を持つものはいくつあるか?
 ******************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

int factorial(const int N)
{
	int fact = 1;
	for (int n = 2; n <= N; ++n)
		fact *= n;
	return fact;
}

int factorialSum(const int N)
{
	int fact = 0;
	for (int n = N ; n != 0; n /= 10)
		fact += factorial(n % 10);
	return fact;
}

int repeatCounter(int fact)
{
	std::vector<int> vec;
	do {
		vec.push_back(fact);
		fact = factorialSum(fact);
	} while (std::find(vec.cbegin(), vec.cend(), fact) == vec.cend());
	return vec.size();
}

int problem74(void)
{
	int count = 0;
	for (int n = 1; n < 1000000; ++n) {
		if (repeatCounter(n) == 60)
			++count;
	}
	return count;
}

int main(void)
{
	assert(repeatCounter(69) == 5);

	std::cout << problem74() << std::endl;
}
