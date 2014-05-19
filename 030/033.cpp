//////////////////////////////////////////////////////////////////////
// Problem 33  
// 
// 49/98は面白い分数である.
// 「分子・分母の9をキャンセルしたので 49/98 = 4/8 が得られた」と
// 経験を積んでいない数学者が誤って思い込んでしまうかもしれないからである.
// 我々は 30/50 = 3/5 のようなタイプは自明な例だとする.
// 1より小さく分子・分母がともに2桁の数になるような自明でない分数は 4個ある.
// その4個の分数の積が約分された形で与えられたとき, 分母の値を答えよ.
//////////////////////////////////////////////////////////////////////
#include <iostream>

void division(int& i, int& j)
{
	int n = 2;

	while (1) {
		if (i % n == 0 && j % n == 0) {
			i /= n;
			j /= n;
			n = 2;
		} else {
			if (i == 1 || j == 1 || i == n || j == n)
				break;
			++n;
		}
	}
}

void check(int i, int j, int k, int l, int& d1, int& d2)
{
	division(i, j);
	division(k, l);
	if (i == k && j == l) {
		d1 *= i;
		d2 *= j;
	}
}

int main(void)
{
	int numerator = 1, denominator = 1; // 分子, 分母 

	for (int i = 11; i < 100; ++i) {
		for (int j = i+1; j < 100; ++j) {
			const int i1 = i%10, i10 = i/10;
			const int j1 = j%10, j10 = j/10;

			if (i1 == 0 || j1 == 0)
				continue;
			if (i/10 == j/10 || i%10 == j%10)
				continue;
			if (i1 == i10 || j1 == j10)
				continue;
			if (i10 != j1 && i1 != j10)
				continue;

			if (i10 == j1 && i1 < j10)
				check(i, j, i1, j10, numerator, denominator);
			else if (i1 == j10 && i10 < j1)
				check(i, j, i10, j1, numerator, denominator);
		}
	}

	division(numerator, denominator);
	std::cout << denominator << std::endl;
}
