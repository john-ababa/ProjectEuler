/******************************************************************
 * Problem 88 「積和数」  
 * 
 * 少なくとも2つの自然数 {a(1), a(2), ... , a(k)} の集合の和かつ積として
 * 表せる自然数Nを積和数と呼ぶ：
 *     N = a(1) + a(2) + ... + a(k) = a(1) * a(2) * ... * a(k).
 * 例えば, 6 = 1 + 2 + 3 = 1 * 2 * 3.
 *
 * ある集合の大きさ k に対して, この性質を持つ最小の N を最小積和数と呼ぼう.
 * 集合の大きさ k = 2, 3, 4, 5, 6 に対する最小積和数は次のとおりである.
 *     k=2: 4 = 2 * 2 = 2 + 2
 *     k=3: 6 = 1 * 2 * 3 = 1 + 2 + 3
 *     k=4: 8 = 1 * 1 * 2 * 4 = 1 + 1 + 2 + 4
 *     k=5: 8 = 1 * 1 * 2 * 2 * 2 = 1 + 1 + 2 + 2 + 2
 *     k=6: 12 = 1 * 1 * 1 * 1 * 2 * 6 = 1 + 1 + 1 + 1 + 2 + 6
 * したがって 2 ≤ k ≤ 6 に対して,全ての最小積和数の和は 4+6+8+12 = 30 である.
 * 8 は和に一度だけカウントされていることに気をつけよう.
 * 実際, 2 ≤ k ≤ 12 に対する最小積和数の完全な集合は {4, 6, 8, 12, 15, 16} なので,
 * その和は 61 である. 2 ≤ k ≤ 12000 に対する全ての最小積和数の和は何か?
 ******************************************************************/
#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
#include <algorithm>
#include "../common/common.h"

template <class BidirectionalIterator>
bool next_combination(
	BidirectionalIterator first1, BidirectionalIterator last1,
	BidirectionalIterator first2, BidirectionalIterator last2)
{
	if ((first1 == last1) || (first2 == last2)) {
		return false;
	}
	BidirectionalIterator m1 = last1;
	BidirectionalIterator m2 = last2; --m2;

	while (--m1 != first1 && !(* m1 < *m2))
		;

	bool result = (m1 == first1) && !(* first1 < *m2);
	if (!result) {
		while (first2 != m2 && !(* m1 < * first2))
			++first2 ;
		first1 = m1;
		std::iter_swap(first1, first2);
		++first1;
		++first2;
	}

	if ((first1 != last1) && (first2 != last2)) {
		m1 = last1; m2 = first2;
		while ((m1 != first1) && (m2 != last2)) {
			std::iter_swap(--m1, m2);
			++m2;
		}
		std::reverse(first1, m1);
		std::reverse(first1, last1);
		std::reverse(m2, last2);
		std::reverse(first2, last2);
	}
	return !result;
}

template <class BidirectionalIterator>
bool next_combination(
		BidirectionalIterator first, BidirectionalIterator middle, BidirectionalIterator last)
{
	return next_combination(first, middle, middle, last);
}

std::vector<int> factorization(int n)
{
	std::vector<int> vec;
	for (int i = 2; n != 1 && i != n; i+=1) {
		while (n % i == 0) {
			vec.push_back(i);
			n /= i;
		}
	}
	if (n != 1)
		vec.push_back(n);
	return vec;
}

bool right(std::vector<int> f, const int k, const int M, const int mult, int lm, int ld)
{
	std::vector<int> fn(f.begin()+M, f.end());

	for (size_t m = 2; m <= fn.size(); ++m) {
		do {
			const int rm = std::accumulate(fn.begin(), fn.begin()+m, 1, std::multiplies<int>());
			const int rsum = std::accumulate(fn.begin()+m, fn.end(), 0);
			const int ad = k - ld - (1 + ((int)fn.size() - m));
			if (lm + rm + rsum + ad == mult)
				return true;

			const int rm2 = std::accumulate(fn.begin()+m, fn.end(), 1, std::multiplies<int>());
			const int ad2 = k - 2 - ld;
			if (lm + rm + rm2 + ad2 == mult)
				return true;

			if (3 <= (int)fn.size() - m) {
				const int lm2 = std::accumulate(fn.begin(), fn.begin()+m, 1, std::multiplies<int>());
				if (right(fn, k, m, mult, lm2+lm, ld+1))
					return true;
			}
		} while (next_combination(fn.begin(), fn.begin()+m, fn.end()));
	}
	return false;
}

bool left(std::vector<int>& f, const int k, const int m, const int mult)
{
	const int rmul = std::accumulate(f.begin(), f.begin()+m, 1, std::multiplies<int>());
	const int rsum = std::accumulate(f.begin()+m, f.end(), 0);
	const int ad = [&]{
		const int s = f.size();
		if (m == 1)
			return (k >= s) ? k - s : s - k;
		else
			return k - (1 + s - m);
	}();

	if (rmul + rsum + ad == mult)
		return true;
	return false;
}

int check(std::vector<int> f, int k)
{
	const int mult = std::accumulate(f.begin(), f.end(), 1, std::multiplies<int>());

	for (size_t m = 1; m <= f.size(); ++m) {
		do {
			if (left(f, k, m, mult) == true)
				return mult;

			const int lm = mult / std::accumulate(f.begin()+m, f.end(), 1, std::multiplies<int>());
			if (right(f, k, m, mult, lm, 1) == true)
				return mult;
		} while (next_combination(f.begin(), f.begin()+m, f.end()));
	}
	return 0;
}

int problem88(void)
{
	std::vector<int> result(12001, 0);

	for (size_t i = 2; i < 30000; ++i) {
		if (Euler::isPrime(i))
			continue;

		const std::vector<int> f = factorization(i);
		for (int k = 2; k <= 12000; ++k) {
			if (result[k] == 0)
				result[k] = check(f, k);
		}
	}
	std::sort(result.begin(), result.end());
	result.erase(std::unique(result.begin(), result.end()), result.end());
	return std::accumulate(result.begin(), result.end(), 0);
}

int main(void)
{
	std::cout << problem88() << std::endl;
}
