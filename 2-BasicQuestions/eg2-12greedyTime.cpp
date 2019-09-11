/*
	今年暑假不AC
	注意总结贪心算法技巧
*/
#include <bits/stdc++.h>

using namespace std;

struct E{
	int s;
	int e;
	bool operator< (const E &a) const{
		return e < a.e;
	}
} t[110];

int main(void) {
	int n;
	int s, e;
	while(scanf("%d", &n) != EOF) {
		if(n == 0) break;
		for(int i = 0 ; i < n ; i ++) {
			scanf("%d%d", &t[i].s, &t[i].e);
		}
		sort(t, t + n);
		int ans = 0;
		int cur = 0;
		for(int i = 0 ; i < n ; i ++) {
			if(t[i].s >= cur) {
				ans ++;
				cur = t[i].e;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
