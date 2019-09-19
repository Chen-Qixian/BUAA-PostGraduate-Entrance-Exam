/*
	More is better
*/
#include <bits/stdc++.h>
#define SIZE 10000010
#define N 10000000
using namespace std;

int tree[SIZE];
int num[SIZE];

int findRoot(int x) {
	if(tree[x] == -1) return x;
	int tmp = findRoot(tree[x]);
	tree[x] = tmp;
	return tmp;
}

int main(void) {
	int n, a, b, ans;
	while(scanf("%d", &n) != EOF) {
		ans = 1;
		for(int i = 1; i <= N ; i ++) {
			tree[i] = -1;
			num[i] = 1;
		}
		while(n --) {
			scanf("%d%d", &a, &b);
			a = findRoot(a);
			b = findRoot(b);
			if(a != b) {
				tree[a] = b;
				num[b] += num[a];
			}
		}
		for(int i = 1; i <= N ; i ++) {
			if(tree[i] == -1)
				ans = max(ans, num[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}