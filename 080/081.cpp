/******************************************************************
 * Problem 81 「経路の和:2方向」  
 * 
 * 下記の5次の正方行列で, 左上のセルから開始し右下のセルで終わるパスを探索する.
 * ただし下方向と右方向にのみ移動できるものとする. 
 * 通過したセルの和が最小となるパスは赤の太字で示されたもので, その値は2427である.
 *   | 131 | 673 | 234 | 103 | 18  |
 *   | 201 | 96  | 342 | 965 | 150 |
 *   | 630 | 803 | 746 | 422 | 111 |
 *   | 537 | 699 | 497 | 121 | 956 |
 *   | 805 | 732 | 524 | 37  | 331 |
 * 今, 31Kのテキストファイルmatrix.txt には80*80の行列が書かれている. 
 * 同様に左上のセルから開始し右下のセルで終わり, 
 * かつ右方向と下方向にのみ移動するときの最小のパスの和を求めよ.
 ******************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <assert.h>

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

std::vector<std::vector<int>> readFile(void)
{
	std::vector<std::vector<int>> vecs;

	std::ifstream ifs("p081_matrix.txt");
	for (std::string line; std::getline(ifs, line); )
		vecs.push_back(split(line, ','));
	return vecs;
}

int calcPath(std::vector<std::vector<int>> vecs)
{
	const int w = vecs[0].size()-1;
	for (int i = 0; i < w*2; ++i) {
		for (int j = i+1; j != -1; --j) {
			const int col = i+1-j;
			const int row = j;
			if (0 <= col && col <= w && 0 <= row && row <= w) {
				size_t a = -1, b = -1;
				if (col-1 != -1)
					a = vecs[col-1][row];
				if (row-1 != -1)
					b = vecs[col][row-1];
				vecs[col][row] += std::min(a, b);
			}
		}
	}
	return vecs[w][w];
}

int problem81()
{
	return calcPath(readFile());
}

int main(void)
{
	std::vector<std::vector<int>> vec = {
		{ 131, 673, 234, 103, 18  },
		{ 201, 96,  342, 965, 150 },
		{ 630, 803, 746, 422, 111 },
		{ 537, 699, 497, 121, 956 },
		{ 805, 732, 524, 37 , 331 }
	};
	assert(calcPath(vec) == 2427);

	std::cout << problem81() << std::endl;
}
