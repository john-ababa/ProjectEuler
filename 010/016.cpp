//////////////////////////////////////////////////////////////////////
// Problem 16  
// 
// 2^15 = 32768 であり、これの各数字の合計は 3 + 2 + 7 + 6 + 8 = 26 となる。
// 同様にして、2^1000 の各数字の合計を求めよ。
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <sstream>
#include <assert.h>

int problem16(int n)
{
	long double num = 1;
	for (int i = 0; i < n; ++i)
		num *= 2;

	std::stringstream ss;
	ss << std::fixed << num;

	int sum = 0;
	for (auto itr = ss.str().begin(); *itr != '.'; ++itr)
		sum += *itr - '0';
	return sum;
}

int main(void)
{
	assert(problem16(15) == 26);

	std::cout << problem16(1000) << std::endl;
}
