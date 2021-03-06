//////////////////////////////////////////////////////////////////////
// Problem 30  
// 
// 驚くべきことに, 各桁を4乗した和が元の数と一致する数は3つしかない.
// 1634 = 1^4 + 6^4 + 3^4 + 4^4
// 8208 = 8^4 + 2^4 + 0^4 + 8^4
// 9474 = 9^4 + 4^4 + 7^4 + 4^4
// ただし, 1=1^4は含まないものとする.
// この数たちの和は 1634 + 8208 + 9474 = 19316 である.
// 各桁を5乗した和が元の数と一致するような数の総和を求めよ.
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <cmath>

int main(void)
{
	std::vector<int> vec(10);
	for (int i = 0; i < 10; ++i)
		vec[i] = std::pow(i, 5);

	int ans = 0;
	for (int i = 2; i < 1000000; ++i) {
		int n = 0;
		for (int t = i; n < t || t != 0; t /= 10)
			n += vec[t%10];
		if (n == i)
			ans += i;
	}
	std::cout << ans << std::endl;
}
