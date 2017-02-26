/******************************************************************
 * Problem 90 「2つの立方体の数字」  
 * 
 * 立方体の6面それぞれに異なる数字(0から9)が書かれている; 2番目の立方体も同様になっている.
 * 異なる位置に2つの立方体を隣り合わせることで様々な2桁の数を作ることができる.
 * 例えば, 平方数である64も作ることができる: [image here]
 *
 * 事実, 両方の立方体の数字を注意深く選ぶと100以下のすべての平方数を示すことが可能である
 * :01, 04, 09, 16, 25, 36, 49, 64, そして 81.
 * 例えば, これを実現する一つの方法としては {0, 5, 6, 7, 8, 9} を一方の立方体に,
 * そして {1, 2, 3, 4, 8, 9} を他方の立方体に配置すればよい.
 * しかし, 6と9を逆さまに回転することを許すと {0, 5, 6, 7, 8, 9} と {1, 2, 3, 4, 6, 7} のような
 * 配列で9つすべての平方数を示す事ができる; そうでなければ09を得ることができない.
 * 順番ではなくそれぞれの立方体の数字に着目して配列を区別する.
 * {1, 2, 3, 4, 5, 6} は {3, 6, 4, 1, 2, 5} と同じものとし
 * {1, 2, 3, 4, 5, 6} は {1, 2, 3, 4, 5, 9} と異なるものとする.
 * しかし6と9を逆さにすることを許すために, 最後の例で区別された両方の配列のかわりに,
 * {1, 2, 3, 4, 5, 6, 9} という(要素数が７つに)拡張された配列を使用して2桁の数をつくることにする.
 * すべての平方数を表示し得る2つの立方体の異なる配列の組はいくつあるか.
 ******************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

bool containsAllSN(const std::vector<int>& vec)
{
	for (int n = 1; n*n < 100; ++n) {
		if (vec[n*n] != 1)
			return false;
	}
	return true;
}

bool check(const std::vector<int>& vec1, const std::vector<int>& vec2)
{
	std::vector<int> result(100, 0);
	for (size_t i = 0; i < vec1.size(); ++i) {
		for (size_t j = 0; j < vec2.size(); ++j) {
			result[(vec1[i])*10 + vec2[j]] = 1;
			result[(vec2[j])*10 + vec1[i]] = 1;
		}
	}
	return containsAllSN(result);
}

void adjust69(std::vector<int>& vec)
{
	const auto p6 = std::find(vec.begin(), vec.end(), 6);
	const auto p9 = std::find(vec.begin(), vec.end(), 9);

	if (p6 == vec.end() && p9 == vec.end())
		return;
	if (p6 != vec.end() && p9 != vec.end())
		return;
	if (p9 == vec.end() && p6 != vec.end())
		vec.push_back(9);
	if (p6 == vec.end() && p9 != vec.end())
		vec.push_back(6);
}

std::vector<std::vector<int>> getCombination(void)
{
	std::vector<std::vector<int>> combinations;

	const std::vector<int> num = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<int> mask(6, 1); mask.resize(10, 0);

	do {
		std::vector<int> vec; vec.reserve(6);
		for (size_t i = 0; i < mask.size(); ++i) {
			if (mask[i] == 1)
				vec.push_back(num[i]);
		}
		adjust69(vec);
		combinations.push_back(vec);
	} while (std::prev_permutation(mask.begin(), mask.end()));

	return combinations;
}

int problem90(void)
{
	const std::vector<std::vector<int>> comb1 = getCombination();
	int count = 0;

	for (size_t i = 0; i < comb1.size(); ++i) {
		for (size_t j = i+1; j < comb1.size(); ++j)
			count += check(comb1[i], comb1[j]);
	}
	return count;
}

int test1()
{
	std::vector<int> comb1 = {0, 5, 6, 7, 8, 9};
	std::vector<int> comb2 = {1, 2, 3, 4, 8, 9};

	return check(comb1, comb2);
}

int test2()
{
	std::vector<std::vector<int>> comb1 = getCombination();
	return comb1.size();
}

int main(void)
{
	assert(test1() == 1);
	assert(test2() == 210);

	std::cout << problem90() << std::endl;
}
