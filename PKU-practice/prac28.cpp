/*
	点菜问题
*/
#include <bits/stdc++.h>
using namespace std;
#define N 1010
#define M 110

int p[M], v[M];
int dp[N];

int main(void) {
	int c, n;
	while(scanf("%d%d", &c, &n) != EOF) {
		for(int i = 0 ; i < n ; i ++) {
			scanf("%d%d", &p[i], &v[i]);
		}
		for(int i = 0 ; i <= c ; i ++) {
			dp[i] = 0;
		}
		for(int i = 0 ; i < n ; i ++) {
			for(int j = c ; j >= p[i]; j --) {
				dp[j] = max(dp[j], dp[j - p[i]] + v[i]);
			}
		}
		printf("%d\n", dp[c]);
	}
	return 0;
}