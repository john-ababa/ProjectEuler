/******************************************************************
 * Problem 80 「平方根の10進展開」  
 * 
 * よく知られているように, 自然数の平方根が整数ではないならば, それは無理数である.
 * そのような平方根の10進展開(decimal expansion)は繰り返しを持たない無限小数になる.
 * 2の平方根は, 1.41421356237309504880...,であり, 
 * その頭から100桁の数字を合計すると475になる.
 *
 * 初めの100個の自然数の平方根のうち, 無理数について,
 * それぞれの頭から100桁の数字を足した数の総和を求めよ.
 ******************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <assert.h>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/math/constants/constants.hpp>

using namespace boost::multiprecision;
using namespace boost::math::constants;

std::string getSquareRoot(int n)
{
	const number<cpp_dec_float<200>> f(n);

	std::stringstream ss;
	ss << std::setprecision(200) << sqrt(f);

	std::string s = ss.str();
	if (s.find('.') == std::string::npos)
		return "";

	s.erase(s.find('.'), 1);
	return s.substr(0, 100);
}

int sumDigit(const std::string& s)
{
	return std::accumulate(s.begin(), s.end(), 0) - ('0' * 100);
}

int problem80(void)
{
	int sum = 0, count = 0;
	for (int n = 2; n < 100; ++n) {
		const std::string s = getSquareRoot(n);
		if (!s.empty()) {
			sum += sumDigit(s);
			++count;
		}
	}
	return sum;
}

int main(void)
{
	assert(sumDigit(getSquareRoot(2)) == 475);

	std::cout << problem80() << std::endl;
}
