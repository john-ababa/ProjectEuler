/******************************************************************
 * Problem 52 「置換倍数」
 *
 * 125874を2倍すると251748となる. これは元の数125874と順番は違うが同じ数を含む.
 * 2x, 3x, 4x, 5x, 6x が x と同じ数を含むような最小の正整数 x を求めよ.
 ******************************************************************/
#include <iostream>
#include <string>
#include <algorithm>

std::string toString(const int n)
{
	std::string s = std::to_string(n);
	std::sort(s.begin(), s.end());
	return s;
}

bool check2to7(const int n, const std::string& base)
{
	for (int x = 2; x < 7; ++x) {
		if (base != toString(n*x))
			return false;
	}
	return true;
}

int problem52()
{
	for (int n = 1; ; ++n) {
		if (check2to7(n, toString(n)))
			return n;
	}
	return -1;
}

int main(void)
{
	std::cout << problem52() << std::endl;
}
