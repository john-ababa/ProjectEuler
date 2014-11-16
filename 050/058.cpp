/******************************************************************
 * Problem 58
 * 
 * 1から初めて, 以下のように反時計回りに数字を並べていくと, 辺の長さが7の渦巻きが形成される.
 *    37  36  35  34  33  32  31
 *    38  17  16  15  14  13  30
 *    39  18   5   4   3  12  29
 *    40  19   6   1   2  11  28
 *    41  20   7   8   9  10  27
 *    42  21  22  23  24  25  26
 *    43  44  45  46  47  48  49
 * 面白いことに, 奇平方数が右下の対角線上に出現する.
 * もっと面白いことには, 対角線上の13個の数字のうち, 8個が素数である.
 * ここで割合は8/13 ≈ 62%である.
 * 
 * 渦巻きに新しい層を付け加えよう. すると辺の長さが9の渦巻きが出来る.
 * 以下, この操作を繰り返していく. 対角線上の素数の割合が10%未満に落ちる最初の辺の長さを求めよ.
 ******************************************************************/
#include <iostream>
#include <vector>
#include "../common/common.h"

int problem058(void)
{
	std::vector<int> vec = {1};
	int all_count = 1,  prime_count = 0;

	for (int edge = 3; ; edge+=2) {
		const int right_top = (edge*edge) - ((edge-1) * 3);
		for (int i = 0; i < 4; ++i) {
			++all_count;
			prime_count += (int)Euler::isPrime(right_top + (edge-1)*i);
		}

		if ((double)prime_count / (double)all_count <= 0.10)
			return edge;
	}
}

int main(void)
{
	std::cout << problem058() << std::endl;
}
