/*
	FatMouse' Trade
*/
#include <bits/stdc++.h>

using namespace std;

struct E {
	double j;
	double f;
	double d;
	bool operator< (const E &a) const{
		return d > a.d;
	}
} r[1100];

int main(void) {
	int m, n;
	while(scanf("%d%d", &m, &n) != EOF) {
		if(m == -1 && n == -1) break;
		for(int i = 0 ; i < n ; i ++) {
			scanf("%lf%lf", &r[i].j, &r[i].f);
			r[i].d = r[i].j / r[i].f;
		}
		sort(r, r + n);
		double ans = 0.0;
		int k = 0;
		while(m >= r[k].f && k < n) {
			ans += r[k].j;
			m -= r[k].f;
			k ++;
		}
		ans += (m / r[k].f) * r[k].j;
		printf("%.3lf\n", ans);
	}	
	return 0;
}