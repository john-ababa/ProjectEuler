//////////////////////////////////////////////////////////////////////
// Problem 32  
// 
// 7254は面白い性質を持っている. 39 * 186 = 7254と書け,
// 掛けられる数/掛ける数/積に1から9の数が1回ずつ出現する.
// 掛けられる数/掛ける数/積に1から9の数が1回ずつ出現するような積の総和を求めよ.
// HINT: いくつかの積は, 1通り以上の掛けられる数/掛ける数/積の組み合わせを持つが1回だけ数え上げよ.
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>

void solve(std::set<int>& result, int n1, int n2, int n3, int n4)
{
	for (int i = n1; i < n2; ++i) {
		for (int j = n3; j < n4; ++j) {
			std::stringstream ss;
			ss << i << j << i*j;

			std::string str = ss.str();
			std::sort(str.begin(), str.end());

			if (str == "123456789")
				result.insert(i*j);
		}
	}
}

int main(void)
{
	std::set<int> result;
	solve(result, 1, 10, 1000, 10000); // (1) 1...10 * 1000...10000
	solve(result, 10, 100, 100, 1000); // (2) 10...100 * 100...1000

	std::cout << std::accumulate(result.begin(), result.end(), 0) << std::endl;
}
