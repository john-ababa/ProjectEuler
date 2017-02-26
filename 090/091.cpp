/******************************************************************
 * Problem 91 「整数座標における直角三角形」  
 * 
 * 点P(x1, y1)と点Q(x2, y2)はともに整数係数の点であり, 原点O(0,0)と合わせてΔOPQをなす.
 *   [image here]
 * 各係数が0と2の間にあるとき, すなわち0 ≤ x1, y1, x2, y2 ≤ 2のとき, 直角三角形は14個できる:
 *   [image here]
 * では, 0 ≤ x1, y1, x2, y2 ≤ 50のとき, 直角三角形は何個作れるか?
 ******************************************************************/
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <assert.h>

double calcLength(int w1, int h1, int w2, int h2)
{
	const int w = std::max(w1, w2) - std::min(w1, w2);
	const int h = std::max(h1, h2) - std::min(h1, h2);
	return std::sqrt(std::pow(w, 2) + std::pow(h, 2));
}

bool isRightTriangle(double a, double b, double c)
{
	return (std::fabs(pow(c, 2.0) - (std::pow(a, 2.0) + std::pow(b, 2.0))) < 0.0001) ? true : false;
}

int problem91(const int N = 50)
{
	int count = 0;

	for (int pw = 0; pw <= N; ++pw) {
		for (int ph = 1; ph <= N; ++ph) {
			for (int ow = 1; ow <= N; ++ow) {
				for (int oh = 0; oh <= ph; ++oh) {
					const double a = calcLength(0, 0, pw, ph);
					const double b = calcLength(0, 0, ow, oh);
					const double c = calcLength(ow, oh, pw, ph);
					if (std::fabs(c) < 0.001)
						continue;
					std::vector<double> v = {a, b, c};
					std::sort(v.begin(), v.end());
					count += isRightTriangle(v[0], v[1], v[2]);
				}
			}
		}
	}
	return count;
}

int main(void)
{
	assert(problem91(2) == 14);

	std::cout << problem91() << std::endl;
}

