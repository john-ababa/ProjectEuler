/******************************************************************
 * Problem 42 「符号化三角数」
 * 
 * 三角数のn項は tn = ½n(n+1)で与えられる. 最初の10項は
 *     1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
 * である.
 * 
 * 単語中のアルファベットを数値に変換した後に和をとる.
 * この和を「単語の値」と呼ぶことにする.
 * 例えば SKY は 19 + 11 + 25 = 55 = t10である.
 * 単語の値が三角数であるとき, その単語を三角語と呼ぶ.
 * 
 * 16Kのテキストファイル words.txt 中に約2000語の英単語が記されている. 三角語はいくつあるか?
 ******************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>

bool isTriangleNumber(const int num)
{
	for (int n = 1; ; ++n) {
		const int tn = (n*(n+1))/2;
		if (num == tn)
			return true;
		if (num < tn)
			return false;
	}
}

int problem42(void)
{
	std::ifstream ifs("words.txt");
	std::string str;
	int count = 0;

	while (std::getline(ifs, str, ',')) {
		int sum = 0;
		for (auto itr = str.cbegin(); itr != str.cend(); ++itr) {
			if (*itr != '"')
				sum += *itr - 'A' + 1;
		}
		if (isTriangleNumber(sum))
			++count;
	}
	return count;
}

int main(void)
{
	assert(('S'-'A'+1) + ('K'-'A'+1) + ('Y'-'A'+1) == 55);
	assert(isTriangleNumber(55));

	std::cout << problem42() << std::endl;
}
