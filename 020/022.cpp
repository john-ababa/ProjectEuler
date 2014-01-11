//////////////////////////////////////////////////////////////////////
// Problem 22  
// 
// 5000個以上の名前が書かれている46Kのテキストファイルnames.txt を用いる. 
// http://projecteuler.net/project/names.txt
//
// まずアルファベット順にソートせよ.
// のち, 各名前についてアルファベットに値を割り振り, 
// リスト中の出現順の数と掛け合わせることで, 名前のスコアを計算する.
//
// たとえば, リストがアルファベット順にソートされているとすると, COLINはリストの938番目にある.
// またCOLINは3 + 15 + 12 + 9 + 14 = 53という値を持つ. 
// よってCOLINは938 * 53 = 49714というスコアを持つ.
//
// ファイル中の全名前のスコアの合計を求めよ.
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <assert.h>
	
int wordScore(const std::string& word, const int n)
{
	int sum = 0;
	for (auto itr = word.cbegin(); itr != word.cend(); ++itr) {
		if (*itr != '"')
			sum += *itr - 'A' + 1;
	}
	return sum * n;
}

int problem22()
{
	std::vector<std::string> words;

	std::ifstream ifs("names.txt");
	std::string line;
	while (std::getline(ifs, line, ','))
		words.push_back(line);

	std::sort(words.begin(), words.end());

	int score = 0;
	for (size_t i = 0; i < words.size(); ++i)
		score += wordScore(words[i], i+1);
	return score;
}

int main(void)
{
	assert(wordScore("\"COLIN\"", 938) == 49714);

	std::cout << problem22() << std::endl;
}
