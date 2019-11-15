#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n, tmp;
	vector<vector<int> > v;
	while(scanf("%d", &n) != EOF) {
		v.clear();
		for(int i = 0 ; i < n ; i ++) {
			vector<int> t;
			for(int j = 0 ; j < n ; j ++) {
				scanf("%d", &tmp);
				t.push_back(tmp);
			}
			v.push_back(t);
		}
		for(int i = 0 ; i < n ; i ++) {
			int _max = v[0][i];
			int idx = 0;
			for(int j = 0, len = v.size() ; j < len ; j ++) {
				if(v[j][i] >_max) {
					_max = v[j][i];
					idx = j;
				}
			}
			for(int k = 0 ; k < n ; k ++) {
				printf("%d ", v[idx][k]);
			}
			printf("\n");
			v.erase(v.begin() + idx, v.begin() + idx + 1);
		}
	}

	return 0;
}