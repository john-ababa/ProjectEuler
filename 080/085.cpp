/******************************************************************
 * Problem 85 「長方形の数え上げ」  
 * 
 * 注意深く数えると, 横が3, 縦が2の長方形の格子には, 18個の長方形が含まれている.
 *     [image here]
 * ぴったり2,000,000個の長方形を含むような長方形の格子は存在しない.
 * 一番近い解を持つような格子の面積を求めよ.
 ******************************************************************/
#include <iostream>
#include <assert.h>

int countRectangle(int row, int col)
{
	int n = 0;
	for (int i = 1; i <= row; ++i) {
		for (int j = 1; j <= col; ++j)
			n += i * j;
	}
	return n;
}

int problem85(void)
{
	int result = 0, min = 2000000;

	for (int i = 1; i < 200; ++i) {
		for (int j = 1; j < 200; ++j) {
			const int n = countRectangle(i, j);
			if (std::abs(2000000 - n) < min) {
				min = std::abs(2000000 - n);
				result = i * j;
			}
		}
	}
	return result;
}

int main(void)
{
	assert(countRectangle(2, 3) == 18);

	std::cout << problem85() << std::endl;
}
