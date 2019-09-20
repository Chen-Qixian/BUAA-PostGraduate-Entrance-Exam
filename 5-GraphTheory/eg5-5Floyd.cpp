/*
	最短路
*/
#include <stdio.h>
#define N 110 
using namespace std;

int ans[N][N];

int main(void) {
	int n, m;
	int a, b, c;
	while(scanf("%d%d", &n, &m) != EOF) {
		if(n == 0 && m == 0) break;
		for(int i = 1 ; i <= n ; i ++) {
			for(int j = 1 ; j <= n ; j ++) {
				ans[i][j] = -1;
			}
			ans[i][i] = 0;
		}
		while(m --) {
			scanf("%d%d%d", &a, &b, &c);
			ans[a][b] = c;
			ans[b][a] = c;
		}
		for(int k = 1 ; k <= n ; k ++) {
			for(int i = 1 ; i <= n ; i ++) {
				for(int j = 1 ; j <= n ; j ++) {
					if(ans[i][k] == -1 || ans[k][j] == -1) continue;
					if(ans[i][j] == -1 || ans[i][k] + ans[k][j] < ans[i][j]) {
						ans[i][j] = ans[i][k] + ans[k][j];
					}
				}
			}
		}
		printf("%d\n", ans[1][n]);
	}
	return 0;
}