//////////////////////////////////////////////////////////////////////
// Problem 9
//
// ピタゴラスの三つ組(ピタゴラスの定理を満たす自然数)とはa<b<cで
// a^2 + b^2 = c^2 を満たす数の組である.
// 例えば, 3^2 + 4^2 = 9 + 16 = 25 = 5^2である.
// a + b + c = 1000となるピタゴラスの三つ組が一つだけ存在する.
// このa,b,cの積を計算しなさい.
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cmath>
#include <assert.h>

bool isPythagoras(const int a, const int b, const int c)
{
	return (std::pow(a, 2) + std::pow(b, 2) == std::pow(c, 2));
}

int problem9()
{
	for (int a = 1; a < 333; ++a) {
		for (int b = a+1; a+b != 1000; ++b) {
			const int c = 1000-b-a;
			if (isPythagoras(a, b, c))
				return a * b * c;
		}
	}
	return -1;
}


int main(void)
{
	assert(isPythagoras(3, 4, 5));

	std::cout << problem9() << std::endl;
}
