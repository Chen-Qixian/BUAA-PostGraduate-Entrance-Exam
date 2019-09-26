/*
	2018-1-C
*/
#include <bits/stdc++.h>
using namespace std;
#define N 12

struct E {
	int x, y, t;
};

int k, m, t;
char maze[N][N];
bool mark[N][N];
int sx, sy, ex, ey;
queue<E> q;
bool flag;

int go[][2] = {
	1 , 0,
	-1, 0,
	0 , 1,
	0 ,-1
};

void bfs() {
	while(q.empty() == false) {
		E now = q.front();
		q.pop();
		for(int i = 0 ; i < 4 ; i ++) {
			int nx = now.x + go[i][0];
			int ny = now.y + go[i][1];
			int nt = now.t + 1;
			if(nx >= m || nx < 0 || ny >= m || ny < 0) continue;
			if(mark[nx][ny]) continue;
			if(maze[nx][ny] == '#') continue;
			if(nx == ex && ny == ey && nt <= t) {
				flag = true;
				break;
			}
			E tmp;
			tmp.x = nx;
			tmp.y = ny;
			tmp.t = nt;
			q.push(tmp);
			mark[nx][ny] = true;
		}
		if(flag) return;
	}
}

int main(void) {
	scanf("%d", &k);
	while(k --) {
		scanf("%d%d", &m, &t);
		for(int i = 0 ; i < m ; i ++) {
			scanf("%s", maze[i]);
		}
		for(int i = 0 ; i < m ; i ++) {
			for(int j = 0 ; j < m ; j ++) {
				if(maze[i][j] == 'S') {
					sx = i;
					sy = j;
				}
				else if(maze[i][j] == 'E') {
					ex = i;
					ey = j;
				}
				mark[i][j] = false;
			}
		}
		while(q.empty() == false) q.pop();
		E tmp;
		tmp.x = sx;
		tmp.y = sy;
		tmp.t = 0;
		q.push(tmp);
		mark[sx][sy] = true;
		flag = false;
		bfs();
		if(flag) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}