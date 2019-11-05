/*
	前序/后序问题：拓扑排序
	priority_queue默认大顶堆， 三个参数<Type, Container, Functional>分别表示数据类型，保存数据的容器，元素比较方式
*/
#include <bits/stdc++.h>
using namespace std;
#define N 100000

int indeg[N];
vector<int> e[N];
priority_queue<int, vector<int>, greater<int> > q;

int main(void) {
	int n;
	while(scanf("%d", &n) != EOF) {
		char task[1000];	
		for(int i = 0 ; i < n ; i ++) {
			e[i].clear();
			indeg[i] = 0;
		}
		while(!q.empty()) q.pop();
		for(int loop = 0 ; loop < n ; loop ++) {	
			scanf("%s", task);
			int t = (task[4] - '0');
			for(int i = 10 , len = strlen(task); i < len ; i += 6) {
				if(task[i] > '9' || task[i] < '0') break;
				int next = task[i] - '0';
				e[t].push_back(next);
				indeg[next] ++;
			}
		}
		for(int i = 0 ; i < n ; i ++) {
			if(indeg[i] == 0) {
				q.push(i);
			}
		}
		while(q.empty() == false) {
			int t = q.top();
			q.pop();
			printf("Task%d ", t);
			for(int i = 0 ,len = e[t].size(); i < len ; i ++) {
				indeg[e[t][i]] --;
				if(indeg[e[t][i]] == 0) {
					q.push(e[t][i]);
				}
			}
		}
	}
	return 0;
}