/*
	日期差值
*/
#include <bits/stdc++.h>
#define ISLEAP(x) (x % 100 != 0 && x % 4 == 0) || (x % 400 == 0) ? 1 : 0
using namespace std;

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

int buf[5001][13][32];

int main(void) {
	int cnt = 0;
	Date tmp;
	tmp.day = 1;
	tmp.month = 1;
	tmp.year = 0;
	while(tmp.year < 5001) {
		buf[tmp.year][tmp.month][tmp.day] = cnt;
		cnt ++;
		tmp.nextDay();
	}

	int y1, m1, d1, y2, m2, d2;
	int ans;
	while(scanf("%4d%2d%2d", &y1, &m1, &d1) != EOF) {
		scanf("%4d%2d%2d", &y2, &m2, &d2);
		ans = abs(buf[y1][m1][d1] - buf[y2][m2][d2]) + 1;
		printf("%d\n", ans); 
	}
	return 0;
}
























