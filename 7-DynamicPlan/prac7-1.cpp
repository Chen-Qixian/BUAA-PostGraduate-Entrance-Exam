/*
	合唱队形
*/
#include <bits/stdc++.h>
#define N 110
using namespace std;

int t[N];
int dp[N];
int dp1[N];

int main(void) {
	int n;
	while(scanf("%d", &n) != EOF) {
		for(int i = 0 ; i < n ; i ++) {
			scanf("%d", &t[i]);
			dp[i] = dp1[i] = 0;
		}
		dp[0] = 1;
		dp1[n - 1] = 1;
		for(int i = 0 ; i < n ; i ++) {
			int tmax = 1;
			for(int j = 0 ; j < i ; j ++) {
				if(t[j] < t[i]) {
					tmax = max(tmax, dp[j] + 1);
				}
			}
			dp[i] = tmax;
		}
		for(int i = n - 1 ; i >= 0 ; i --) {
			int tmax = 1;
			for(int j = n - 1 ; j > i ; j --) {
				if(t[j] < t[i]) {
					tmax = max(tmax, dp1[j] + 1);
				}
			}
			dp1[i] = tmax;
		}
		int ans = 0;
		for(int i = 0 ; i < n ; i ++) {
			ans = max(ans, dp[i] + dp1[i] - 1);
		}
		printf("%d\n", n - ans);
	}

	return 0;
}
