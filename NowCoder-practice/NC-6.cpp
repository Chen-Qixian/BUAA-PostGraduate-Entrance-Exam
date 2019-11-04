#include <bits/stdc++.h>
using namespace std;
#define N 1000010
int tree[N];

int findRoot(int x) {
	if(tree[x] == -1) return x;
	int tmp = findRoot(tree[x]);
	tree[x] = tmp;
	return tmp;
}

int main(void) {
	int a, b;
	set<int> s;
	for(int i = 0 ; i < N ; i ++) tree[i] = -1;
	while(scanf("%d%d", &a, &b) != EOF) {
		s.insert(a);
		s.insert(b);
		a = findRoot(a);
		b = findRoot(b);
		if(a != b) {
			tree[a] = b;
		}
	}
	int ans = 0;
	for(auto it = s.begin() ; it != s.end() ; it ++) {
		if(tree[*it] == -1) {
			ans ++;
		}
	}
	printf("%d\n", ans);
	return 0;
}