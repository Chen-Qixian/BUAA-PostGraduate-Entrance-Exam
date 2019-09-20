#include <stdio.h>
#include <vector>
#define N 110
using namespace std;

struct E {
	int t;
	int c;
};

vector<E> e[N];
int dis[N];
bool mark[N];

int main(void) {
	int n, m;
	int a, b, c;
	while(scanf("%d%d", &n, &m) != EOF) {
		if(n == 0 && m == 0) break;
		for(int i = 1 ; i <= n ; i ++) {
			e[i].clear();
			dis[i] = -1;
			mark[i] = false;
		}
		while(m --) {
			scanf("%d%d%d", &a, &b, &c);
			E tmp;
			tmp.c = c;
			tmp.t = a;
			e[b].push_back(tmp);
			tmp.t = b;
			e[a].push_back(tmp);
		}
		int newP = 1;
		dis[newP] = 0;
		mark[newP] = true;

		for(int i = 1 ; i < n ; i ++) {
			for(int j = 0 ; j < e[newP].size() ; j ++) {
				int t = e[newP][j].t;
				int c = e[newP][j].c;
				if(mark[t]) continue;
				if(dis[t] == -1 || dis[t] > dis[newP] + c) {
					dis[t] = dis[newP] + c;
				}
			}
			int min = INT_MAX;
			for(int j = 1 ; j <= n ; j ++) {
				if(mark[j]) continue;
				if(dis[j] == -1) continue;
				if(dis[j] < min) {
					min = dis[j];
					newP = j;
				}
			}
			mark[newP] = true;
		}

		printf("%d\n", dis[n]);
	}
	return 0;
}