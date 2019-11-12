#include <bits/stdc++.h>
using namespace std;

int main(void) {
	vector<int> v;
	int n, x;
	while(scanf("%d", &n) != EOF) {
		v.clear();
		for(int i = 0 ; i < n ; i ++) {
			scanf("%d", &x);
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		for(auto it = v.begin(); it != v.end() ; it ++) {
			printf("%d ", *it);
		}
		printf("\n");
	}
	return 0;
}