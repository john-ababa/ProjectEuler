/******************************************************************
 * Problem 56 「もっとべき乗の数字和」
 * 
 * Googol (10^100)は非常に大きな数である: 1の後に0が100個続く. 100^100は想像を絶する.
 * 1の後に0が200回続く. その大きさにも関わらず, 両者とも数字和 ( 桁の和 ) は1である.
 * 
 * a, b < 100 について自然数 a^b を考える. 数字和の最大値を答えよ.
 ******************************************************************/
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include "../common/bignum.hpp"

int sumDigital(const std::string& str)
{
	return std::accumulate(str.begin(), str.end(), 0) - '0' * str.size();
}

int problem056()
{
	int max = 0;

	for (int a = 1; a < 100; a+=1) {
		BigNum A(std::to_string(a));
		BigNum B(std::to_string(a));
		for (int b = 1; b < 100; b+=1) {
			A *= B;
			max = std::max(max, sumDigital(A.to_string()));
		}
	}
	return max;
}

int main(void)
{
	std::cout << problem056() << std::endl;
}
