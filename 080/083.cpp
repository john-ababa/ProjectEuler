/******************************************************************
 * Problem 83 「経路の和:4方向」  
 * 
 * 注: この問題はProblem 81よりも非常に挑戦しがいがあるだろう.
 * 下記の5次の正方行列で, 上下左右に移動し左上のセルから開始し
 * 右下のセルで終了する道を探索する. 一番小さな道は下で赤で示されており,
 * このときの合計は2297になる.
 *     | 131 | 673 | 234 | 103 | 18  |
 *     | 201 | 96  | 342 | 965 | 150 |
 *     | 630 | 803 | 746 | 422 | 111 |
 *     | 537 | 699 | 497 | 121 | 956 |
 *     | 805 | 732 | 524 | 37  | 331 |
 * 今, 31Kのテキストファイルmatrix.txtには80*80の行列が書かれている. 
 * 上下左右に移動し左上のセルから開始し右下のセルで終了する道に沿った和の最小を求めよ.
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

void calcPath(std::vector<std::vector<int>>& tmp, int h, int w)
{
	if (w == (int)tmp.size()-1 && h == (int)tmp[0].size()-1)
		return;

	int sum1 = BIGNUM, sum2 = BIGNUM, sum3 = BIGNUM, sum4 = BIGNUM;
	if (h+1 != (int)tmp.size())
		sum1 = calcSum(tmp, tmp[h][w], h+1, w); // down
	if (w+1 != (int)tmp[0].size())
		sum2 = calcSum(tmp, tmp[h][w], h, w+1); // right
	if (h-1 != -1) 
		sum3 = calcSum(tmp, tmp[h][w], h-1, w); // up
	if (w-1 != -1) 
		sum4 = calcSum(tmp, tmp[h][w], h, w-1); // left
	if (sum1 == BIGNUM && sum2 == BIGNUM && sum3 == BIGNUM && sum4 == BIGNUM)
		return;

	if (h+1 != (int)tmp.size())
		calcPath(tmp, h+1, w);
	if (w+1 != (int)tmp[0].size())
		calcPath(tmp, h, w+1);
	if (h-1 != -1)
		calcPath(tmp, h-1, w);
	if (w-1 != -1)
		calcPath(tmp, h, w-1);
}

int problem83(const std::vector<std::vector<int>>& vecs)
{
	std::vector<std::vector<int>> tmp(vecs.size(), std::vector<int>(vecs.size(), BIGNUM));
	tmp[0][0] = org[0][0];
	calcPath(tmp, 0, 0);
	return tmp.back().back();
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
	assert(problem83(org) == 2297);

	org = readFile("p083_matrix.txt");
	std::cout << problem83(org) << std::endl;
}
