/*
	Freckles
*/
#include <bits/stdc++.h>
#define E 10000
#define N 110
using namespace std;

struct Edge {
	int a;
	int b;
	double weight;
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

double p[N][2];

double dist(double x[2], double y[2]) {
	double x1 = x[0],x2 = x[1],y1 = y[0], y2 = y[1];
	return sqrt((x1 - y1) * (x1 - y1) + (x2 - y2) * (x2 - y2));
}

int main(void) {
	int n;
	while(scanf("%d", &n) != EOF) {
		for(int i = 0 ; i < N ; i ++) {
			tree[i] = -1;
		}
		for(int i = 1 ; i <= n ; i ++) {
			scanf("%lf%lf", &p[i][0], &p[i][1]);
		}
		int cnt = 0;
		for(int i = 1 ; i <= n ; i ++) {
			for(int j = 1 ; j <= n ; j ++) {
				if(i == j) continue;
				e[cnt].a = i;
				e[cnt].b = j;
				e[cnt].weight = dist(p[i], p[j]);
				cnt ++;
			}
		}
		sort(e, e + cnt);
		double ans = 0.0;
		for(int i = 0 ; i < cnt ; i ++) {
			int x = findRoot(e[i].a);
			int y = findRoot(e[i].b);
			if(x != y) {
				tree[x] = y;
				ans += e[i].weight;
			}
		}
		printf("%.2lf", ans);
	}
	return 0;
} 