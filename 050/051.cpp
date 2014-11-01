/******************************************************************
 * Problem 51 「素数の桁置換」
 * 
 * *3の第1桁を置き換えることで, 13, 23, 43, 53, 73, 83という6つの素数が得られる.
 * 56**3の第3桁と第4桁を同じ数で置き換えることを考えよう.
 *
 * この5桁の数は7つの素数をもつ最初の例である:
 *   56003, 56113, 56333, 56443, 56663, 56773, 56993.
 * よって, この族の最初の数である56003は, このような性質を持つ最小の素数である.
 *
 * 桁を同じ数で置き換えることで8つの素数が得られる最小の素数を求めよ (注:連続した桁でなくても良い)
 ******************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include "../common/common.h"

std::string replaceC1ToC2(std::string str, char c1, char c2)
{
	for (size_t p = str.find(c1, 0); p != std::string::npos; p = str.find(c1, 0))
		str.replace(p, 1, 1, c2);
	return str;
}

bool check(const std::vector<std::string>& prime, const std::string& str, char c)
{
	int count = 1;
	for (char i = c+1; i <= '9'; ++i) {
		if (prime[std::stoi(replaceC1ToC2(str, c, i))] != "-1")
			count++;
	}
	if (count == 8)
		return true;
	return false;
}

std::string problem51(void)
{
	std::vector<std::string> prime;
	prime.reserve(1000000);

	for (int i = 0; i < 1000000; ++i)
		prime.push_back(Euler::isPrime(i) ? std::to_string(i) : "-1");

	for (auto itr = prime.begin(); itr != prime.end(); ++itr) {
		if (*itr != "-1") {
			bool flag = false;
			if (2 <= std::count(itr->begin(), itr->end(), '0'))
				flag = check(prime, *itr, '0');
			else if (2 <= std::count(itr->begin(), itr->end(), '1'))
				flag = check(prime, *itr, '1');
			else if (2 <= std::count(itr->begin(), itr->end(), '2'))
				flag = check(prime, *itr, '2');

			if (flag)
				return *itr;
		}
	}
	return "-1";
}

int main(void)
{
	std::cout << problem51() << std::endl;
}
