//////////////////////////////////////////////////////////////////////
// Problem 17  
// 
// 1 から 5 までの数字を英単語で書けば one, two, three, four, five であり、
// 全部で 3 + 3 + 5 + 4 + 4 = 19 の文字が使われている。
// では 1 から 1000 (one thousand) までの数字をすべて英単語で書けば、全部で何文字になるか。
// 注: 空白文字やハイフンを数えないこと。
//
// 例えば、342 (three hundred and forty-two) は 23 文字、
// 115 (one hundred and fifteen) は20文字と数える。
// なお、"and" を使用するのは英国の慣習。
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <assert.h>

const std::map<int, std::string> conv = {
	{1,  "one"},
	{2,  "two"},
	{3,  "three"},
	{4,  "four"},
	{5,  "five"},
	{6,  "six"},
	{7,  "seven"},
	{8,  "eight"},
	{9,  "nine"},
	{10, "ten"},
	{11, "eleven"},
	{12, "twelve"},
	{13, "thirteen"},
	{14, "fourteen"},
	{15, "fifteen"},
	{16, "sixteen"},
	{17, "seventeen"},
	{18, "eighteen"},
	{19, "nineteen"},
	{20, "twenty"},
	{30, "thirty"},
	{40, "forty"},
	{50, "fifty"},
	{60, "sixty"},
	{70, "seventy"},
	{80, "eighty"},
	{90, "ninety"},
	{100,"hundred"},
	{1000, "thousand"}
};

int convEnglishNum(const int n)
{
	std::stringstream ss;
	if (n < 20 || (n < 100 && n%10 == 0))
		ss << conv.at(n);
	else if (n == 100 || n == 1000)
		ss << conv.at(1) << conv.at(n);
	else {
		if (100 < n) {
			ss << conv.at(n/100) << conv.at(100);
			if (n%100 != 0)
				ss << "and";
		}
		if (n%100 != 0) {
			if (n%100 < 20 || n%10 == 0)
				ss << conv.at(n%100);
			else
				ss << conv.at(n%100-n%10) << conv.at(n%10);
		}
	}
	return ss.str().length();
}

int problem17(const int n)
{
	int count = 0;
	for (int i = 1; i <= n; ++i) {
		count += convEnglishNum(i);
	}
	return count;
}

int main(void)
{
	assert(convEnglishNum(342) == 23);
	assert(convEnglishNum(115) == 20);

	std::cout << problem17(1000) << std::endl;
}


