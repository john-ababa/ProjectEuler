/******************************************************************
 * Problem 48 「自身のべき乗(self powers)」
 * 
 * 次の式は, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317 である.
 * では, 1^1 + 2^2 + 3^3 + ... + 1000^1000 の最後の10桁を求めよ.
 ******************************************************************/
#include <iostream>
#include <assert.h>

const long keta = 10000000000l;

long pow(int x, int y)
{
	long num = 1;
	while (y-- != 0)
		num = (num * x) % keta;
	return num;
}

long problem48(const int n)
{
	long sum = 0;
	for (int i = 1; i <= n; ++i)
		sum = (sum + pow(i, i)) % keta;
	return sum;
}

int main(void)
{
	assert(problem48(10) == 405071317l);

	std::cout << problem48(1000) << std::endl;
}
