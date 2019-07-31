/******************************************************************
 * Problem 47 「異なる素因数」
 * 
 * それぞれ2つの異なる素因数を持つ連続する2つの数が最初に現れるのは:
 *   14 = 2 × 7
 *   15 = 3 × 5
 * 
 * それぞれ3つの異なる素因数を持つ連続する3つの数が最初に現れるのは:
 *   644 = 2^2 × 7 × 23
 *   645 = 3 × 5 × 43
 *   646 = 2 × 17 × 19
 * 
 * 最初に現れるそれぞれ4つの異なる素因数を持つ連続する4つの数を求めよ.
 * その最初の数はいくつか?
 ******************************************************************/
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

int primeFactor(int n)
{
	int tmp = 0, count = 0;

	for (int i = 2; n != 1; n /= i) {
		while (n % i != 0)
			++i;
		if (tmp != i) {
			tmp = i;
			++count;
		}
	}
	return count;
}

// 本当は重複チェックするべき
int problem47()
{
	std::vector<int> vec(4, 0);

	for (int i = 2; ; ++i) {
		std::rotate(vec.begin(), vec.begin()+1, vec.end());
		vec[0] = primeFactor(i);
		if (std::accumulate(vec.begin(), vec.end(), 0) == 16)
			return i-3;
	}
}

int main(void)
{
	std::cout << problem47() << std::endl;
}
