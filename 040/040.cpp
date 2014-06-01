/******************************************************************
 * Problem 40 「チャンパーノウン定数」
 * 
 * 正の整数を順に連結して得られる以下の10進の無理数を考える:
 * 0.123456789101112131415161718192021...
 * 
 * 小数第12位は1である. dnで小数第n位の数を表す.
 * d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000 を求めよ.
 ******************************************************************/
#include <iostream>
#include <cmath>
#include <assert.h>

int problem40()
{
	int result = 1, len = 0, d = 1;

	for (int i = 1; len <= 1000000; ++i) {
		len += ((int)std::log10(i))+1;
		if (d <= len) {
			const int tmp = len - (((int)std::log10(i))+1);
			const std::string n = std::to_string(i);
			for (size_t p = 0; p < n.length(); ++p) {
				if ((size_t)d == tmp + p + 1)
					result *= (n[p] - '0');
			}
			d *= 10;
		}
	}
	return result;
}

int main(void)
{
	std::cout << problem40() << std::endl;
}
