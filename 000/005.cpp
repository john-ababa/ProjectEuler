//////////////////////////////////////////////////////////////////////
// Problem 5
//
// 2520 は 1 から 10 の数字の全ての整数で割り切れる数字であり、
// そのような数字の中では最小の値である。では、1 から 20 までの
// 整数全てで割り切れる数字の中で最小の値はいくらになるか。
//////////////////////////////////////////////////////////////////////
#include <iostream>
// #include <vector>
// #include <cmath>
#include <assert.h>

bool check(const int num, const int untill)
{
	for (int i = 2; i <= untill; ++i) {
		if (num % i != 0)
			return false;
	}
	return true;
}

int problem5(const int untill)
{
 	long long num = untill;
	while (check(num, untill) != true)
		num += 2;
	return num;
}

/*
int problem5_2(const int untill)
{
	std::vector<int> vec(untill+1, 0);
	for (int i = 2; i <= untill; ++i) {
		int n = i;
		for (int j = 2; j <= i; ++j) {
			int c = 0;
			while (n % j == 0) {
				n /= j;
				++c;
			}
			vec[j] = std::max(vec[j], c);
		}
	}

	int sum = 1;
	for (int i = 2; i <= untill; ++i) {
		if (vec[i])
			sum *= std::pow(i, vec[i]);
	}
	return sum;
}
*/

int main(void)
{
	assert(problem5(10) == 2520);

 	std::cout << problem5(20) << std::endl;
}
