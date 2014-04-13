#ifndef BIGNUM_HPP_INCLUDED
#define BIGNUM_HPP_INCLUDED

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

// 適当
class BigNum {
	std::vector<int> digits;
public:

	std::string to_string() const
	{
		std::stringstream ss;
		for (auto itr = digits.crbegin(); itr != digits.crend(); ++itr)
			ss << *itr << std::flush;
		return ss.str();
	}

	//BigNum() : digits(0, 1) { }

	BigNum(const BigNum& bn) : digits(bn.digits) { }

	BigNum(const std::string& str)
	{
		for (auto itr = str.crbegin(); itr != str.crend(); ++itr)
			this->digits.push_back(*itr - '0');
	}

	BigNum& operator+=(const BigNum& rhs)
   	{
		if (this->digits.size() < rhs.digits.size())
			this->digits.resize(rhs.digits.size(), 0);

		int carry = 0;
		std::transform(rhs.digits.begin(), rhs.digits.end(),
			   		   this->digits.begin(), this->digits.begin(),
			[&](const int a, const int b) {
				int tmp = a + b + carry;
				carry = tmp / 10;
				return tmp % 10;
			}
		);
		if (carry)
			this->digits.push_back(carry);
		return *this;
	}

	BigNum& operator*=(const BigNum& rhs)
   	{
		int count = 0;
		BigNum result("0");

		for (auto itr = this->digits.cbegin(); itr != this->digits.cend(); ++itr) {
			BigNum temp(std::string(count, '0'));
			int carry = 0;

			std::transform(rhs.digits.cbegin(), rhs.digits.cend(), std::back_inserter(temp.digits),
				[&](const int n) {
					const int tmp = (n * (*itr)) + carry;
					carry = tmp / 10;
					return tmp % 10;
				}
			);
			if (carry)
				temp.digits.push_back(carry);

			result += temp;
			++count;
		}
		this->digits = result.digits;
		return *this;
	}


	//BigNum& operator-=(const BigNum & rhs);
	//BigNum& operator*=(const BigNum & rhs);
	//BigNum& operator*=(int n);
	//BigNum& operator<<=(int n);

	BigNum operator+(const BigNum& rhs) const
	{
		BigNum result(*this);
		return result += rhs;
	};

	//BigNum operator-(const BigNum & rhs) const;
	//BigNum operator*(const BigNum & rhs) const;
	//BigNum operator*(int n) const;
	//BigNum operator<<(int n) const;

};

#endif /* BIGNUM_HPP_INCLUDED */
