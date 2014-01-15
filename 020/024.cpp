//////////////////////////////////////////////////////////////////////
// Problem 24  
// 
// 順列とはモノの順番付きの並びのことである.
// たとえば, 3124は数1, 2, 3, 4の一つの順列である.
// すべての順列を数の大小でまたは辞書式に並べたものを辞書順と呼ぶ.
// 0と1と2の順列を辞書順に並べると
// 012 021 102 120 201 210
// になる.
// 0,1,2,3,4,5,6,7,8,9からなる順列を辞書式に並べたときの100万番目を答えよ

//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <algorithm>
#include <assert.h>

std::string problem24(std::string str, int n)
{
	int count = 0;
	while (++count != n)
		next_permutation(str.begin(), str.end());
	return str;
}

int main(void)
{
	assert(problem24("012", 6) == "210");

	std::cout << problem24("0123456789", 1000000) << std::endl;
}
