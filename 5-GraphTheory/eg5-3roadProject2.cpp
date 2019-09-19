/*
	还是畅通工程
*/
#include <bits/stdc++.h>
#define N 10000
using namespace std;

int tree[N];

int findRoot(int x) {
	if(tree[x] == -1) return x;
	int tmp = findRoot(tree[x]);
	tree[x] = tmp;
	return tmp;
}

struct Edge {
	int a;
	int b;
	int weight;
	bool operator < (const Edge &a) const {
		return weight < a.weight;
	}
} e[N];

int main(void) {
	int n;
	while(scanf("%d", &n) != EOF) {
		if(n == 0) break;
		int bound = n * (n - 1) / 2;
		for(int i = 1 ; i <= bound ; i ++) {
			scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].weight);
		}
		sort(e + 1, e + 1 + bound);
		for(int i = 1; i <= n ; i ++) {
			tree[i] = -1;
		}
		int ans = 0;
		int a, b;
		for(int i = 1 ; i <= bound ; i ++) {
			a = findRoot(e[i].a);
			b = findRoot(e[i].b);
			if(a != b){
				tree[a] = b;
				ans += e[i].weight;
			}
		}
		int cnt = 0;
		for(int i = 1 ; i <= n ; i ++) {
			if(tree[i] == -1) {
				cnt ++;
				if(cnt > 1) break;
			}
		}
		if(cnt > 1){
			printf("?\n");
		}
		else{
			printf("%d\n", ans);
		}
	}
	return 0;
}