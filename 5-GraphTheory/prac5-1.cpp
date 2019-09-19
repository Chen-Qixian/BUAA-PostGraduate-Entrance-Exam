/*
	连通图
*/	
#include <bits/stdc++.h>
#define SIZE 10000
using namespace std;

int tree[SIZE];

int findRoot(int x) {
	if(tree[x] == -1) return x;
	int tmp = findRoot(tree[x]);
	tree[x] = tmp;
	return tmp;
}

int main(void) {
	int n, m, x, y;
	while(scanf("%d%d", &n, &m) != EOF) {
		for(int i = 1; i <= n ; i ++) {
			tree[i] = -1;
		}
		while(m --) {
			scanf("%d%d", &x, &y);
			x = findRoot(x);
			y = findRoot(y);
			if(x != y) {
				tree[x] = y;
			}
		}
		int num = 0;
		for(int i = 1 ; i <= n ; i ++) {
			if(tree[i] == -1){
				num ++;
				if(num > 1) break;
			}
		}
		if(num > 1){
			printf("NO\n");
		}
		else{
			printf("YES\n");
		}
	}

	return 0;
}