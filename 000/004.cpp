//////////////////////////////////////////////////////////////////////
// Problem 4
//
// 左右どちらから読んでも同じ値になる数を回文数という。
// 2桁の数の積で表される回文数のうち、最大のものは 9009 = 91 * 99 である。
//では、3桁の数の積で表される回文数のうち最大のものはいくらになるか。
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <assert.h>

bool check(const std::string& s)
{
	auto ib = s.begin();
	auto ie = s.end()-1;
	while (ib < ie) {
		if (*ib++ != *ie--)
			return false;
	}
	return true;
}

int problem4()
{
	int max = 0;
	for (int i = 100; i < 1000; ++i) {
		for (int j = i; j < 1000; ++j) {
			if (check(std::to_string(i*j)))
				max = std::max(i*j, max);
		}
	}
	return max;
}

int main(void)
{
	assert(check("9009"));

	std::cout << problem4() << std::endl;
}
