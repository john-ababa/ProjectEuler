/******************************************************************
 * Problem 62
 *
 * 立方数 41063625 (345^3) は, 桁の順番を入れ替えると2つの立方数になる:
 * 56623104 (384^3) と 66430125 (405^3) である.
 * 41063625は, 立方数になるような桁の置換をちょうど3つもつ最小の立方数である.
 *
 * 立方数になるような桁の置換をちょうど5つもつ最小の立方数を求めよ.
 ******************************************************************/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

typedef unsigned long long ull;

template<class Map, class Key>
void updateMap(Map& m, const Key& k)
{
	typename Map::iterator it = m.lower_bound(k);
	if (it != m.end() && !m.key_comp()(k, it->first))
		it->second++;
	else
		m.insert(it, typename Map::value_type(k, 1));
}

std::string makeHash(const ull cb)
{
	std::vector<int> v(10, 0);
	for (ull n = cb; n != 0; n /= 10)
		v[n % 10]++;

	std::stringstream ss;
	for (size_t i = 0; i < v.size(); ++i)
		ss << i << v[i];
	return ss.str();
}

ull problem62(void)
{
	std::map<std::string, int> m;
	for (ull i = 1; i < 10000; ++i)
		updateMap(m, makeHash(i*i*i));

	for (ull i = 1; i < 10000; ++i) {
		auto itr = m.find(makeHash(i*i*i));
		if (itr != m.end() && itr->second == 5)
			return i*i*i;
	}
	return -1;
}

int main(void)
{
	std::cout << problem62() << std::endl;
}
