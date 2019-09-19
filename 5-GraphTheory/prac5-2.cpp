/*
	Head of a Gang
*/
#include <bits/stdc++.h>
#define SIZE 1001
using namespace std;

int tree[SIZE];
int sum[SIZE];
map<string,int[2]> m;

int findRoot(int x) {
	if(tree[x] == -1) return x;
	int tmp = findRoot(tree[x]);
	tree[x] = tmp;
	return tmp;
}

int main(void) {
	int n, k, time, id;
	string a, b;
	int x, y;
	while(scanf("%d%d", &n, &k) != EOF) {
		for(int i = 0 ; i < SIZE ; i ++) {
			tree[i] = -1;
			sum[i] = 0;
		}
		m.clear();
		id = 0;
		while(n --) {
			scanf("%s%s%d", a, b, &time);
			if(m.find(a) == m.end()) {
				m[a][0] = id ++;
				m[a][1] = 0;
			}
			if(m.find(b) == m.end()) {
				m[b][0] = id ++;
				m[b][1] = 0;
			}
			m[a][1] += time;
			m[b][1] += time;
			x = findRoot(m[a][0]);
			y = findRoot(m[b][0]);
			if(x != y) {
				tree[x] = y;
				sum[y] += sum[x];
			}
			sum[y] += time;
		}
		int ans = 0;

		for(int i = 0 ; i < id ; i ++) {
			if(tree[x] == -1) {
				ans ++;
			}
		}

		printf("%d\n", ans);
	}
	return 0;
}