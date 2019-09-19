/*
	畅通工程
	并查集
*/
#include <bits/stdc++.h>
#define SIZE 1010
using namespace std;

int tree[SIZE];

int findRoot(int x) {
	if(tree[x] == -1) return x;
	int tmp = findRoot(tree[x]);
	tree[x] = tmp;
	return tmp;
}

int main(void) {
	int n, m;
	int a, b;
	while(scanf("%d", &n) != EOF) {
		if(n == 0) break;
		scanf("%d",&m);
		for(int i = 1; i <= n ; i ++) {
			tree[i] = -1;
		}
		while(m --) {
			scanf("%d%d", &a, &b);
			a = findRoot(a);
			b = findRoot(b);
			if(a != b) {
				tree[a] = b;
			}
		}
		int ans = -1;
		for(int i = 1; i <= n ; i ++) {
			if(tree[i] == -1) {
				ans ++;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}