/*
	还是畅通工程
*/
#include <bits/stdc++.h>
#define E 10000
#define N 110
using namespace std;

struct Edge {
	int a;
	int b;
	int weight;

	bool operator < (const Edge &a) const {
		return weight < a.weight;
	}
} e[E];

int tree[N];

int findRoot(int x) {
	if(tree[x] == -1) return x;
	int tmp = findRoot(tree[x]);
	tree[x] = tmp;
	return tmp;
}

int main(void) {
	int n, flag;
	while(scanf("%d", &n) != EOF) {
		if(n == 0) break;
		int bound = n * (n - 1) / 2;
		int a, b;
		for(int i = 1 ; i <= n ; i ++) {
			tree[i] = -1;
		}
		for(int i = 1 ; i <= bound ; i ++) {
			scanf("%d%d%d%d", &e[i].a, &e[i].b, &e[i].weight, &flag);
			if(flag == 1) {
				a = findRoot(e[i].a);
				b = findRoot(e[i].b);
				if(a != b) {
					tree[a] = b;
				}
			}
		}
		sort(e + 1, e + 1 + bound);
		int ans = 0;
		for(int i = 1 ; i <= bound ; i ++) {
			a = findRoot(e[i].a);
			b = findRoot(e[i].b);
			if(a != b) {
				tree[a] = b;
				ans += e[i].weight;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}