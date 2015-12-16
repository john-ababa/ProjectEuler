/******************************************************************
 * Problem 65  
 * 
 * 2の平方根は無限連分数として書くことができる。
 * [image here]
 * 無限連分数である√2 = [1;(2)]と書くことができるが、(2)は2が無限に繰り返されることを示す。
 *
 * 同様に、√23 = [4;(1,3,1,8)]。
 * 平方根の部分的な連分数の数列から良い有理近似が得られることが分かる。
 *
 * √2の近似分数について考えよう。
 * [image here]
 * 従って、√2の近似分数からなる数列の最初の10項は：
 * 1, 3/2, 7/5, 17/12, 41/29, 99/70, 239/169, 557/408, 1393/985, 3363/2378, ...
 *
 * もっとも驚くべきことに、数学的に重要な定数、
 * e = [2; 1,2,1, 1,4,1, 1,6,1 , ... , 1,2k,1, ...]。
 *
 * eの近似分数からなる数列の最初の10項は：
 * 2, 3, 8/3, 11/4, 19/7, 87/32, 106/39, 193/71, 1264/465, 1457/536, ...
 *
 * 10項目の近似分数の分子の桁を合計すると1+4+5+7=17である。
 * eについての連分数である近似分数の100項目の分子の桁の合計を求めよ。
 ******************************************************************/
#include <iostream>
#include <vector>
#include <assert.h>
#include <boost/multiprecision/cpp_int.hpp>

int problem65(int size)
{
	std::vector<int> v(size, 1);
	v[0] = 2;
	for (int k = 0, i = 2; i < size; i+=3)
		v[i] = (++k)*2;

	boost::multiprecision::cpp_int numer = 1, denom = *(v.rbegin());
	for (auto itr = v.rbegin(); itr != v.rend()-2; ++itr) {
		boost::multiprecision::cpp_int new_denom = denom * *(itr+1) + numer;
		numer = 1 * denom;
		denom = new_denom;
	}
	//std::cout << numer+denom*2 << " / " << denom << std::endl;

	int result = 0;
	for (boost::multiprecision::cpp_int n = numer+denom*2; n != 0; n /= 10)
		result += boost::multiprecision::cpp_int(n % 10).str()[0] - '0';
	return result;
}

int main(void)
{
	assert(problem65(10) == 17);

	std::cout << problem65(100) << std::endl;
}

