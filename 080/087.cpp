/******************************************************************
 * Problem 87 「3つの素数のべき乗」  
 * 
 * 素数の2乗と素数の3乗と素数の4乗の和で表される最小の数は28である.
 * 50未満のこのような数は丁度4つある.
 *     28 = 2^2 + 2^3 + 2^4
 *     33 = 3^2 + 2^3 + 2^4
 *     49 = 5^2 + 2^3 + 2^4
 *     47 = 2^2 + 3^3 + 2^4
 * では, 50,000,000未満の数で, 素数の2乗と素数の3乗と素数の4乗の和で表される数は何個あるか?
 ******************************************************************/
#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <assert.h>
#include "../common/common.h"

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;

size_t problem87(const int until = 50000000)
{
	const int m = sqrt(until);

	std::vector<cpp_int> v2, v3, v4;
	for (int i = 2; (int)v2.size() < m; ++i) {
		if (Euler::isPrime(i)) {
			const cpp_int n = i;
			v2.push_back(n*n);
			v3.push_back(n*n*n);
			v4.push_back(n*n*n*n);
		}
	}

	std::set<cpp_int> ans;
	for (int i = 0; i < m && v2[i] <= until; ++i) {
		for (int j = 0; j < m && v2[i]+v3[j] <= until; ++j) {
			for (int k = 0; k < m && v2[i]+v3[j]+v4[k] <= until; ++k)
				ans.insert(v2[i] + v3[j] + v4[k]);
		}
	}
	return ans.size();
}

int main(void)
{
	assert(problem87(50) == 4);

	std::cout << problem87() << std::endl;
}
