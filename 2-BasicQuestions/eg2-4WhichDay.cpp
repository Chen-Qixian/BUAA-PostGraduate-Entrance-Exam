/*
	Day of Week
*/
#include <bits/stdc++.h>
#define ISLEAP(x) (x % 100 != 0 && x % 4 == 0) || (x % 400 == 0) ? 1 : 0
using namespace std;

int buf[5001][13][32];

char month[13][20] = {
	"",
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};

char week[7][20] = {
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday"
};

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

int getMonth(char *s) {
	for(int i = 1 ; i <= 12 ; i ++) {
		if (strcmp(s, month[i]) == 0)
			return i;
	}
	return 0;
}

int main(void) {
	Date tmp;
	tmp.day = 1;
	tmp.month = 1;
	tmp.year = 0;
	int cnt = 0;
	while(tmp.year < 5001) {
		buf[tmp.year][tmp.month][tmp.day] = (cnt ++);
		tmp.nextDay();
	}

	int d,m,y;
	int distance;
	char ms[20];
	memset(ms, 0, sizeof(ms));
	while(scanf("%d%s%d", &d, ms, &y) != EOF){
		m = getMonth(ms);
		// printf("###%d %d %d\n", y, m ,d);
		distance = ((buf[y][m][d] - buf[2019][9][10]) % 7 + 9) % 7;
		printf("%s\n", week[distance]);

		memset(ms, 0, sizeof(ms));
	}
	return 0;
}