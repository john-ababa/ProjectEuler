//////////////////////////////////////////////////////////////////////
// Problem 21  
// 
// d(n)をnの真の約数の和と定義する。（真の約数とはn以外の約数のことである。）
// もし、d(a) = b かつ d(b) = a （a ≠ b）を満たすとき、aとbは友愛数（親和数）であるという。
// 例えば、220の約数は1, 2, 4, 5, 10, 11, 20, 22, 44, 55, 110なのでd(220) = 284である。
// また、284の約数は1, 2, 4, 71, 142なのでd(284) = 220である。
// それでは10000未満の友愛数の合計を求めよ。
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <assert.h>

int d(const int n)
{
	int sum = 0;
	for (int i = 1; i <= n/2; ++i) {
		if (n % i == 0)
			sum += i;
	}
	return sum;
}

int problem21(const int n)
{
	int sum = 0;
	for (int i = 1; i < n; ++i) {
		const int b = d(i);
		const int a = d(b);
		if (a != b && a == i)
			sum += i;
	}
	return sum;
}

int main(void)
{
	assert(d(220) == 284);
	assert(d(284) == 220);

	std::cout << problem21(10000) << std::endl;
}
