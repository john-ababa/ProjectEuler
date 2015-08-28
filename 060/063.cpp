/******************************************************************
 * Problem 63 †
 * 
 * 5桁の数 16807 = 7^5は自然数を5乗した数である.
 * 同様に9桁の数 134217728 = 8^9も自然数を9乗した数である.
 * 
 * 自然数をn乗して得られるn桁の正整数は何個あるか?
 ******************************************************************/
#include <iostream>
#include <string>
#include "../common/bignum.hpp"

int problem063()
{
	int count = 0;
	for (int i = 1; i < 10; ++i) {
		BigNum A(std::to_string(i));
		BigNum B(std::to_string(i));
		for (int j = 1; j < 100; ++j) {
			if (j == (int)A.to_string().length())
				count++;
			A *= B;
		}
	}
	return count;
}

int main(void)
{
	std::cout << problem063() << std::endl;
}
