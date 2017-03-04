/******************************************************************
 * Problem 93 「算術式」  
 * 
 * 集合 {1, 2, 3, 4} の各数字をちょうど一度用い, また四則演算 (+, －, *, /) と
 * 括弧を使うことにより, 異なる正の整数を作ることができる. 例えば,
 *    8 = (4 * (1 + 3)) / 2
 *    14 = 4 * (3 + 1 / 2)
 *    19 = 4 * (2 + 3) - 1
 *    36 = 3 * 4 * (2 + 1)
 * 12 + 34 のように数字をつなげることは許されないことに注意しよう.
 * 集合 {1, 2, 3, 4} を使うと, 36 を最大とする 31 個の異なる数が得られる.
 * 最初の表現できない数に会うまで, 1 から 28 の各数を得ることができる.
 * 最長の連続した正の整数 1 から n の集合を得ることができる, 4 つの異なる数字
 * a < b < c < d を見つけよ. 答えを文字列 abcd として与えよ.
 ******************************************************************/
#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <assert.h>

template <class T>
T pop(std::stack<T>& stack)
{
	const T val = stack.top();
	stack.pop();
	return val;
}

double calc(std::stack<double>& value, char e, bool end_flag)
{
	if (end_flag == true)
		return 0;

	const double v2 = pop(value);
	const double v1 = pop(value);

	switch (e) {
	case '+': return v1 + v2;
	case '-': return v1 - v2;
	case '*': return v1 * v2;
	case '/':
			  if (v2 == 0) {
				  end_flag = true;
				  return 0;
			  }
			  return v1 / v2;
	default:  exit(1);
	}
}

double expr(const std::string& str)
{
	std::stack<double> value;
	std::stack<char> exp;

	bool end_flag = false;

	for (auto c : str) {
		switch (c) {
		case ' ': break;
		case '+': exp.push(c); break;
		case '-': exp.push(c); break;
		case '*': exp.push(c); break;
		case '/': exp.push(c); break;
		case '(': exp.push(c); break;
		case ')':
				  while (!exp.empty()) {
					  const char e = pop(exp);
					  if (e == '(')
						  break;
					  value.push(calc(value, e, end_flag));
				  }
				  while (!exp.empty() && (exp.top() == '*' || exp.top() == '/')) {
					  const char e = pop(exp);
					  value.push(calc(value, e, end_flag));
				  }
				  break;
		default:
				  value.push(c - '0');
				  if (!exp.empty() && (exp.top() == '*' || exp.top() == '/')) {
					  const char e = pop(exp);
					  value.push(calc(value, e, end_flag));
				  }
				  break;
		}
		if (end_flag == true)
			return 0;
	}
	while (!exp.empty()) {
		char e = pop(exp);
		if (e == '(')
			continue;
		value.push(calc(value, e, end_flag));
	}
	if (end_flag == true)
		return 0;
	return pop(value);
}

template <class T>
std::vector<std::string> combination(std::vector<T> target, int n, int k)
{
	std::vector<int> mask(k, 1); mask.resize(n, 0);
	std::sort(mask.begin(), mask.end());

	std::vector<std::string> vec;
	do {
		std::stringstream ss;
		for (size_t i = 0; i < mask.size(); ++i) {
			if (mask[i] == 1)
				ss << target[i];
		}
		vec.push_back(ss.str());
	} while (std::next_permutation(mask.begin(), mask.end()));

	std::sort(vec.begin(), vec.end());
	vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
	return vec;
}

std::vector<std::vector<int>> bracket()
{
	const std::vector<int> bracketCounterList = {0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2};
	std::vector<std::string> bCounter = combination(bracketCounterList, 12, 4);

	const std::vector<int> bracketBAFlagList = {0, 1, 0, 1, 0, 1, 0, 1};
	std::vector<std::string> bBeforAfterFlags = combination(bracketBAFlagList, 8, 4);

	std::vector<std::vector<int>> res;
	for (size_t x = 0; x < bCounter.size(); ++x) {
		for (size_t i = 0; i < bBeforAfterFlags.size(); ++i) {

			std::vector<int> result(bCounter[x].size(), 0);
			for (size_t j = 0; j < bBeforAfterFlags[i].size(); ++j)
				result[j] = (bBeforAfterFlags[i][j] == '0') ? (bCounter[x][j]-'0') * -1 : (bCounter[x][j]-'0');

			int sum = 0, flag = 0;
			for (size_t i = 0; i < result.size(); ++i) {
				sum += result[i];
				if (sum >= 1)
					flag = 1;
			}

			if (result[0] >= 1 || sum != 0 || flag != 0)
				continue;

			for (size_t i = 0; i < result.size()-1; ++i) {
				if (result[i] < 0 && 0 < result[i+1]) {
					const int diff = std::abs(result[i]) - std::abs(result[i+1]);
					if (diff == 0) {
						result[i] = -1;
						result[i+1] = 1;
					}
				}
			}
			res.push_back(result);

		}
	}
	std::sort(res.begin(), res.end());
	res.erase(std::unique(res.begin(), res.end()), res.end());

	return res;
}

int checkMax(const std::vector<int>& result)
{
	const auto itr = std::find_if_not(result.cbegin()+1, result.cend(), [](int v) { return v == 1; });
	return std::distance(result.cbegin(), itr);
}

int problem93()
{

	const std::vector<char> op_list= {'+', '-', '*', '/', '+', '-', '*', '/', '+', '-', '*', '/'};
	std::vector<std::string> ops = combination(op_list, 12, 3);

	const std::vector<int> num_list = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<std::string> nums = combination(num_list, 9, 4);

	std::vector<std::vector<int>> brackets = bracket();
	int max = 0;

	for (std::string v : nums) {
		std::vector<int> result(9*8*7*6+1, 0);
		do {
			for (size_t a = 0; a != ops.size(); ++a) {
				for (size_t b = 0; b != brackets.size(); ++b) {
					std::stringstream ss;
					for (int i = 0; i < 4; ++i) {
						if (brackets[b][i] < 0)
							ss << std::string(brackets[b][i]*-1, '(');
						ss << v[i];
						if (brackets[b][i] > 0)
							ss << std::string(brackets[b][i], ')');
						if (i != 3)
							ss << ops[a][i];
					}
					const double ans = expr(ss.str());
					if (ans > 0 && std::fabs(ans) - std::floor(std::fabs(ans)) < 0.00001)
						result[std::floor(ans)] = 1;
				}
			}
		} while (std::next_permutation(v.begin(), v.end()));
		max = std::max(checkMax(result), max);
	}
	return max;
}

int main(void)
{
	assert(expr("(4 * (1 + 3)) / 2") == 8);
	assert(expr("4 * (3 + 1 / 2)") == 14);
	assert(expr("4 * (2 + 3) - 1") == 19);
	assert(expr("3 * 4 * (2 + 1)") == 36);

	std::cout << problem93() << std::endl;
}
