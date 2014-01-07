//////////////////////////////////////////////////////////////////////
// Problem 20  
// 
// n * (n - 1) * ... * 3 * 2 * 1 を n! と表す。
// 100! の各桁の数字の合計を求めよ。
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <assert.h>

int problem20(const int num)
{
	std::vector<int> result = {1};

	for (int n = 1; n <= num; n++) {
		int keta = 0;
		std::vector<int> temp;
		for (auto itr = result.begin(); itr != result.end(); ++itr) {
			const int t = (*itr) * n + keta;
			temp.push_back(t%10);
			keta = t / 10;
		}
		for ( ; keta != 0; keta /= 10)
			temp.push_back(keta%10);

		result = std::move(temp);
	}

// 	reverse(result.begin(), result.end());
	return std::accumulate(result.begin(), result.end(), 0);
}


int main(void)
{
	assert(problem20(10) == 27);

	std::cout << problem20(100) << std::endl;
}
