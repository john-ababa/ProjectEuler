/******************************************************************
 * Problem 67  
 *
 * 以下の三角形の頂点から下まで移動するとき、その数値の合計の最大値は23になる。
 *            3
 *           7 5
 *          2 4 6
 *         8 5 9 3
 * この例では 3 + 7 + 4 + 9 = 23
 * 100列の三角形を含んでいる15Kのテキストファイル triangle.txt の
 * 上から下まで最大合計を見つけてください。
 *
 * 注：これは、Problem 18のずっと難しいバージョンです。
 * 全部で2^99 通りの組み合わせがあるので、
 * この問題を解決するためにすべてのルートをためすことは可能でありません！
 * あなたが毎秒1兆本の(10^12)ルートをチェックすることができたとしても、
 * 全てをチェックするために200億年以上かかるでしょう。
 * 解決するための効率的なアルゴリズムがあります。;o)
 ******************************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int checkRoute(std::vector<std::vector<int>>& v)
{
	for (size_t n = 1; n < 100; ++n) {
		for (size_t i = 0; i <= n; ++i) {
			if (i == 0)
				v[n][0] = v[n-1][0] + v[n][0];
			else if (i == n)
				v[n][i] = v[n-1][i-1] + v[n][i];
			else
				v[n][i] = std::max(v[n-1][i-1], v[n-1][i]) + v[n][i];
		}
	}
	return *std::max_element(v[99].begin(), v[99].end());
}

int problem67(void)
{
	std::vector<std::vector<int>> vec;
	std::ifstream ifs("triangle.txt");

	for (int n = 0; n < 100; ++n) {
		std::vector<int> line;
		for (int num, i = 0; i <= n; ++i) {
			ifs >> num;
			line.push_back(num);
		}
		vec.push_back(line);
	}
	return checkRoute(vec);
}

int main(void)
{
	std::cout << problem67() << std::endl;
}
