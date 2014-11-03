/******************************************************************
 * Problem 54
 *
 * カードゲームのポーカーでは, 手札は5枚のカードからなりランク付けされている.
 * 役を低い方から高い方へ順に並べると以下である.
 *   0. 役無し: 一番値が大きいカード
 *   1. ワン・ペア: 同じ値のカードが2枚
 *   2. ツー・ペア: 2つの異なる値のペア
 *   3. スリーカード: 同じ値のカードが3枚
 *   4. ストレート: 5枚の連続する値のカード
 *   5. フラッシュ: 全てのカードが同じスート
 *      (注: スートとはダイヤ・ハート・クラブ/スペードというカードの絵柄のこと)
 *   6. フルハウス: スリーカードとペア
 *   7. フォーカード: 同じ値のカードが4枚
 *   8. ストレートフラッシュ: ストレートかつフラッシュ
 *   9. ロイヤルフラッシュ: 同じスートの10, J, Q, K, A
 * 
 * ここでカードの値は小さい方から2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, Aである.
 * (訳注：データ中で10は'T'と表される)
 * もし2人のプレイヤーが同じ役の場合には,
 * 役を構成する中で値が最も大きいカードによってランクが決まる:
 * 例えば, 8のペアは5のペアより強い (下の例1を見よ).
 * それでも同じランクの場合には (例えば, 両者ともQのペアの場合),
 * 一番値が大きいカードによってランクが決まる (下の例4を見よ).
 * 一番値が大きいカードが同じ場合には, 次に値が大きいカードが比べれられ,
 * 以下同様にランクを決定する.
 * 
 * 例:
 *    プレイヤー1                       プレイヤー2                         勝者
 * 1  5H 5C 6S 7S KD (5のペア)          2C 3S 8S 8D TD (8のペア)            プレイヤー2
 * 2  5D 8C 9S JS AC (役無し, A)        2C 5C 7D 8S QH (役無し, Q)          プレイヤー1
 * 3  2D 9C AS AH AC (Aのスリーカード)  3D 6D 7D TD QD (ダイヤのフラッシュ) プレイヤー2
 * 4  4D 6S 9H QH QC (Qのペア, 9)       3D 6D 7H QD QS (Qのペア, 7)         プレイヤー1
 * 5  2H 2D 4C 4D 4S (4-2のフルハウス   3C 3D 3S 9S 9D (3-9のフルハウス)    プレイヤー1
 * 
 * http://projecteuler.net/project/poker.txt
 * poker.txtには1000個のランダムな手札の組が含まれている.
 * 各行は10枚のカードからなる (スペースで区切られている):
 * 最初の5枚がプレイヤー1の手札であり, 残りの5枚がプレイヤー2の手札である.
 * 
 * 以下のことを仮定してよい
 *   * 全ての手札は正しい (使われない文字が出現しない. 同じカードは繰り返されない)
 *   * 各プレイヤーの手札は特に決まった順に並んでいるわけではない
 *   * 各勝負で勝敗は必ず決まる
 * 
 * 1000回中プレイヤー1が勝つのは何回か?
 ******************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <assert.h>

std::vector<std::string> split(const std::string &str, char delim)
{
	std::vector<std::string> vec;
	size_t current = 0, found;

	while ((found = str.find_first_of(delim, current)) != std::string::npos) {
		vec.push_back(std::string(str, current, found - current));
		current = found + 1;
	}
	vec.push_back(std::string(str, current, str.size() - current));
	return vec;
}

std::vector<int> sortCards(const std::vector<std::string>& vec)
{
	std::vector<int> cards;
	for (size_t i = 0; i < vec.size(); ++i) {
		switch (vec[i][0]) {
		case 'T': cards.push_back(10); break;
		case 'J': cards.push_back(11); break;
		case 'Q': cards.push_back(12); break;
		case 'K': cards.push_back(13); break;
		case 'A': cards.push_back(14); break;
		default : cards.push_back(vec[i][0] - '0');
		}
	}
	std::sort(cards.begin(), cards.end());
	return cards;
}

std::vector<int> countCards(const std::vector<std::string>& vec)
{
	const std::vector<int> card = sortCards(vec);

	std::vector<int> table(15, 0);
	for (size_t i = 0; i < card.size(); ++i)
		++table[card[i]];
	return table;
}

int getHighCard(const std::vector<std::string>& vec, const int pflag = 0)
{
	if (pflag != 0) {
		const std::vector<int> table = countCards(vec);
		if (pflag == 1)
			return std::distance(table.begin(), std::find(table.begin(), table.end(), 2));
		else if (pflag == 2) {
			const auto p1 = std::find(table.begin(), table.end(), 2);
			const auto p2 = std::find(p1+1, table.end(), 2);
			return std::max(*p1, *p2);
		} else if (pflag == 3)
			return std::distance(table.begin(), std::find(table.begin(), table.end(), 3));
		else if (pflag == 4)
			return std::distance(table.begin(), std::find(table.begin(), table.end(), 4));
	} else {
		const std::vector<int> card = sortCards(vec);
		return *std::max_element(card.begin(), card.end());
	}
	return -1;
}

bool isOnePair(const std::vector<std::string>& vec)
{
	const std::vector<int> table = countCards(vec);
	if (std::count(table.begin(), table.end(), 2) == 1)
		return true;
	return false;
}

bool isTwoPair(const std::vector<std::string>& vec)
{
	const std::vector<int> table = countCards(vec);
	if (std::count(table.begin(), table.end(), 2) == 2)
		return true;
	return false;
}

bool isThreeCard(const std::vector<std::string>& vec)
{
	const std::vector<int> table = countCards(vec);
	if (std::count(table.begin(), table.end(), 3) == 1)
		return true;
	return false;
}

bool isStraight(const std::vector<std::string>& vec)
{
	const std::vector<int> card = sortCards(vec);
	for (size_t i = 0; i < card.size(); ++i) {
		if (card[i] != card[0] + (int)i)
			return false;
	}
	return true;
}

bool isFlush(const std::vector<std::string>& vec)
{
	for (size_t i = 0; i < vec.size(); ++i) {
		if (vec[i][1] != vec[0][1])
			return false;
	}
	return true;
}

bool isFullHouse(const std::vector<std::string>& vec)
{
	if (isTwoPair(vec) && isThreeCard(vec))
		return true;
	return false;
}

bool isFourCard(const std::vector<std::string>& vec)
{
	std::vector<int> table = countCards(vec);
	if (std::count(table.begin(), table.end(), 4) == 1)
		return true;
	return false;
}

bool isStraightFlush(const std::vector<std::string>& vec)
{
	if (isStraight(vec) && isFlush(vec))
		return true;
	return false;
}

bool isRoyalFlush(const std::vector<std::string>& vec)
{
	const std::vector<int> card = sortCards(vec);
	for (size_t i = 0; i < card.size(); ++i) {
		if (card[i] != (int)i+10)
			return false;
	}
	return true;
}

int score(const std::vector<std::string>& vec)
{
	if (isRoyalFlush(vec))
		return 900;
	if (isStraightFlush(vec))
		return 800 + getHighCard(vec);
	if (isFourCard(vec))
		return 700 + getHighCard(vec, 4);
	if (isFullHouse(vec))
		return 600 + getHighCard(vec, 3);
	if (isFlush(vec))
		return 500 + getHighCard(vec);
	if (isStraight(vec))
		return 400 + getHighCard(vec);
	if (isThreeCard(vec))
		return 300 + getHighCard(vec, 3);
	if (isTwoPair(vec))
		return 200 + getHighCard(vec, 2);
	if (isOnePair(vec))
		return 100 + getHighCard(vec, 1);
	return getHighCard(vec);
}

int checkHighCard(const std::vector<std::string>& player1, const std::vector<std::string>& player2)
{
	const std::vector<int> card1 = sortCards(player1);
	const std::vector<int> card2 = sortCards(player2);

	for (int i = card1.size(); i != -1; --i) {
		if (card1[i] < card2[i])
			return 0;
		else if (card1[i] > card2[i])
			return 1;
	}
	return -1; // draw
}

bool isWinPlayer1(const std::string& line)
{
	const std::vector<std::string> v = split(line, ' ');
	const std::vector<std::string> player1(v.begin(), v.begin()+5);
	const std::vector<std::string> player2(v.begin()+5, v.end());

	const int score1 = score(player1);
	const int score2 = score(player2);
	if (score1 > score2)
		return true;
	else if (score1 == score2)
		return checkHighCard(player1, player2);
	else
		return false;
}

int problem054()
{
	std::ifstream ifs("poker.txt");
	int count = 0;

	for (std::string line; std::getline(ifs, line); ) {
		if (isWinPlayer1(line))
			++count;
	}
	return count;
}

int main(void)
{
	assert(isWinPlayer1("5H 5C 6S 7S KD 2C 3S 8S 8D TD") == false);
	assert(isWinPlayer1("5D 8C 9S JS AC 2C 5C 7D 8S QH") == true);
	assert(isWinPlayer1("2D 9C AS AH AC 3D 6D 7D TD QD") == false);
	assert(isWinPlayer1("4D 6S 9H QH QC 3D 6D 7H QD QS") == true);
	assert(isWinPlayer1("2H 2D 4C 4D 4S 3C 3D 3S 9S 9D") == true);

	std::cout << problem054() << std::endl;
}
