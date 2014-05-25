/******************************************************************
 * Problem 36 「二種類の基数による回文数」
 * 
 * 585 = 1001001001 (2進) は10進でも2進でも回文数である.
 * 100万未満で10進でも2進でも回文数になるような数の総和を求めよ.
 * (注: 先頭に0を含めて回文にすることは許されない.)
 ******************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <assert.h>

bool isPalindromic(const std::string& n)
{
	auto ib = n.cbegin();
	auto ie = n.cend()-1;

	for ( ; ib < ie; ++ib, --ie) {
		if (*ib != *ie)
			return false;
	}
	return true;

}
bool isPalindromic(int n) { return isPalindromic(std::to_string(n)); }

std::string convBinary(int n)
{
	std::stringstream ss;
	for ( ; n > 0; n /= 2)
		ss << n % 2;

	std::string str = ss.str();
	std::reverse(str.begin(), str.end());
	return str;
}

int problem36()
{
	int sum = 0;

	for (int n = 0; n < 1000000; ++n) {
		if (isPalindromic(n) && isPalindromic(convBinary(n)))
			sum += n;
	}
	return sum;
}

int main(void)
{
	assert(convBinary(585) == "1001001001");
	assert(isPalindromic("585") == true);
	assert(isPalindromic(convBinary(585)) == true);

	std::cout << problem36() << std::endl;
}
