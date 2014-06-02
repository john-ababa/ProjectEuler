/******************************************************************
 * Problem 41 「パンデジタル素数」
 * 
 * n桁パンデジタルであるとは, 1からnまでの数を各桁に1つずつ持つこととする.
 *    #下のリンク先にあるような数学的定義とは異なる
 * 例えば2143は4桁パンデジタル数であり, かつ素数である.
 * n桁（この問題の定義では9桁以下）パンデジタルな素数の中で最大の数を答えよ.
 ******************************************************************/
#include <iostream>
#include <string>
#include <algorithm>
#include "../common/common.h"
#include <assert.h>

int problem41(void)
{
	int max = 0;

	for (std::string str = "123456789"; !str.empty(); str.pop_back()) {
		do {
			if (Euler::isPrime(std::stoi(str)))
				max = std::max(max, std::stoi(str));
		} while (next_permutation(str.begin(), str.end()));
	}
	return max;
}

int main(void)
{
	std::cout << problem41() << std::endl;
}
