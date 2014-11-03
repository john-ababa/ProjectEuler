/******************************************************************
 * Problem 55
 *
 * 47とその反転を足し合わせると, 47 + 74 = 121となり, 回文数になる.
 * 全ての数が素早く回文数になるわけではない. 349を考えよう,
 *   1. 349 + 943 = 1292,
 *   2. 1292 + 2921 = 4213
 *   3. 4213 + 3124 = 7337
 * 349は, 3回の操作を経て回文数になる.
 * まだ証明はされていないが, 196のようないくつかの数字は回文数にならないと考えられている.
 * 反転したものを足すという操作を経ても回文数にならないものをLychrel数と呼ぶ.
 * 
 * 先のような数の理論的な性質により, またこの問題の目的のために,
 * Lychrel数で無いと証明されていない数はLychrel数だと仮定する.
 * 
 * 更に, 10000未満の数については以下を仮定してよい.
 *   1. 50回未満の操作で回文数になる
 *   2. まだ誰も回文数まで到達していない
 * 実際, 10677が50回以上の操作を必要とする最初の数である:
 *    4668731596684224866951378664 (53回の操作で28桁のこの回文数になる).
 * 驚くべきことに, 回文数かつLychrel数であるものが存在する. 最初の数は4994である.
 * 10000未満のLychrel数の個数を答えよ.
 * 注: 2007/04/24にLychrel数の理論的な性質を強調するために文面が修正された.
 * 
 * 結局 => 回文数が成立しないものを探す
 ******************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

std::vector<int> intToVec(int n)
{
	std::vector<int> num;
	for (int tmp = n; tmp != 0; tmp /= 10)
		num.push_back(tmp % 10);
	std::reverse(num.begin(), num.end());
	return num;
}

bool isPalindrome(const std::vector<int>& vec)
{
	return std::equal(vec.begin(), vec.end(), vec.rbegin());
}

bool isLychrel(const int n)
{
	std::vector<int> num = intToVec(n);

	for (int i = 0; i < 50; ++i) {
		std::vector<int> result;
		int keta = 0;
		for (size_t i = 0; i < num.size(); ++i) {
			const int n = num[i] + num[num.size()-1-i] + keta;
			keta = n / 10;
			result.push_back(n % 10);
		}
		if (keta != 0)
			result.push_back(keta);
		num = std::move(result);

		if (isPalindrome(num))
			return true;
	}
	return false;
}

int problem055()
{
	int counter = 0;

	for (int n = 1; n < 10000; ++n) {
		if (isLychrel(n) == false)
			counter++;
	}
	return counter;
}

int main()
{
	assert(isPalindrome(intToVec(7337)));
	assert(isLychrel(349));

	std::cout << problem055() << std::endl;
}
