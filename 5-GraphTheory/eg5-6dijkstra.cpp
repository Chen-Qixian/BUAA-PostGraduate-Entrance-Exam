/*
	最短路径问题
	dijkstra
*/
#include <bits/stdc++.h>
#define N 1010
using namespace std;

struct E {
	int next;
	int c;
	int cost;
};

vector<E> e[N];
int dis[N];
int cost[N];
bool mark[N];


int main(void) {
	int n, m, s, t;
	int a, b, c, co;
	while(scanf("%d%d", &n, &m) != EOF) {
		if(n == 0 && m == 0) break;
		for(int i = 1 ; i <= n ; i ++) e[i].clear();
		while(m --) {
			scanf("%d%d%d%d", &a, &b, &c, &co);
			E tmp;
			tmp.c = c;
			tmp.cost = co;
			tmp.next = a;
			e[b].push_back(tmp);
			tmp.next = b;
			e[a].push_back(tmp);
		}

		scanf("%d%d", &s, &t);

		for(int i = 1 ; i <= n ; i ++) {
			dis[i] = -1;
			mark[i] = false;
		}

		dis[s] = 0;
		mark[s] = true;

		int newP = s;

		for(int i = 1 ; i < n ; i ++) {
			for(int j = 0 ; j < e[newP].size() ; j ++) {
				int next = e[newP][j].next;
				int c = e[newP][j].c;
				int co = e[newP][j].cost;
				if(mark[next] == true) continue;
				if(dis[next] == -1 || dis[next] > dis[newP] + c || dis[next] == dis[newP] + c && cost[next] > cost[newP] + co) {
					dis[next] = dis[newP] + c;
					cost[next] = cost[newP] + co;
				}
			}
			int min = INT_MAX;
			for(int j = 1 ; j <= n ; j ++) {
				if(mark[j] == true) continue;
				if(dis[j] == -1) continue;
				if(dis[j] < min) {
					min = dis[j];
					newP = j;
				}
			}
			mark[newP] = true;
		}

		printf("%d %d\n", dis[t], cost[t]);
	}
	return 0;
}














