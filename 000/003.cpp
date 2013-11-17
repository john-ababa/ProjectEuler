//////////////////////////////////////////////////////////////////////
// Problem 3
//
// 13195 の素因数は 5、7、13、29 である。
// 600851475143 の素因数のうち最大のものを求めよ。
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <assert.h>

int problem3(long long n)
{
 	if (n <= 1) return 1;
 	while (n % 2 == 0)
 		n /= 2;
 	if (n <= 1) return 2;

	int i;
	for (i = 3; n != 1 && i != n; i+=2) {
		while (n % i == 0)
			n /= i;
	}
 	return i;
}

int main(void)
{
	assert(problem3(13195) == 29);

	std::cout << problem3(600851475143LL) << std::endl;
}
