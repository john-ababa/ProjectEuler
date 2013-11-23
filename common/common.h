#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <cmath>

namespace Euler {

template <class T>
bool isPrime(T n)
{
	if ((n != 2 && n % 2 == 0) || n <= 1)
		return false;
	const T limit = std::sqrt(n);
	for (T i = 3; i <= limit; i += 2)
		if (n % i == 0)
			return false;
	return true;
}

}

#endif /* COMMON_H_INCLUDED */
