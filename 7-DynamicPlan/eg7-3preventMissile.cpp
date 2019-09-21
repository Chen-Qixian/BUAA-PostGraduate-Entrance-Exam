/*
	拦截导弹
	LIS
*/
#include <bits/stdc++.h>
#define N 50
using namespace std;

int main(void) {
	int ans, k;
	int a[N];
	while(scanf("%d", &k) != EOF) {
		for(int i = 1 ; i <= k ; i ++) {
			scanf("%d", &a[i]);
		}
		int dp[N];
		for(int i = 0 ; i <= k ; i ++) {
			dp[i] = 0;
		}
		dp[1] = 1;
		for(int i = 2 ; i <= k ; i ++) {
			int tmax = 1;
			for(int j = 1 ; j < i ; j ++) {
				if(a[j] >= a[i]) {
					// 易错点1:需要寻找前i个里的最大值！不断更新
					tmax = max(tmax, dp[j] + 1);
				}
			}
			dp[i] = tmax;
		}
		//易错点2:需要寻找所有dp中的最大值
		ans = dp[1];
		for(int i = 1 ; i <= k ; i ++) {
			ans = max(ans, dp[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}