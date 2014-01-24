//////////////////////////////////////////////////////////////////////
// Problem 26  
// 
// 単位分数とは分子が1の分数である。
// 分母が2から10の単位分数を10進数で表記すると次のようになる。
// 1/2 = 0.5
// 1/3 = 0.(3)
// 1/4 = 0.25
// 1/5 = 0.2
// 1/6 = 0.1(6)
// 1/7 = 0.(142857)
// 1/8 = 0.125
// 1/9 = 0.(1)
// 1/10 = 0.1
// 0.1(6)は 0.166666... という数字であり、1桁の循環節を持つ。1/7 の循環節は6桁ある。
// d < 1000 なる 1/d の中で循環節が最も長くなるような d を求めよ。
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

int recurringCycle(const int m)
{
	std::vector<int> ans;
	int n = 10;

	while (1) {
		auto itr = std::find(ans.cbegin(), ans.cend(), n % m);
		if (!ans.empty() && itr != ans.cend())
			return std::distance(itr, ans.cend());
		ans.push_back(n % m);

		if (n / m == 0)
			n *= 10;
		else 
			n = n % m * 10;
	}
}

int problem26(void)
{
	int max = 0, keta = 0;
	for (int m = 2; m < 1000; ++m) {
		const int tmp = recurringCycle(m);
		if (keta < tmp) {
			keta = tmp;
			max = m;
		}
	}
	return max;
}

int main(void)
{
	assert(recurringCycle(7) == 6);

	std::cout << problem26() << std::endl;
}
