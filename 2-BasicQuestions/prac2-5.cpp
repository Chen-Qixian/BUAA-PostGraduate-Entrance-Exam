/*
	打印日期
*/
#include <bits/stdc++.h>
#define ISLEAP(x) (x % 100 != 0 && x % 4 == 0) || (x % 400 == 0) ? 1 : 0
using namespace std;

int buf[5001][13][32];

int dayOfMonth[13][2] = {
	0, 0,
	31, 31,
	28, 29,
	31, 31,
	30, 30,
	31, 31,
	30, 30,
	31, 31, 
	31, 31,
	30, 30,
	31, 31,
	30, 30,
	31, 31 
};

struct Date {
	int day;
	int month;
	int year;
	void nextDay() {
		day ++;
		if(day > dayOfMonth[month][ISLEAP(year)]) {
			day = 1;
			month ++;
			if(month > 12) {
				month = 1;
				year ++;
			}
		}
	}
};

int main(void) {

	int y, n;
	while(scanf("%d%d", &y, &n) != EOF) {
		int s = n - 1;
		Date tmp;
		tmp.year = y;
		tmp.month = 1;
		tmp.day = 1;

		while(s > 0) {
			tmp.nextDay();
			s --;
		}

		printf("%04d-%02d-%02d\n", tmp.year, tmp.month, tmp.day);
	}
	return 0;
}

