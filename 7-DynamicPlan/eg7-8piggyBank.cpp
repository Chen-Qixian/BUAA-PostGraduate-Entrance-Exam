/*
	Piggy Bank
	完全背包问题
	只需修改遍历方向，另外此题优化目标为寻求最小值
	不懂为何无法调适通过
*/
#include <bits/stdc++.h>
#define M 10001
#define N 501
#define INF 0x7fffffff
using namespace std;

int dp[M], c[N], v[N];

int min(int a, int b) {
	return (a < b) ? a : b;
}

int main(void) {
	int t, n, e, f;
	scanf("%d", &t);
	while(t --) {
		scanf("%d%d", &e , &f);
		f -= e;
		scanf("%d", &n);
		for(int i = 1 ; i <= n ; i ++) {
			scanf("%d%d", &v[i], &c[i]);
		}
		for(int i = 1 ; i <= f ; i ++) {
			dp[i] = INF;
		}
		// “恰好装满”问题：只有0时为0，其他均为无穷，由于找最小值，设置为正无穷！
		dp[0] = 0;
		for(int i = 1 ; i <= n ; i ++) {
			// 完全背包问题：顺序遍历！
			// printf("%d %d\n",c[i], v[i]);
			for(int j = c[i] ; j <= f ; j ++) {
				// printf("%d %d\n",j , j - c[i]);
				if(dp[j-c[i]] + v[i] < dp[j]) // 只有不为无穷时，才能转移得来！
					dp[j] = dp[j-c[i]] + v[i];
			}
		}
		if(dp[f] == INF) {
			printf("This is impossible.\n");
		}
		else {
			printf("The minimum amount of money in the piggy-bank is %n", dp[f]);
		}
	} 
	return 0;
}