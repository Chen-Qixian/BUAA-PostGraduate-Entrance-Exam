#include <bits/stdc++.h>
using namespace std;
#define isLeap(x) ((x % 100 != 0 && x % 4 == 0) || (x % 400 == 0)) ? 1 : 0

int day[14][2] = {
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

struct D {
	int y;
	int m;
	int d;

	void next() {
		d ++;
		if(d > day[m][isLeap(y)]) {
			d = 1;
			m ++;
			if(m > 12) {
				m = 1;
				y ++;
			}
		}
	}
};

int buf[5001][13][32];

void init() {
	int cnt = 0;
	D t;
	t.y = 0;
	t.m = 1;
	t.d = 1;
	while(t.y < 5000) {
		buf[t.y][t.m][t.d] = cnt ++;
		t.next();
	}
}

int main(void) {
	int m;
	init();
	int year,month,day;
	while(scanf("%d", &m) != EOF) {
		while(m --) {
			scanf("%d%d%d", &year, &month, &day);
			printf("%d\n", buf[year][month][day] - buf[year][1][1] + 1);
		}
	}
	return 0;
}

