/******************************************************************
 * Problem 92 「桁の2乗による連鎖」  
 * 
 * 各桁の2乗を足し合わせて新たな数を作ることを, 同じ数が現れるまで繰り返す.
 * 例えば
 * 　　44 → 32 → 13 → 10 → 1 → 1
 * 　　85 → 89 → 145 → 42 → 20 → 4 → 16 → 37 → 58 → 89
 * のような列である. どちらも1か89で無限ループに陥っている. 
 * 驚くことに, どの数から始めても最終的に1か89に到達する.
 * では, 10,000,000より小さい数で89に到達する数はいくつあるか.
 ******************************************************************/
#include <iostream>
#include <assert.h>

int calcSquare(int n)
{
	int sum = 0;
	for (int tmp; n != 0; n /= 10) {
		tmp = n%10;
		sum += tmp * tmp;
	}
	return sum;
}

int is89(int n)
{
	while (n != 1 && n != 89)
		n = calcSquare(n);
	return (n == 89) ? true : false;
}

int problem92(void)
{
	int count = 0;
	for (int n = 1; n < 10000000; ++n)
		count += is89(n);
	return count;
}

int main(void)
{
	assert(is89(44) == false);
	assert(is89(85) == true);

	std::cout << problem92() << std::endl;
}

