/******************************************************************
 * Problem 37 「切り詰め可能素数」
 * 
 * 3797は面白い性質を持っている. まずそれ自身が素数であり,
 * 左から右に桁を除いたときに全て素数になっている (3797, 797, 97, 7).
 * 同様に右から左に桁を除いたときも全て素数である (3797, 379, 37, 3).
 * 
 * 右から切り詰めても左から切り詰めても素数になるような素数は11個しかない. 総和を求めよ.
 * 注: 2, 3, 5, 7を切り詰め可能な素数とは考えない.
 ******************************************************************/
#include <iostream>
#include <string>
#include <assert.h>
#include "../common/common.h"

bool isTruncatablePrime(const int n)
{
	for (int RtoL = n/10; RtoL != 0; RtoL /= 10) {
		if (!Euler::isPrime(RtoL))
			return false;
	}
	for (std::string LtoR = std::to_string(n); !LtoR.empty(); LtoR = LtoR.substr(1)) {
		if (!Euler::isPrime(std::stoi(LtoR)))
			return false;
	}
	return true;
}

int problem37()
{
	int sum = 0, count = 0;
	for (int n = 8; count != 11; ++n) {
		if (isTruncatablePrime(n)) {
			sum += n;
			++count;
		}
	}
	return sum;
}

int main(void)
{
	assert(isTruncatablePrime(3797) == true);

	std::cout << problem37() << std::endl;
}
