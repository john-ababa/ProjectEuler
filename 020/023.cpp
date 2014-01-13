//////////////////////////////////////////////////////////////////////
// Problem 23  
// 
// 完全数とは, その数の真の約数の和がそれ自身と一致する数のことである.
// たとえば, 28の真の約数の和は, 1 + 2 + 4 + 7 + 14 = 28であるので, 28は完全数である.
// 真の約数の和がその数よりも少ないものを不足数といい,
// 真の約数の和がその数よりも大きいものを過剰数と呼ぶ.
// 12は, 1+2+3+4+6=16となるので, 最小の過剰数である.
// よって2つの過剰数の和で書ける最少の数は24である.
//
// 数学的な解析により, 28123より大きい任意の整数は2つの過剰数の和で書けることが知られている.
// 2つの過剰数の和で表せない最大の数がこの上限よりも小さいことは分かっているのだが,
// この上限を減らすことが出来ていない. 2つの過剰数の和で書き表せない正の整数の総和を求めよ.
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <assert.h>

int	isAbundant(const int n)
{
	int sum = 0, n2 = n/2;
	for (int i = 1; i <= n2; ++i) {
		if (n % i == 0)
			sum += i;
	}
	return (n < sum) ? 1 : 0;
}

// need more test
bool isSumOfAbundant(const int n, std::vector<int>& a)
{
	int n2 = n/2;
	for (int i = 1; i <= n2; ++i) {
		if (a[i] && a[n-i])
			return true;
	}
	return false;
}

int problem23(void)
{
	std::vector<int> a(28123, 0);

	for (size_t i = 1; i < a.size(); ++i)
		a[i] = isAbundant(i);

	int sum = 0;
	for (size_t i = 1; i < a.size(); ++i) {
		if (!isSumOfAbundant(i, a))
			sum += i;
	}
	return sum;
}

int main()
{
	assert(isAbundant(24) == 1);

	std::cout << problem23() << std::endl;
}
