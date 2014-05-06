//////////////////////////////////////////////////////////////////////
// Problem 31  
// 
// イギリスでは硬貨はポンド£とペンスpがあり，一般的に流通している硬貨は以下の8種類である.
// 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
// 以下の方法で£2を作ることが可能である．
// 1*£1 + 1*50p + 2*20p + 1*5p + 1*2p + 3*1p
// これらの硬貨を使って£2を作る方法は何通りあるか?
//////////////////////////////////////////////////////////////////////
#include <iostream>

int problem31(const int* coins, const int sum, const int c)
{
	int count = 0;
	if (!c)
		return 1;

	for (int n = sum; n >= 0; n -= coins[c])
		count += problem31(coins, n, c-1);
	return count;
}

int main()
{
	const int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
	int count = 0;

	count += problem31(coins, 200, 7);
	std::cout << count << std::endl;
}
