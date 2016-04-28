/******************************************************************
 * Problem 84 「モノポリーの確率」  
 * 
 * モノポリーの標準的な盤面は以下である:
 *     | GO  | A1 | CC1 | A2 | T1 | R1 | B1 | CH1 | B2 | B3 | JAIL
 *     | H2  |                                              | C1
 *     | T2  |                                              | U1
 *     | H1  |                                              | C2
 *     | CH3 |                                              | C3
 *     | R4  |                                              | R2
 *     | G3  |                                              | D1
 *     | CC3 |                                              | CC2
 *     | G2  |                                              | D2
 *     | G1  |                                              | D3
 *     | G2J | F3 | U2  | F2 | F1 | R3 | E3 | E2 | CH2 | E1 | FP
 *
 * 各プレイヤーはGOのマスから開始し, 2個の6面サイコロを用いて時計回りに進む.
 * 他のルールが無いとすれば, 各マスに止まる確率は全て等しく, 2.5%である.
 * しかし, G2J (Go To Jail), CC (Community Chest, 共同基金),
 * CH (Chance, チャンス) のマスによってこの確率は変えられてしまう.
 *
 * G2Jに止まる, または, CCやCHのマスに止まると引くカードのうちそれぞれ1枚によって,
 * プレイヤーはJAILのマスに飛ばされる. またプレイヤーが連続して3回ゾロ目を出すと,
 * 3投目の結果のマスに進むのではなく, 直接JAILのマスに飛ばされる.
 * (訳注: モノポリーではゾロ目が出るともう1回サイコロをふる.
 * 6,6→2,1の場合は合計15マス進む. 4,4→2,2→1,2の場合は合計15マス進む.
 * 3,3→4,4→2,2の場合は6マス目, 14マス目に止まったのちJAILに飛ばされる.)
 *
 * ゲーム開始前にCCカードとCHカードはシャッフルされる.
 * プレイヤーがCCまたはCHマスに止まった場合, プレイヤーはCCカードまたはCHカードの山の
 * 一番上からカードを1枚引く. カードの指示に従ったのち, そのカードは山の一番下に戻される.
 * それぞれのカードは16枚あるが, 今回は問題を進み方に限定するので, 移動の指示があるカードのみを考える.
 * 移動の指示が無いカードに関しては何もせずカードをそのまま山の下に戻す.
 * プレイヤーはそのままCC/CHマスに残るものとする.
 *
 *   Community Chest (16枚中2枚が移動カード)
 *   - GOへ進め
 *   - JAILへ進め
 *   Chance (16枚中10枚が移動カード)
 *   - GOへ進め
 *   - JAILへ進め
 *   - C1へ進め
 *   - E3へ進め
 *   - H2へ進め
 *   - R1へ進め
 *   - 次のRへ進め (Rはrailway company, 鉄道会社の意)
 *   - 次のRへ進め
 *   - 次のUへ進め (Uはutility company, 公共事業会社の意)
 *   - 3マス戻れ
 *
 * 今回考えるのは, どのマスに止まりやすいかである. 即ち, サイコロを投げた後に止まる確率である.
 * より正確には, サイコロを1回振ってカードやマスによる移動を終えた後に各マスに止まる確率を求めたい.
 * 従って, G2Jに止まる確率は0であり, CHマスに止まる確率はその次に少ない (16枚中10枚が移動カードなので).
 *
 * またJAILマスにたまたま止まることとJAILマスに送られることを区別しない.
 * またJAILマスから抜けるルール (自分のターンにゾロ目を2回出す) を無視する.
 * つまり必ず保釈金を払ってJAILマスから進むものとする.
 *
 * GOマスを00とし番号を00-39と順番に振る. これにより各マスを2桁の数で表すことが出来る.
 * 統計的には, 3つのマスに止まりやすいことを示せる.
 * JAIL (6.24%) = 10番目, E3 (3.18%) = 24番目, GO (3.09%) = 00番目である.
 * 従ってもっとも止まりやすいマスを6桁で表せて102400となる.
 *
 * 2つの6面サイコロではなくて, 2つの4面サイコロを用いた場合の, もっとも止まりやすいマスを6桁で表せ.
 * （翻訳ヒント、サイコロを振りぞろ目だろうがでなかろうが止まったマス目の指示に従う
 * カードマスならカードを引く。これを繰り返す。繰り返す途中で三連続でぞろ目が出たら強制的に刑務所行き）
 ******************************************************************/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <random>
#include <assert.h>

std::string drowCard(std::deque<std::string>& cards)
{
	const std::string card = cards.front();
	cards.pop_front();
	cards.push_back(card);
	return card;
}

std::deque<std::string> CH = {
	"GO", "JAIL", "C1", "E3", "H2", "R1", "R", "R", "U", "3", "-", "-", "-", "-", "-", "-"
};
std::deque<std::string> CC = {
	"GO", "JAIL", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"
};
std::vector<std::string> mass = {
	"GO",   "A1", "CC1", "A2",  "T1", "R1", "B1",  "CH1", "B2", "B3",
	"JAIL", "C1", "U1",  "C2",  "C3", "R2", "D1",  "CC2", "D2", "D3",
	"FP",   "E1", "CH2", "E2",  "E3", "R3", "F1",  "F2",  "U2", "F3",
	"G2J",  "G1", "G2",  "CC3", "G3", "R4", "CH3", "H1",  "T2", "H2"
};

std::string problem84(void)
{
	std::shuffle(CH.begin(), CH.end(), std::mt19937());
	std::shuffle(CC.begin(), CC.end(), std::mt19937());
	std::vector<int> counter = std::vector<int>(mass.size(), 0);

	std::random_device rnd;
	int p = 0, count = 0;
	for (int i = 0; i < 5000000; ++i) {
		const int dice1 = rnd() % 4 + 1;
		const int dice2 = rnd() % 4 + 1;

		count = (dice1 == dice2) ? count+1 : 0;
		p = (p + dice1 + dice2) % mass.size();

		if (count == 3 || mass[p] == "G2J") {
			p = 10;
			count = 0;
		} else {
			std::string card = "-", n = "";
			if (mass[p].find("CC") != std::string::npos)
				card = drowCard(CC);
			if (mass[p].find("CH") != std::string::npos)
				card = drowCard(CH);

			if (card != "-") {
				if (card == "R") {
					if (p < 5 || 35 <= p) n = "1";
					else if (5  <= p && p < 15) n = "2";
					else if (15 <= p && p < 25) n = "3";
					else if (25 <= p && p < 35) n = "4";
				} else if (card == "U") {
					if (p <= 12 || 28 < p) n = "1";
					else if (12 < p && p <= 28) n = "2";
				}
				p = (card == "3") ?
					p-3 : std::distance(mass.begin(), std::find(mass.begin(), mass.end(), card+n));
			}
		}
		counter[p] += 1;
	}

	std::vector<int> counter2 = counter;
	std::sort(counter2.begin(), counter2.end());

	std::stringstream ss;
	ss << std::distance(counter.begin(), std::find(counter.begin(), counter.end(), counter2[counter2.size()-1]));
    ss << std::distance(counter.begin(), std::find(counter.begin(), counter.end(), counter2[counter2.size()-2]));
    ss << std::distance(counter.begin(), std::find(counter.begin(), counter.end(), counter2[counter2.size()-3]));
	return ss.str();
}

int main(void)
{
	std::cout << problem84() << std::endl;
}
