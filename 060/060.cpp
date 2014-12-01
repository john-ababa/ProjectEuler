/******************************************************************
 * Problem 60 
 * 
 * 素数3, 7, 109, 673は非凡な性質を持っている.
 * 任意の2つの素数を任意の順で繋げると, また素数になっている.
 * 例えば, 7と109を用いると, 7109と1097の両方が素数である. これら4つの素数の和は792である.
 * これは, このような性質をもつ4つの素数の組の和の中で最小である.
 * 
 * 任意の2つの素数を繋げたときに別の素数が生成される, 5つの素数の組の和の中で最小のものを求めよ.
 ******************************************************************/
#include <iostream>
#include <vector>
#include "../common/common.h"

int concat(int a, int b)
{
	int tmp = b;
	while (b > 0) {
		b /= 10;
		a *= 10;
	}
	return a + tmp;
}

bool isPrimePair(const int a, const int b)
{
	if (Euler::isPrime(concat(a, b)) && Euler::isPrime(concat(b, a)))
		return true;
	return false;
}

void run(std::vector<int>& primes, std::vector<int>& vec, int depth, int& max, int sum)
{
	if (depth == 5) {
		max = sum;
		return;
	}
	if (max != 0 && max <= sum)
		return;

	for (size_t i = vec[depth-1]+1; i < primes.size(); ++i) {
		int j = 0;
		for (j = 0; j < depth; ++j) {
			if (isPrimePair(primes[vec[j]], primes[i]) == false)
				break;
		}
		if (j == depth) {
			vec.push_back(i);
			run(primes, vec, depth+1, max, sum + primes[i]);
			vec.pop_back();
		}
	}
}

int problem60()
{
	std::vector<int> primes, vec;
	for (int i = 0; i < 10000; ++i) {
		if (Euler::isPrime(i))
			primes.push_back(i);
	}

	int max = 0;
	for (size_t i = 0; i != primes.size(); ++i) {
		vec.push_back(i);
		run(primes, vec, 1, max, primes[i]);
		vec.pop_back();
	}
	return max;
}

int main(void)
{
	std::cout << problem60() << std::endl;
}
