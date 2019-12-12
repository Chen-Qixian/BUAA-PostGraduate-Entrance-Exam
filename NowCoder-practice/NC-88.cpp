#include <bits/stdc++.h>
using namespace std;

int n, dp[1000002], a[21];

int main(void) {
	for(int i = 1 ; i <= 20 ; i ++) {
		a[i] = (1 << (i - 1));
	}
	dp[0] = 1;

	while(scanf("%d", &n) != EOF) {
		memset(dp + 1, 0 , sizeof(dp));
		for(int i = 1 ; i <= 20 ; i ++) {
			for(int j = a[i] ; j <= n ; j ++) {
				dp[j] += dp[j - a[i]];
				dp[j] %= 1000000000;
			}
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}