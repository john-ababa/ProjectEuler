/******************************************************************
 * Problem 57
 *
 * 2の平方根は無限に続く連分数で表すことができる.
 * √ 2 = 1 + 1/(2 + 1/(2 + 1/(2 + ... ))) = 1.414213...
 * 最初の4回の繰り返しを展開すると以下が得られる.
 *   * 1 + 1/2 = 3/2 = 1.5
 *   * 1 + 1/(2 + 1/2) = 7/5 = 1.4
 *   * 1 + 1/(2 + 1/(2 + 1/2)) = 17/12 = 1.41666...
 *   * 1 + 1/(2 + 1/(2 + 1/(2 + 1/2))) = 41/29 = 1.41379...
 * 次の3つの項は99/70, 239/169, 577/408である. 第8項は1393/985である.
 * これは分子の桁数が分母の桁数を超える最初の例である.
 * 最初の1000項を考えたとき, 分子の桁数が分母の桁数を超える項はいくつか?
 ******************************************************************/
#include <iostream>
#include <cmath>

int problem057(void)
{
	long double numer = 3, denom = 2; // 分子, 分母 

	int count = 0;
	for (int i = 1; i < 1000; ++i) {
		const long double tmp_numer = numer + denom * 2;
		const long double tmp_denom = numer + denom;
		numer = tmp_numer;
		denom = tmp_denom;
		if ((int)log10l(numer)+1 > (int)log10l(denom)+1)
			++count;
	}
	return count;
}

int main(void)
{
	std::cout << problem057() << std::endl;;
}
