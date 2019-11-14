#include <bits/stdc++.h>
using namespace std;
#define N 50
int n;
vector<vector<int> > v;

void init() {
	vector<int> t = {1, 1};
	v.push_back(t);
	for(int i = 1 ; i <= N - 2 ; i ++) {
		vector<int> t = {1};
		int len = v[i-1].size();
		for(int j = 0 ; j < len - 1 ; j ++) {
			t.push_back(v[i-1][j] + v[i-1][j+1]);
		}
		t.push_back(1);
		v.push_back(t);
	}
}

int main(void) {
	init();
	while(scanf("%d", &n) != EOF) {
		for(int i = 0 ; i <= n - 2 ; i ++) {
			int len = v[i].size();
			for(int j = 0 ; j < len ; j ++) {
				printf("%d ", v[i][j]);
			}
			printf("\n");
		}
 	}
	return 0;
}