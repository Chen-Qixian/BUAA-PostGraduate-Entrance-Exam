/*
	最大上升子序列和
*/
#include <bits/stdc++.h>
using namespace std;
#define N 1010

int dp[N], a[N];

int main(void) {
	int n;
	while(scanf("%d", &n) != EOF) {
		for(int i = 0 ; i < n ; i ++) {
			scanf("%d", &a[i]);
			dp[i] = a[i];
		}
		for(int i = 0 ; i < n ; i ++) {
			int tmax = a[i];
			for(int j = 0 ; j < i ; j ++) {
				if(a[j] < a[i]) {
					tmax = max(tmax, dp[j] + a[i]);
				}
			}
			dp[i] = tmax;
		}
		int ans = dp[0];
		for(int i = 0 ; i < n ; i ++) {
			ans = max(ans, dp[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}