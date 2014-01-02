//////////////////////////////////////////////////////////////////////
// Problem 19  
// 
// 次の情報が与えられている。
// - 1900年1月1日は月曜日である。
// - 9月、4月、6月、11月は30日まであり、2月を除く他の月は31日まである。
// - 2月は28日まであるが、うるう年のときは29日である。
// - うるう年は西暦が4で割り切れる年に起こる。
//
// しかし、西暦が400で割り切れず100で割り切れる年はうるう年でない。
// 20世紀（1901年1月1日から2000年12月31日）で月の初めが日曜日になるのは何回あるか。
//////////////////////////////////////////////////////////////////////
#include <iostream>

int isLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 1;
	else
		return 0;
}

int problem19()
{
	//                1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12
	int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int week_day = 1; // sunday(0), monday(1), ... saturday(6)

	int count = 0;
	for (int year = 1900; year <= 2000; ++year) {
		for (int month = 1; month <= 12; ++month) {
			week_day += days[month];
			if (month == 2)
				 week_day += isLeapYear(year);
			week_day %= 7;

			if (week_day == 0 && 1901 <= year)
				count++;
		}
	}
	return count;
}

int main(void)
{
	std::cout << problem19() << std::endl;
}
