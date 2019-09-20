/*
	legal or not
	拓扑排序
*/
#include <bits/stdc++.h>
#define N 110
using namespace std;

vector<int> e[N];
queue<int> q;
int indeg[N];

int main(void) {
	int n, m, x, y;
	while(scanf("%d%d", &n, &m) != EOF) {
		if(n == 0) break;
		while(q.empty() == false) q.pop();
		for(int i = 0 ; i < n ; i ++) {
			e[i].clear();
			indeg[i] = 0;
		}
		while(m --){
			scanf("%d%d", &x, &y);
			indeg[y] ++;
			e[x].push_back(y);
		}

		int cnt = 0;

		for(int i = 0 ; i < n ; i ++) {
			if(indeg[i] == 0) {
				q.push(i);
			}
		}
		
		while(q.empty() == false) {
			int t = q.front();
			q.pop();
			cnt ++;
			for(int i = 0 ; i < e[t].size() ; i ++) {
				indeg[e[t][i]] --;
				if(indeg[e[t][i]] == 0) {
					q.push(e[t][i]);
				}
			}
		}

		if(cnt == n) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}