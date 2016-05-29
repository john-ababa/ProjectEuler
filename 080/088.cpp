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
#include <climits>
#include <set>
#include "../common/common.h"

//#define debug
//#define right_d

template < class BidirectionalIterator >
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

bool right(std::vector<int> data, int k, int r, const int mult, int lm, int ld)
{
	std::vector<int> data_r(data.begin()+r, data.end());

	//for (size_t i = 0; i < data_r.size(); ++i) {
	//	std::cout << data_r[i] << " ";
	//}
	//std::cout << std::endl;

	//const int m = std::accumulate(data.begin(), data.end(), 1, std::multiplies<int>());
	for (size_t R = 2; R <= data_r.size(); ++R) {
		do {
			//std::cout << R << std::endl;
#ifdef debug
			if (ld >= 2)
				std::cout << "\t";
			std::cout << "\t\t[ " << data_r[0];
			for(unsigned int i=1; i<R; ++i){
				std::cout << ", " << data_r[i];
			}
			std::cout << " ]" << std::flush;
			std::cout << " (";
			for(unsigned int i=R; i<data_r.size(); ++i){
				std::cout << ", " << data_r[i];
			}
			std::cout << " )]" << std::endl;
#endif

			const int rm = std::accumulate(data_r.begin(), data_r.begin()+R, 1, std::multiplies<int>());
			const int rsum = std::accumulate(data_r.begin()+R, data_r.end(), 0);
			const int rm2 = std::accumulate(data_r.begin()+R, data_r.end(), 1, std::multiplies<int>());

			//const int ld = k - 1;
			//const int rd = R-1 + ((int)data_r.size() - R);

			//const int ld = 1;
			const int rd = 1 + ((int)data_r.size() - R);
			const int lrd = k - ld - rd;

#ifdef right_d
			std::cout << mult << " | lm = " << lm << " | rm= " << rm << " | rm2=" << rm2 << " | rsum= " << rsum << std::endl;
			std::cout << lm+rm+rsum+lrd << " |\t"<< k << "\t" << r << "\t" << R << "\t" << lrd << "\t" <<  ld << "\t" << rd << std::endl;
#endif

			if (lm+rm+rsum+lrd == mult)
				return true;
			if (lm+rm+rm2+k-2-ld == mult)
				return true;

			if (3 <= (int)data_r.size() - R) {
				//const int lm2 = mult / std::accumulate(data.begin()+r, data.end(), 1, std::multiplies<int>());
				//const int lm2 = std::accumulate(data_r.begin(), data_r.begin()+r, 1, std::multiplies<int>());
				const int lm2 = std::accumulate(data_r.begin(), data_r.begin()+R, 1, std::multiplies<int>());
				//std::cout << "oppai" << std::endl;
				if (right(data_r, k, R, mult, lm2+lm, ld+1))
					return true;
			}

		} while (next_combination(data_r.begin(), data_r.begin()+R, data_r.end()));
	}
	return false;
}

bool left(std::vector<int>& data, int k, int r, const int mult)
{
	const int tmp = std::accumulate(data.begin(), data.begin()+r, 1, std::multiplies<int>());
	const int rsum = std::accumulate(data.begin()+r, data.end(), 0);

	int d = 0;
	if (r == 1)
		d = (k >= data.size()) ? k - data.size() : data.size() - k;//std::abs(k - (int)data.size());
		//d = std::abs(k - (int)data.size());
	else
		d = k - (1 + data.size() - r);
		//d = (k >= r) ? k - r : (r - k);
		//d = std::abs(k - r);

#ifdef debug
	std::cout << mult << "\t|" << k << "\t| r = " << r << "\t@ " << tmp << "\t" << rsum << "\t" << d << std::endl;
#endif
	if (tmp+rsum+d == mult)
		return true;
	return false;
}

