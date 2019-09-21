/*
	采药
	DP0-1背包问题
*/
#include <bits/stdc++.h>
using namespace std;
#define N 110

int dp[N][N];
int c[N], v[N];


int main(void) {
	int t, m;
	while(scanf("%d%d", &t, &m) != EOF) {
		for(int i = 1 ; i <= m ; i ++) {
			scanf("%d%d", &c[i], &v[i]);
		}
		for(int i = 0 ; i <= t ; i ++) {
			dp[0][i] = 0;
		}
		for(int i = 1 ; i <= m ; i ++) {
			for(int j = t ; j >= c[i] ; j --) {
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-c[i]] + v[i]);
			}
			for(int j = c[i] - 1 ; j >= 0 ; j --) {
				dp[i][j] = dp[i-1][j];
			}
		}
		printf("%d\n", dp[m][t]);
	}

	return 0;
}