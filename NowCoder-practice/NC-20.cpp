#include <bits/stdc++.h>
using namespace std;

int day[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(void) {
	int y, m, d;
	int n;
	while(scanf("%d", &n) != EOF) {
		while(n --) {
			scanf("%d%d%d", &y, &m, &d);
			d ++;
			if(d > day[m]) {
				d = 1;
				m ++;
				if(m > 12) {
					m = 1;
					y ++;
				}
			}
			printf("%4d-%02d-%02d\n", y, m, d);
		}
	}
	return 0;
}