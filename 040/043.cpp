/******************************************************************
 * Problem 43 「部分列被整除性」
 * 
 * 数1406357289は0から9のパンデジタル数である (0から9が1度ずつ現れるので).
 * この数は部分列が面白い性質を持っている.
 * 
 * d1を上位1桁目, d2を上位2桁目の数とし, 以下順にdnを定義する.
 * この記法を用いると次のことが分かる.
 * 
 *   d2 d3 d4= 406 は 2 で割り切れる
 *   d3 d4 d5= 063 は 3 で割り切れる
 *   d4 d5 d6= 635 は 5 で割り切れる
 *   d5 d6 d7= 357 は 7 で割り切れる
 *   d6 d7 d8= 572 は 11 で割り切れる
 *   d7 d8 d9= 728 は 13 で割り切れる
 *   d8 d9 d10= 289 は 17 で割り切れる
 * 
 * このような性質をもつ0から9のパンデジタル数の総和を求めよ.
 ******************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <assert.h>

int concat(const char d1, const char d2, const char d3)
{
	return (d1-'0')*100 + (d2-'0')*10 + (d3-'0');
}

bool isDivisible(const std::string d)
{
	if (concat(d[1], d[2], d[3])   % 2  == 0
		&& (concat(d[2], d[3], d[4]) % 3  == 0)
		&& (concat(d[3], d[4], d[5]) % 5  == 0)
		&& (concat(d[4], d[5], d[6]) % 7  == 0)
		&& (concat(d[5], d[6], d[7]) % 11 == 0)
		&& (concat(d[6], d[7], d[8]) % 13 == 0)
		&& (concat(d[7], d[8], d[9]) % 17 == 0))
		return true;
	return false;
}

long problem43(void)
{
	long sum = 0;

	std::string str = "0123456789";
	do {
		if (isDivisible(str))
			sum += std::stol(str);
	} while (next_permutation(str.begin(), str.end()));

	return sum;
}

int main(void)
{
	assert(isDivisible("1406357289") == true);

	std::cout << problem43() << std::endl;
}
