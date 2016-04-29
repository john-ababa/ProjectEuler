/******************************************************************
 * Problem 86 「直方体のルート」  
 * 
 * 下に示す直方体は寸法が6*5*3である.
 * この直方体の1つの頂点Sにクモがいる. また反対の頂点Fにはハエがいる.
 * SからFまでの壁に沿って直線移動する最短ルートは図に示す通りで, この長さは10である.
 *   [image here]
 * この最短ルートの候補は3本あるが, 最短のものがいつも整数長さとは限らない.
 * さて, M*M*M以下の寸法の直方体について, 最短ルートが整数である直方体の数を考える.
 * M=100のとき, 条件を満たす直方体は2060個ある. このM=100は個数が2000を超える最小のMである.
 * なお, M=99のときは1975個である.  100万個を超える最小のMを求めよ.
 ******************************************************************/
#include <iostream>
#include <cmath>
#include <assert.h>

int countPythagoras(const int m)
{
	int count = 0;
	for (int a = 1; a <= m; ++a) {
		for (int b = a; b <= m; ++b) {
			const double n = std::sqrt(m*m + (a+b)*(a+b));
			if (n - std::floor(n) < 0.00001)
				++count;
		}
	}
	return count;
}

int problem86(int until = 1000000)
{
	int n = 0;
	for (int M = 1; ; ++M) {
		n += countPythagoras(M);
		if (n > until)
			return M;
	}
}

int main(void)
{
	assert(countPythagoras(6) == 3);
	assert(problem86(2000) == 100);
	
	std::cout << problem86() << std::endl;
}
