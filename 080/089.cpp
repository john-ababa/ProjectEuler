/******************************************************************
 * Problem 89 「ローマ数字」  
 * 
 * ローマ数字の記法は一つの数について沢山ある場合が存在する (FAQを見よ).
 * しかし, ある数については最良の記法が必ず存在する. 例えば, 16の正しい記法を全て並べてみる.
 *     IIIIIIIIIIIIIIII
 *     VIIIIIIIIIII
 *     VVIIIIII
 *     XIIIIII
 *     VVVI
 *     XVI
 * 最後の例は, 最小の文字数で表せるという意味で, 最も効率が良い.
 *
 * 11Kのテキストファイル roman.txt は1000個のローマ記法で書かれた数を含んでいる. 
 * これらは, 正しい記法に従っている. 即ち, 大きい数から順に書かれていて,
 * 引き算ペアのルールにも従っている (このルールについてはFAQを見よ)
 * 但し, 最小の文字数で表されているとは限らない. 最小形で書いたときに, 何文字節約できるかを求めよ.
 * 注: ファイル中の全てのローマ数字には, 5つ以上の同じ文字が連続して含まれることはない.
 *
 * FAQ: ローマ数字のルール * (訳者:概略のみ与える)
 *     | I | V | X  | L  | C   | D   | M
 *     | 1 | 5 | 10 | 50 | 100 | 500 | 1000
 * 基本法則1
 *     全ての文字はサイズの降順に並ぶ
 * 基本法則2
 *     引き算ペアについて.
 *     X (10) + IX (9) として19=XIXと表せる. ただし, 8をIIXと二文字以上を引くことは許されない.
 *         * I, X, Cのみが引き算ペアの最初の文字として許される.
 *         * IはVまたはXの前に来ることが許される
 *         * XはLまたはCの前に来ることが許される
 *         * CはDまたはMの前に来ることが許される
 ******************************************************************/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

std::map<char, int> m  = {
	{ 'I', 1    },
	{ 'V', 5    },
	{ 'X', 10   },
	{ 'L', 50   },
	{ 'C', 100  },
	{ 'D', 500  },
	{ 'M', 1000 }
};

int convertNum(const std::string& str)
{
	int sum = 0;
	for (auto itr = str.cbegin(); itr != str.cend(); ++itr) {
		if (*itr == 'I' && (itr+1 != str.cend() && *(itr+1) == 'V')) {
			sum += 4; ++itr;
		} else if (*itr == 'I' && (itr+1 != str.cend() && *(itr+1) == 'X')) {
			sum += 9; ++itr;
		} else if (*itr == 'X' && (itr+1 != str.cend() && *(itr+1) == 'L')) {
			sum += 40; ++itr;
		} else if (*itr == 'X' && (itr+1 != str.cend() && *(itr+1) == 'C')) {
			sum += 90; ++itr;
		} else if (*itr == 'C' && (itr+1 != str.cend() && *(itr+1) == 'D')) {
			sum += 400; ++itr;
		} else if (*itr == 'C' && (itr+1 != str.cend() && *(itr+1) == 'M')) {
			sum += 900; ++itr;
		} else {
			sum += m[*itr];
		}
	}
	return sum;
}

std::string convertX(int r, const char t, const char f, const char o)
{
	std::stringstream ss;

	switch (r) {
	case 9: ss << o << t; break;
	case 4: ss << o << f; break;
	case 8: case 7: case 6: case 5: ss << f; r -= 5; //fall
	default: if (r != 0) ss << std::string(r, o);
	}
	return ss.str();
}

std::string convertRomanNum(int sum)
{
	std::stringstream roman;

	if (sum >= 1000) {
		roman << std::string("M", (sum / 1000 % 1000));
		sum -= (sum / 1000) * 1000;
	}
	if (sum >= 100) {
		roman << convertX(sum / 100 % 100, 'M', 'D', 'C');
		sum -= (sum / 100) * 100;
	}
	if (sum >= 10) {
		roman << convertX(sum / 10 % 10, 'C', 'L', 'X');
		sum -= (sum / 10) * 10;
	}
	if (sum > 0) {
		roman << convertX(sum%10, 'X', 'V', 'I');
	}

	return roman.str();
}

int problem89(void)
{
	int diff = 0;
	std::ifstream ifs("p089_roman.txt");
	for (std::string line; std::getline(ifs, line); )
		diff += line.length() - convertRomanNum(convertNum(line)).length();
	return diff;
}

int main(void)
{
	std::cout << problem89() << std::endl;
}