int test(std::vector<int> data, int k)//, int r)
{
	const int mult = std::accumulate(data.begin(), data.end(), 1, std::multiplies<int>());
	for (size_t R = 1; R <= data.size(); ++R) {
		int r = R;
		do {
#ifdef debug
			std::cout << "[ " << data[0];
			for(unsigned int i=1; i<r; ++i){
				std::cout << ", " << data[i];
			}
			std::cout << " ]" << std::flush;
			std::cout << " (";
			for(unsigned int i=r; i<data.size(); ++i){
				std::cout << ", " << data[i];
			}
			std::cout << " )]" << std::endl;
#endif

			if (left(data, k, r, mult) == true)
				return mult;

			const int lm = mult / std::accumulate(data.begin()+r, data.end(), 1, std::multiplies<int>());
			if (right(data, k, r, mult, lm, 1) == true)
				return mult;

		} while (next_combination(data.begin(), data.begin()+r, data.end()));
	}

	return 0;
}


int run(void)
{
	std::vector<int> primes;
	for (int i = 2; i < 30000; ++i) {
		if (!Euler::isPrime(i))
			primes.push_back(i);
	}
	//std::vector<int> result(1001, 0);
	std::vector<int> result(12001, 0);

	for (size_t i = 0; i < primes.size(); ++i) {
	//for (size_t i = 70; i < 110; ++i) {
		std::vector<int> f = factorization(primes[i]);
#if 1
		std::cout << "# "<< i << " @ " << primes[i] << " | " << std::flush;
		for (size_t i = 0; i < f.size(); ++i)
			std::cout << f[i] << " ";
		std::cout << std::endl;
#endif

		//for (int k = 90; k <= 118; ++k) {
			//if (k == 90 || k == 118)
		for (int k = 2; k <= 12000; ++k) {
			if (result[k] == 0) {
				result[k] = test(f, k);
			}
		}
	}

	std::set<int> s;
	for (size_t i = 0; i < result.size(); ++i) {
		std::cout << i << "\t" << result[i] << std::endl;
		s.insert(result[i]);
	}
	std::cout << std::endl;

	int sum = 0;
	for (auto itr = s.begin(); itr != s.end(); ++itr)
		sum += *itr;
	return sum;
}

int main(void)
{
	std::cout << run() << std::endl;
	//assert(problem87(50) == 4);

	//std::cout << problem() << std::endl;
	//std::cout << problem2() << std::endl;

	//std::vector<int> f = factorization(8);
	//for (int i = 0; i < f.size(); ++i)
	//	std::cout << f[i] << " ";
	//std::cout << std::endl;

	//std::vector<int> v1 = {2, 7, 7};
	//std::vector<int> v2 = {};
	//int r = 3, k = 11;
	//int p1 = std::accumulate(v1.begin(), v1.end(), 1, std::multiplies<int>());
	//std::cout << " X " << p1 << std::endl;
	//int s1 = (r == 0) ? 0 : p1;
	//std::cout << " X " << s1 << std::endl;

	//int p2 = std::accumulate(v2.begin(), v2.end(), 1, std::multiplies<int>());
	//std::cout << " X " <<  p2 << std::endl;
	//int s2 = std::accumulate(v2.begin(), v2.end(), 0) + ((r == 0) ? 0 : (k - r));
	//std::cout << " X " <<  s2 << std::endl;

	//isOK(3, 1, f);
	//isOK(3, 2, f);

	//std::vector<int> a1(f.begin(), f.begin()+0);
	//for (int i = 0; i < a1.size(); ++i)
	//	std::cout << a1[i] << " ";
	//std::cout << std::endl;
	//int p1 = std::accumulate(a1.begin(), a1.end(), 1, std::multiplies<int>());
	//std::cout << p1 << std::endl;


	//std::vector<int> a2(f.begin()+0, f.end());
	//for (int i = 0; i < a2.size(); ++i)
	//	std::cout << a2[i] << " ";
	//std::cout << std::endl;
	return 0;
}
