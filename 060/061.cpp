/******************************************************************
 * Problem 61 †
 * 
 * 三角数, 四角数, 五角数, 六角数, 七角数, 八角数は多角数であり, それぞれ以下の式で生成される.
 * 三角数	P3,,n = n(n+1)/2	1, 3, 6, 10, 15, ...
 * 四角数	P4,,n = n^2       	1, 4, 9, 16, 25, ...
 * 五角数	P5,,n = n(3n-1)/2	1, 5, 12, 22, 35, ...
 * 六角数	P6,,n = n(2n-1)	1, 6, 15, 28, 45, ...
 * 七角数	P7,,n = n(5n-3)/2	1, 7, 18, 34, 55, ...
 * 八角数	P8,,n = n(3n-2)	1, 8, 21, 40, 65, ...
 * 
 * 3つの4桁の数の順番付きの集合 (8128, 2882, 8281) は以下の面白い性質を持つ.
 * 
 *    1. この集合は巡回的である. 最後の数も含めて, 各数の後半2桁は次の数の前半2桁と一致する
 *    2. それぞれ多角数である: 三角数 (P3,127=8128), 四角数 (P4,91=8281), 五角数 (P5,44=2882) が
 *       それぞれ別の数字で集合に含まれている
 *    3. 4桁の数の組で上の2つの性質をもつはこの組だけである.
 * 
 * 同じように, 6つの4桁の数からなる順番付きの集合で,
 * 
 *    1. 集合は巡回的である
 *    2. 三角数, 四角数, 五角数, 六角数, 七角数, 八角数が全て表れる唯一の集合を求め, その和を求めよ.
 ******************************************************************/
#include <iostream>
#include <functional>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

std::vector<std::function<int(int)>> polygonal_vec = {
	[] (int n) { return n*(n+1)/2;   },
	[] (int n) { return n*n;         },
	[] (int n) { return n*(3*n-1)/2; },
	[] (int n) { return n*(2*n-1);   },
	[] (int n) { return n*(5*n-3)/2; },
	[] (int n) { return n*(3*n-2);   }
};

template <class T>
bool isPolygonalNum(const int num, T& func)
{
	for (int n = 1; ; ++n) {
		int tmp = func(n);
		if (tmp == num)
			return true;
		if (num < tmp)
			return false;
	}
}

int checkPolygonalNum(int n)
{
	for (int i = 5; i != -1; --i)
		if (isPolygonalNum(n, polygonal_vec[i]))
			return i;
	return -1;
}

bool isAllOK(const std::vector<int>& v)
{
	for (size_t i = 0; i < v.size(); ++i) {
		if (v[i] != 1)
			return false;
	}
	return true;
}

int func(int n, std::vector<int>& v, std::vector<int>& v2)
{
	if (v2.size() == 6 && v2.front()/100 == v2.back()%100 && isAllOK(v))
		return 0;

	const int i = checkPolygonalNum(n), t = n%100*100;
	if (i != -1 && v[i] == 0 && t > 1000) {
		v[i] = 1; v2.push_back(n);
		for (int m = t; m < t+100; m++) {
			const int sum = func(m, v, v2);
			if (sum != -1)
				return n + sum;
		}
		v[i] = 0; v2.pop_back();
	}
	return -1;
}

int problem61(void)
{
	for (int n = 1000; n < 10000; n++) {
		std::vector<int> v(6, 0), v2;
		const int sum = func(n, v, v2);
		if (sum != -1)
			return sum;
	}
	return -1;
}

int main(void)
{
	std::cout << problem61() << std::endl;
}
