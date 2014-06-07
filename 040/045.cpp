/******************************************************************
 * Problem 45 「三角数, 五角数, 六角数」
 * 
 * 三角数, 五角数, 六角数は以下のように生成される.
 *     三角数 Tn=n(n+1)/2   1, 3, 6, 10, 15, ...
 *     五角数 Pn=n(3n-1)/2  1, 5, 12, 22, 35, ...
 *     六角数 Hn=n(2n-1)    1, 6, 15, 28, 45, ...
 * 
 * T285 = P165 = H143 = 40755であることが分かる.
 * 次の三角数かつ五角数かつ六角数な数を求めよ.
 ******************************************************************/
#include <iostream>
#include <cmath>
#include <assert.h>

long Triangle(long n)   { return (n*(n+1)/2);   }
long Pentagonal(long n) { return (n*(3*n-1)/2); }
long Hexagonal(long n)  { return (n*(2*n-1));   }

int problem45()
{
	int Tn = 286, Pn = 166, Hn = 144;
	long tri = Triangle(Tn);
	long pen = Pentagonal(Pn);
	long hex = Hexagonal(Hn);

	while (tri != pen && pen != hex) {
		if (tri <= pen && tri <= hex)
			tri = Triangle(++Tn);
		if (pen <= tri && pen <= hex)
			pen = Pentagonal(++Pn);
		if (hex <= tri && hex <= pen)
			hex = Hexagonal(++Hn);
	}
	return tri;
}

int main(void)
{
	assert(Triangle(285) == 40755);
	assert(Pentagonal(165) == 40755);
	assert(Hexagonal(143) == 40755);

	std::cout << problem45() << std::endl;
}
