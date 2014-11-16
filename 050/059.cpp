/******************************************************************
 * Problem 59 「XOR暗号解読」
 * 
 * 各文字はそれぞれ一意のコードに割り当てられている.
 * よく使われる標準としてASCII (American Standard Code for Information Interchange) がある.
 * ASCIIでは, 大文字A = 65, アスタリスク (*) = 42, 小文字k = 107というふうに割り当てられている.
 *
 * モダンな暗号化の方法として, テキストファイルの各バイトをASCIIに変換し,
 * 秘密鍵から計算された値とXORを取るという手法がある. XOR関数の良い点は,
 * 暗号化に用いたのと同じ暗号化鍵でXORを取ると平文を復号できる点である.
 * 65 XOR 42 = 107であり, 107 XOR 42 = 65である.
 *
 * 破られない暗号化のためには, 鍵は平文と同じ長さのランダムなバイト列でなければならない.
 * ユーザーは暗号文と暗号化鍵を別々の場所に保存する必要がある.
 * また, もし一方が失われると, 暗号文を復号することは不可能になる.
 * 悲しいかな, この手法はほとんどのユーザーにとって非現実的である.
 *
 * そこで, 鍵の変わりにパスワードを用いる手法が用いられる.
 * パスワードが平文より短ければ (よくあることだが), パスワードは鍵として繰り返し用いられる.
 * この手法では, 安全性を保つために十分長いパスワードを用いる必要があるが,
 * 記憶するためにはある程度短くないといけない.
 *
 * この問題での課題は簡単になっている. 暗号化鍵は3文字の小文字である.
 * cipher.txtは暗号化されたASCIIのコードを含んでいる.
 * また, 平文はよく用いられる英単語を含んでいる.
 * この暗号文を復号し, 平文のASCIIでの値の和を求めよ.
 ******************************************************************/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main(void)
{
	std::vector<int> str, key(3);
	std::ifstream ifs("cipher.txt");
	for (std::string line; std::getline(ifs, line, ','); )
		str.push_back(std::stoi(line));

	for (int i = 'a'; i <= 'z'; ++i) {
		key[0] = i;
		for (int j = 'a'; j <= 'z'; ++j) {
			key[1] = j;
			for (int k = 'a'; k <= 'z'; ++k) {
				key[2] = k;

				std::stringstream ss;
				int c = 0, sum = 0;
				for (auto n = str.begin(); n != str.end(); ++n, c++) {
					ss << (char)(*n ^ key[c % 3]);
					sum += *n ^ key[c % 3];
				}
				if (ss.str().find(" the ") != std::string::npos) {
					std::cout << sum << std::endl;
					std::cout << ss.str() << std::endl;
				}
			}
		}
	}
}
