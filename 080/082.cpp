/******************************************************************
 * Problem 82 「経路の和:3方向」  
 * 
 * 注: この問題はProblem 81よりも挑戦しがいがあるだろう.
 * 下記の5次の正方行列で, 一番左の行の任意のセルから開始し
 * 一番右の行の任意のセルで終わる道を探索する. ただし上下右にのみ移動できるものとする. 
 * 一番小さなパスは下で赤の太字で示されたものである. このときの合計は994になる.
 *     | 131 | 673 | 234 | 103 | 18  |
 *     | 201 | 96  | 342 | 965 | 150 |
 *     | 630 | 803 | 746 | 422 | 111 |
 *     | 537 | 699 | 497 | 121 | 956 |
 *     | 805 | 732 | 524 | 37  | 331 |
 * 今, 31Kのテキストファイルmatrix.txtには80*80の行列が書かれている.
 * 一番左の行から一番右の行へ移動する際の一番小さなパスの和を求めよ.
 ******************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <assert.h>

const int BIGNUM = 99999999;
std::vector<std::vector<int>> org;

std::vector<int> split(const std::string &str, char delim)
{
	std::vector<int> vec;
	size_t current = 0, found;
	while ((found = str.find_first_of(delim, current)) != std::string::npos) {
		vec.push_back(std::stoi(std::string(str, current, found - current)));
		current = found + 1;
	}
	vec.push_back(std::stoi(std::string(str, current, str.size() - current)));
	return vec;
}

std::vector<std::vector<int>> readFile(const char* file)
{
	std::vector<std::vector<int>> vecs;

	std::ifstream ifs(file);
	for (std::string line; std::getline(ifs, line); )
		vecs.push_back(split(line, ','));
	return vecs;
}

int calcSum(std::vector<std::vector<int>>& tmp, int p, int h2, int w2)
{
	const int sum = p + org[h2][w2];
	if (sum < tmp[h2][w2]) {
		tmp[h2][w2] = sum;
		return sum;
	}
	return BIGNUM;
}

void calcPath(std::vector<std::vector<int>>& tmp, int h, int w, const int min)
{
	if (min <= tmp[h][w] || w == (int)tmp.size()-1)
		return;

	int sum1 = BIGNUM, sum2 = BIGNUM, sum3 = BIGNUM;
	if (h+1 != (int)tmp.size())
		sum1 = calcSum(tmp, tmp[h][w], h+1, w); // down
	if (w+1 != (int)tmp[0].size())
		sum2 = calcSum(tmp, tmp[h][w], h, w+1); // right
	if (h-1 != -1) 
		sum3 = calcSum(tmp, tmp[h][w], h-1, w); // up
	if (sum1 == BIGNUM && sum2 == BIGNUM && sum3 == BIGNUM)
		return;

	if (h+1 != (int)tmp.size())
		calcPath(tmp, h+1, w, min);
	if (w+1 != (int)tmp[0].size())
		calcPath(tmp, h, w+1, min);
	if (h-1 != -1)
		calcPath(tmp, h-1, w, min);
}

int problem82(std::vector<std::vector<int>> vecs)
{
	int min = BIGNUM;
	for (size_t i = 0; i < vecs.size(); ++i) {
		std::vector<std::vector<int>> tmp(vecs.size(), std::vector<int>(vecs.size(), BIGNUM));
		tmp[i][0] = org[i][0];
		calcPath(tmp, i, 0, min);
		for (size_t j = 0; j < tmp[0].size(); ++j)
			min = std::min(min, tmp[j].back());
	}
	return min;
}

int main(void)
{
	std::vector<std::vector<int>> test = {
		{ 131, 673, 234, 103, 18  },
		{ 201, 96,  342, 965, 150 },
		{ 630, 803, 746, 422, 111 },
		{ 537, 699, 497, 121, 956 },
		{ 805, 732, 524, 37 , 331 }
	};
	org = test;
	assert(problem82(org) == 994);

	org = readFile("p082_matrix.txt");
	std::cout << problem82(org) << std::endl;
}
