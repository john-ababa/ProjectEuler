/******************************************************************
 * Problem 78　「コインの分割」  
 * 
 * n 枚のコインを異なった方法で山に分ける場合の数を p(n) と表わす.
 * 例えば, 5枚のコインを山に分ける異なったやり方は７通りなので p(5)=7 となる.
 * OOOOO
 * OOOO   O
 * OOO   OO
 * OOO   O   O
 * OO   OO   O
 * OO   O   O   O
 * O   O   O   O   O
 * p(n) が100万で割り切れる場合に最小となる n を求めよ.
 ******************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

int check(int limit)
{
	std::vector<int> p(limit, 0); p[0] = 1;
	for (int i = 1; i < limit; i++) {
		for (int j = i; j < limit; j++)
			p[j] = (p[j] + p[j - i]) % 1000000;
	}
	auto itr = std::find(p.cbegin(), p.cend(), 0);
	return (itr != p.cend()) ? std::distance(p.cbegin(), itr) : -1;
}

int problem78(void)
{
	for (int limit = 1; ; limit *= 2) {
		const int result = check(limit);
		if (result != -1)
			return result;
	}
}

int main(void)
{
	std::cout << problem78() << std::endl;
}
