/*
	采药
	DP0-1背包问题
	化简版
*/
#include <bits/stdc++.h>
#define N 110
using namespace std;

int c[N], v[N];
int dp[N];

int main(void) {
	int t, m;
	while(scanf("%d%d", &t, &m) != EOF) {
		for(int i = 1 ; i <= m ; i ++) {
			scanf("%d%d", &c[i], &v[i]);
		}
		for(int i = 0 ; i <= t ; i ++) {
			dp[i] = 0;
		}
		for(int i = 1 ; i <= m ; i ++) {
			for(int j = t ; j >= c[i] ; j --) {
				dp[j] = max(dp[j], dp[j-c[i]] + v[i]); 
			}
		}
		printf("%d\n", dp[t]);
	}
	return 0; 
}