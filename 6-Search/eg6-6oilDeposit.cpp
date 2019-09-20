/*
	Deposit
*/
#include <bits/stdc++.h>
#define N 110
using namespace std;

char g[N][N];
bool mark[N][N];
int m, n;

int go[][2] = {
	1, 0,
	-1,0,
	0, 1,
	0,-1,
	1, 1,
	1,-1,
	-1,1,
	-1,-1
};

void dfs(int x, int y) {
	for(int i = 0 ; i < 8 ; i ++) {
		int nx = x + go[i][0];
		int ny = y + go[i][1];
		if(nx >= m || nx < 0 || ny >= n || ny < 0) continue;
		if(mark[nx][ny]) continue;
		if(g[nx][ny] == '*') continue;
		mark[nx][ny] = true;
		dfs(nx, ny);
	}
	return;
}

int main(void) {
	while(scanf("%d%d", &m, &n) != EOF) {
		if(m == 0) break;
		for(int i = 0 ; i < m ; i ++) {
			for(int j = 0 ; j < n ; j ++) {
				mark[i][j] = false;
			}
		}
		for(int i = 0 ; i < m ; i ++) {
			scanf("%s", g[i]);
		}
		int ans = 0;
		for(int i = 0 ; i < m ; i ++) {
			for(int j = 0 ; j < n ; j ++) {
				if(mark[i][j]) continue;
				if(g[i][j] == '*') continue;
				dfs(i, j);
				ans ++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}