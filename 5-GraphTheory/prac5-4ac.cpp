/*
	最短路径
	实际上是一道MST
*/
#include <bits/stdc++.h>
#define N 110
#define L 100000
using namespace std;

int tree[N];
int ans[N][N];

int findRoot(int x) {
	if(tree[x] == -1) return x;
	int tmp = findRoot(tree[x]);
	tree[x] = tmp;
	return tmp;
}

int main(void) {
	int n, m;
	int a, b, k, x, y;
	while(scanf("%d%d", &n, &m) != EOF) {
		k = 1;

		for(int i = 0 ; i < n ; i ++) {
			tree[i] = -1;
			for(int j = 0 ; j < n ; j ++) {
				ans[i][j] = -1;
			}
			ans[i][i] = 0;
		}

		while(m --) {
			scanf("%d%d", &a, &b);
			x = findRoot(a);
			y = findRoot(b);
			if(x != y) {
				for(int i = 0 ; i < n ; i ++) {
					if(x == findRoot(i)) {
						for(int j = 0 ; j < n ; j ++) {
							if(y == findRoot(j)) {
								ans[i][j] = ans[j][i] = (ans[i][a] + ans[b][j] + k) % L;
							}
						}
					}
				}
				tree[x] = y;
			}
			k = (k * 2) % L;
		}

		for(int i = 1 ; i < n ; i ++) {
			printf("%d\n", ans[0][i]);
		}


	}
	return 0;
}