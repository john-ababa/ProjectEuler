/******************************************************************
 * Problem 68  
 * 
 * 下に示す図のようなものを"magic" 3-gon ringという。
 * これは1～6の数字を当てはめて、各列の数字の和が9となっている。
 * これを例として説明する。
 *   [image here]
 * 外側のノードのうち一番小さいものの付いた列(例では4,3,2)から時計回りに回って
 * それぞれ列の数字を3つ連ねて説明する。
 * 例えば例のものは4,3,2; 6,2,1; 5,1,3という組で説明することができる。
 * 1～6の数字を当てはめて、各列の数字の和が等しくなるものは次の8通りある。
 * | 合計 | 組
 * |  9   | 4,2,3; 5,3,1; 6,1,2
 * |  9   | 4,3,2; 6,2,1; 5,1,3
 * |  10  | 2,3,5; 4,5,1; 6,1,3
 * |  10  | 2,5,3; 6,3,1; 4,1,5
 * |  11  | 1,4,6; 3,6,2; 5,2,4
 * |  11  | 1,6,4; 5,4,2; 3,2,6
 * |  12  | 1,5,6; 2,6,4; 3,4,5
 * |  12  | 1,6,5; 3,5,4; 2,4,6
 * この組の各数字を連結して、9桁の数字で表すことができる。
 * 例えば、上の図のものは4,3,2; 6,2,1; 5,1,3であるので432621513である。
 * さて、下の図に1～10の数字を当てはめ、各列の数字の和が等しくなる
 * "magic" 5-gon ringを作って、それを表す16桁または17桁の数字のうち、
 * 16桁のものの最大の数字を答えよ。
 * [image here]
 ******************************************************************/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#define range(x) x.begin(), x.end()

std::string problem68(void)
{
	std::vector<int> n = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, sum(5);
	std::vector<int*> t = { &n[0], &n[3], &n[5], &n[7], &n[9] };
	std::vector<std::vector<int*>> p = {
		{ &n[0], &n[1], &n[2] }, 
		{ &n[3], &n[2], &n[4] }, 
		{ &n[5], &n[4], &n[6] }, 
		{ &n[7], &n[6], &n[8] }, 
		{ &n[9], &n[8], &n[1] }
	};

	std::vector<std::string> vec;
	do {
		for (int i = 0; i < 5; ++i)
			sum[i] = std::accumulate(range(p[i]), 0, [](int s, int* x){ return s + *x; });

		if (std::find_if_not(range(sum), [&](int x){return sum[0] == x;}) == sum.end()) {
			int min = std::distance(t.begin(), std::min_element(range(t), [](int* a, int* b){return *a < *b;}));

			std::stringstream ss;
			for (int n = 0; n < 5; ++n, ++min)
				ss << std::accumulate(range(p[min%5]), std::string(), [](std::string& s, int* x){ return s += std::to_string(*x); });
			vec.push_back(ss.str());
		}
	} while (std::next_permutation(range(n)));

	vec.erase(std::remove_if(range(vec), [](const std::string& s) { return s.length() != 16;}), vec.end());
	std::sort(range(vec));
	return vec.back();
}

int main(void)
{
	std::cout << problem68() << std::endl;
}
