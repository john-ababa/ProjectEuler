/******************************************************************
 * Problem 66  
 *
 * 次の形式の, 2次のディオファントス方程式を考えなさい:
 * x^2 - D*y^2 = 1
 * たとえばD=13のとき, xを最小にする解は649^2 - 13*180^2 = 1である.
 * Dが平方数(square)のとき, 正整数のなかに解は存在しないと考えられる.
 *
 * D = {2, 3, 5, 6, 7}に対してxを最小にする解は次のようになる:
 * 3^2 - 2*2^2 = 1
 * 2^2 - 3*1^2 = 1
 * 9^2 - 5*4^2 = 1
 * 5^2 - 6*2^2 = 1
 * 8^2 - 7*3^2 = 1
 * したがって, D <= 7に対してxを最小にする解を考えると, D=5のときxは最大である.
 * D <= 1000に対するxを最小にする解で, xが最大になるようなDの値を見つけよ.
 ******************************************************************/
#include <iostream>
#include <vector>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;

cpp_int p65(const std::vector<int>& v, const int D) // from problem64
{
	cpp_int numer = 1, denom = *(v.rbegin());
	for (auto itr = v.rbegin(); itr != v.rend()-2; ++itr) {
		boost::multiprecision::cpp_int new_denom = denom * *(itr+1) + numer;
		numer = 1 * denom;
		denom = new_denom;
	}

	const cpp_int x = numer+v.front()*denom, y = denom;
	if (x*x - D*y*y == 1)
		return x; //std::cout << x << " / " << y << std::endl;
	else
		return x*x+y*y*D; //std::cout << x*x+y*y*D << " / " << y*x*2 << std::endl;
}

cpp_int p64(const int n) // from problem64
{
	int s = (int)std::sqrt(n);
	if (s*s == n)
		return 0;

	std::vector<int> vec = {s};
	int a = s, y = 0, x = 1;
	do {
		y = a * x - y;
		x = (n - y*y) / x;
		a = (y + s) / x;
		vec.push_back(a);
	} while (x != 1);

	if (vec.size() > 2)
		vec.pop_back();
	return p65(vec, n);
}

int problem66(void)
{
	cpp_int max;
	int maxD = 0;

	for (int D = 1; D <= 1000; ++D) {
		const cpp_int tmp = p64(D);
		if (max <= tmp) {
			max = tmp;
			maxD = D;
		}
	}
	return maxD;
}

//ペル方程式 Dx^2+1 = y^2 の sqrt(d) を連分数 b/a で近似. x=a, y=b が解になる
int main(void)
{
	assert(p64(61) == 1766319049);

	std::cout << problem66() << std::endl;
}
