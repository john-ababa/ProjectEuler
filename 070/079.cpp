/******************************************************************
 * Problem 79 「パスコードの導出」  
 * 
 * オンラインバンクで通常使われるsecurity methodは,
 * パスコードからランダムに選んだ3文字をユーザーに要求するものである.
 * たとえば, パスコードが531278のとき, 2番目, 3番目, 5番目の文字を要求されるかもしれない.
 * このとき, 期待される答えは: 317 である.
 *
 * テキストファイルkeylog.txtには, ログインに成功した50回の試行が記録されている.
 * 3つの文字が常に順番通りに要求されるとするとき, ファイルを分析して,
 * 可能なパスコードのなかでもっとも短いものを見つけよ.
 ******************************************************************/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

template <typename T>
void uniqSort(T& a)
{
	std::sort(a.begin(), a.end());
	a.erase(std::unique(a.begin(), a.end()), a.end());
}

char getDiff(std::string& str1, std::string& str2)
{
	std::string s; s.resize(10);
	std::set_symmetric_difference(str1.begin(), str1.end(), str2.begin(), str2.end(), s.begin());
	return s[0];
}

char getFirst(const std::vector<std::string>& vec, std::string second)
{
	std::string str = "";
	for (auto itr = vec.cbegin(); itr != vec.cend(); ++itr)
		str += *itr;
	uniqSort(str);
	return getDiff(str, second);
}

std::string getSecond(const std::vector<std::string>& vec)
{
	std::string str = "";
	for (auto itr = vec.cbegin(); itr != vec.cend(); ++itr)
		str += itr->substr(1);
	uniqSort(str);
	return str;
}

std::vector<std::string> readFile(void)
{
	std::vector<std::string> vec;

	std::ifstream ifs("p079_keylog.txt");
	for (std::string line; std::getline(ifs, line); )
		vec.push_back(line);
	uniqSort(vec);

	return vec;
}

void removeNum(std::vector<std::string>& vec, const char c)
{
	std::vector<std::string> new_vec;
	for (auto itr = vec.begin(); itr != vec.end(); ++itr) {
		auto p = std::remove_if(
				itr->begin(), itr->end(), [&](char x) {return x == c;});
		itr->erase(p, itr->end());

		if (!itr->empty())
			new_vec.push_back(*itr);
	}
	vec = new_vec;
}

std::string problem79(void)
{
	std::vector<std::string> vec = readFile();

	std::stringstream ss;
	while (!vec.empty()) {
		const char c = getFirst(vec, getSecond(vec));
		ss << c;
		removeNum(vec, c);
	}
	return ss.str();
}

int main(void)
{
	std::cout << problem79() << std::endl;
}
