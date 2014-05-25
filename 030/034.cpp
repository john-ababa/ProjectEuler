/*
 * Problem 34 「桁の階乗」
 *
 * 145は面白い数である. 1! + 4! + 5! = 1 + 24 + 120 = 145となる.
 * 各桁の数の階乗の和が自分自身と一致するような数の和を求めよ.
 * 注: 1! = 1 と 2! = 2 は総和に含めてはならない.
 */
#include <iostream>
#include <assert.h>

const int factorial[] = {
	1,                // 0!
	1,                // 1!
	1*2,              // 2!
	1*2*3,            // 3!
	1*2*3*4,          // 4!
	1*2*3*4*5,        // 5!
	1*2*3*4*5*6,      // 6!
	1*2*3*4*5*6*7,    // 7!
	1*2*3*4*5*6*7*8,  // 8!
	1*2*3*4*5*6*7*8*9 // 9!
};

int check(const int num)
{
	int sum = 0;
	for (int n = num; n != 0; n /= 10)
		sum += factorial[n%10];
	return (num == sum) ? num : 0;
}

int problem45()
{
	const int limit = factorial[9]*7;

	int result = 0;
	for (int n = 3; n < limit; ++n)
		result += check(n);
	return result;
}

int main(void)
{
	assert(check(145) == 145);

	std::cout << problem45() << std::endl;
}
