/*
	胜利大逃亡
	BFS
*/
#include <stdio.h>
#include <queue>
#define N 50 
using namespace std;

struct E {
	int x, y, z;
	int t;
};

queue<E> q;
int cube[N][N][N];
bool mark[N][N][N];
int go[][3] = {
	1, 0, 0,
	-1,0, 0,
	0, 1, 0,
	0,-1, 0,
	0, 0, 1,
	0, 0,-1
};

int bfs(int a, int b, int c) {
	while(q.empty() == false) {
		E tmp = q.front();
		q.pop();
		for(int i = 0 ; i < 6 ; i ++) {
			int nx = tmp.x + go[i][0];
			int ny = tmp.y + go[i][1];
			int nz = tmp.z + go[i][2];
			int nt = tmp.t + 1;
			// 注意！边界判断必须写在最前面！
			if(nx < 0 || nx >= a || ny < 0 || ny >= b || nz < 0 || nz >= c) continue;
			if(mark[nx][ny][nz]) continue;
			if(cube[nx][ny][nz] == 1) continue;		
			mark[nx][ny][nz] = true;
			if(nx == a - 1 && ny == b - 1 && nz == c - 1){
				return nt;
			}
			E tmp;
			tmp.x = nx;
			tmp.y = ny;
			tmp.z = nz;
			tmp.t = nt;
			q.push(tmp);
		}
	}
	return -1;
}


int main(void) {
	int k;
	int a, b, c, t;
	while(scanf("%d", &k) != EOF) {
		while(k --) {
			scanf("%d%d%d%d", &a, &b, &c, &t);
			for(int i = 0 ; i < a ; i ++) {
				for(int j = 0 ; j < b; j ++) {
					for(int k = 0 ; k < c ; k ++) {
						scanf("%d", &cube[i][j][k]);
						mark[i][j][k] = false;
					}
				}
			}
			// 在BFS前需要先将第一个状态存入队列，mark数组为合理剪枝策略
			while(q.empty() == false) q.pop();
			E tmp;
			tmp.x = tmp.y = tmp.z = tmp.t = 0;
			mark[0][0][0] = true;
			q.push(tmp);
			int ans = bfs(a, b, c);
			if(ans != -1 && ans <= t) {
				printf("%d\n", ans);
			}
			else {
				printf("-1\n");
			}
		}
	}

	return 0;
}