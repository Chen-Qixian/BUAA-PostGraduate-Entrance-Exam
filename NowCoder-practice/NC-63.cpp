#include <bits/stdc++.h>
using namespace std;

int main(void) {
	set<int> s;
	int n, k;
	while(scanf("%d" , &n) != EOF) {
		int t;
		for(int i = 0 ; i < n ; i ++) {
			scanf("%d", &t);
			s.insert(t);
		}
		scanf("%d", &k);
		vector<int> v;
		for(auto it = s.begin() ; it != s.end() ; it ++) {
			v.push_back(*it);
		} 
		sort(v.begin(), v.end());
		printf("%d\n", v[k - 1]);
	}
	return 0;
}