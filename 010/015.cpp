//////////////////////////////////////////////////////////////////////
// Problem 15
//
// 2 * 2 のマス目の左上からスタートした場合、
// 引き返しなしで右下にいくルートは 6 つある。
// [image here]
// では、20 * 20 のマス目ではいくつのルートがあるか。
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <assert.h>

// nCk = 
//     n!
// -----------
// k! * (n-k)!
double problem15(const int num)
{
	double n = 1;
	for (int i = 1; i <= num*2; ++i)
		n *= i;
	double k = 1;
	for (int i = 1; i <= num; ++i)
		k *= i;
	return n/(k*k);
}

int main(void)
{
	assert((int)problem15(2) == 6);

	std::cout << std::fixed << std::setprecision(0) << problem15(20) << std::endl;
}
