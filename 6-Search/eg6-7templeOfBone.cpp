/*
	Temple of the bone
	DFS
*/
#include <bits/stdc++.h>
#define N 10
using namespace std;

char maze[N][N];
int sx, sy, dx, dy;
int n, m, t;
int flag;

int go[][2] = {
	1 , 0,
	-1, 0,
	0 , 1,
	0 ,-1
};

void dfs(int x, int y, int time) {
	for(int i = 0 ; i < 4 ; i ++) {
		int nx = x + go[i][0];
		int ny = y + go[i][1];
		int nt = time + 1;
		if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if(maze[nx][ny] == 'X') continue;
		if(nx == dx && ny == dy && nt == t) {
			flag = true;
			return;
		}
		maze[nx][ny] = 'X';
		dfs(nx, ny, nt);
		// 注意DFS每层递归后回到原来状态
		maze[nx][ny] = '.';
	}

	return;
}

int main(void) {
	while(scanf("%d%d%d", &n, &m, &t) != EOF) {
		if(n == 0 && m == 0 && t == 0) break;
		for(int i = 0 ; i < n ; i ++) {
			scanf("%s", maze[i]);
		}
		for(int i = 0 ; i < n ; i ++) {
			for(int j = 0 ; j < m ; j ++) {
				if(maze[i][j] == 'S') {
					sx = i;
					sy = j;
				}
				else if(maze[i][j] == 'D') {
					dx = i;
					dy = j;
				}
			}
		}
		if(((sx + sy) % 2 + t % 2) % 2 != (dx + dy) % 2) {
			printf("NO\n");
			continue;
		}
		flag = false;
		mazd[sx][sy] = 'X';
		dfs(sx, sy, 0);
		if(flag) {
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}