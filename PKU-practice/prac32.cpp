/*
	Zexal的电影院
*/
#include <bits/stdc++.h>
using namespace std;
#define N 10010

struct M {
	int l;
	int v;
	int w;

	bool operator < (const M &a) const {
		return w > a.w;
	}
} m[N];


int main(void) {
	int n, k;
	while(scanf("%d%d", &n, &k) != EOF) {
		for(int i = 0 ; i < n ; i ++) {
			scanf("%d%d", &m[i].l, &m[i].v);
			m[i].w = m[i].l * m[i].v;
		}
		sort(m, m + n);
		int _min = m[0].v, ans = 0;
		for(int i = 0 ; i < k ; i ++) {
			ans += m[i].l;
			_min = min(_min, m[i].v);
		}
		ans *= _min;
		printf("%d\n", ans);
	}
	return 0;
}