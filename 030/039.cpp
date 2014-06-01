/******************************************************************
 * Problem 39 「整数の直角三角形」
 * 
 * 辺の長さが {a,b,c} と整数の3つ組である直角三角形を考え,
 * その周囲の長さを p とする. p = 120のときには3つの解が存在する:
 *    {20,48,52}, {24,45,51}, {30,40,50}
 * p ≤ 1000 のとき解の数が最大になる p はいくつか?
 ******************************************************************/
#include <iostream>
#include <assert.h>

bool isRightTriangle(const int a, const int b, const int c)
{
	return (c*c == a*a + b*b) ? true : false;
}

int countRightTriangle(const int p)
{
	int count = 0;
	for (int a = 1; a < p; ++a) {
		for (int b = a; b < p-a; ++b) {
			const int c = p-a-b;
			if (isRightTriangle(a, b, c))
				++count;
		}
	}
	return count;
}

int problem39(void)
{
	int count = 0, p_max = 0;
	for (int p = 0; p < 1000; ++p) {
		const int tmp = countRightTriangle(p);
		if (count < tmp) {
			count = tmp;
			p_max = p;
		}
	}
	return p_max;
}

int main(void)
{
	assert(isRightTriangle(20, 48, 52) == true);
	assert(countRightTriangle(120) == 3);

	std::cout << problem39() << std::endl;
}
