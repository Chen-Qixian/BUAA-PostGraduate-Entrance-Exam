/*
	Coincidence 
	LCS
*/
#include <bits/stdc++.h>
#define N 110
using namespace std;

char s1[N], s2[N];
int dp[N][N];


int main(void) {
	while(scanf("%s", s1) != EOF) {
		scanf("%s", s2);
		int l1 = strlen(s1), l2 = strlen(s2);
		for(int i = 0 ; i < l1 ; i ++) {
			dp[i][0] = 0;
		}
		for(int j = 0 ; j < l2 ; j ++) {
			dp[0][j] = 0;
		}
		for(int i = 1 ; i <= l1 ; i ++) {
			for(int j = 1 ; j <= l2 ; j ++) {
				if(s1[i-1] == s2[j-1]) {
					dp[i][j] = dp[i-1][j-1] + 1;
				}
				else {
					dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
				}
			}
		}
		printf("%d\n", dp[l1][l2]);
	}
	return 0;
}