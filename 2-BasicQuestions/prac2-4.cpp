/*
	今年的第几天？
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
	int cnt = 0;
	Date tmp;
	tmp.day = 1;
	tmp.month = 1;
	tmp.year = 0;
	while(tmp.year < 5001) {
		buf[tmp.year][tmp.month][tmp.day] = (cnt ++);
		tmp.nextDay();
	}

	int y,m,d;
	int num;
	while(scanf("%d%d%d", &y, &m, &d) != EOF) {
		num = buf[y][m][d] - buf[y][1][1] + 1;
		printf("%d\n", num);
	}
	return 0;
}

