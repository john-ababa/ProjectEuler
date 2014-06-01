/******************************************************************
 * Problem 38 「パンデジタル倍数」
 * 
 * 192 に 1, 2, 3 を掛けてみよう.
 *   192 × 1 = 192
 *   192 × 2 = 384
 *   192 × 3 = 576
 * 積を連結することで1から9の パンデジタル数 192384576 が得られる.
 * 192384576 を 192 と (1,2,3) の連結積と呼ぶ.
 * 
 * 同じようにして, 9 を 1,2,3,4,5 と掛け連結することで
 * パンデジタル数 918273645 が得られる. これは 9 と (1,2,3,4,5) との連結積である.
 * 
 * 整数と (1,2,...,n) (n > 1) との連結積として得られる9桁の
 * パンデジタル数の中で最大のものはいくつか?
 ******************************************************************/
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <assert.h>

bool isPandigital(int num)
{
	std::string str = std::to_string(num);
	std::sort(str.begin(), str.end());
	if (str == "123456789")
		return true;
	return false;
}

int makePandigital(int n)
{
	std::stringstream ss;
	for (int i = 1; i < 10; ++i) {
		ss << n * i;
		if (ss.str().length() == 9)
			return std::stoi(ss.str());
	}
	return -1;
}

int problem38()
{
	for (int n = 9876; n != 0; --n) {
		int result = makePandigital(n);
		if (result != -1 && isPandigital(result))
			return result;
	}
	return -1;
}

int main(void)
{
	assert(makePandigital(192) == 192384576);

	std::cout << problem38() << std::endl;
}
