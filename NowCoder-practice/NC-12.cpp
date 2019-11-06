#include <bits/stdc++.h>
using namespace std;
#define isLeap(x) (x % 100 != 0 && x % 4 == 0) || (x % 400 == 0) ? 1 : 0 

int day[15][2] = {
	0 ,  0,
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
	int y;
	int m;
	int d;
	void nextDay() {
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

int main(void) {
	int m, dur;
	while(scanf("%d", & m) != EOF) {
		while(m --) {
			Date tmp;
			scanf("%d%d%d%d", &tmp.y, &tmp.m, &tmp.d, &dur);
			while(dur --) {
				tmp.nextDay();
			}
			printf("%4d-%02d-%02d\n", tmp.y, tmp.m, tmp.d);
		}
	}
}






