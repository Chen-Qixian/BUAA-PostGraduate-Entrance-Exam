/*
	哈夫曼树
*/
#include <bits/stdc++.h>

using namespace std;

priority_queue <int, vector<int>, greater<int> > Q;

int main(void) {
	int n, x;
	int ans;
	int a, b;
	while(scanf("%d", &n) != EOF) {
		while(!Q.empty()) Q.pop();
		for(int i = 0 ; i < n ; i ++) {
			scanf("%d", &x);
			Q.push(x);
		}
		ans = 0;
		while(Q.size() > 1) {
			a = Q.top();
			Q.pop();
			b = Q.top();
			Q.pop();
			Q.push(a + b);
			ans += (a + b);
		}
		printf("%d\n", ans);
	}
	return 0;
}