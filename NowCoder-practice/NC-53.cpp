#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

// bool cmp(PII &a, PII &b) {
// 	return a.second > b.second;
// }

int main(void) {
	int n, coe, pow;
	map<int, int> m;
	// vector<PII> v;
	while(scanf("%d", &n) != EOF) {
		while(n --) {
			scanf("%d%d", &coe, &pow);
			m[pow] = coe;
		}
		scanf("%d", &n);
		while(n --) {
			scanf("%d%d", &coe, &pow);
			if(m.find(pow) == m.end()) {
				m[pow] = coe;
			}
			else {
				m[pow] += coe;
			}
		}
		// for(auto it = m.begin() ; it != m.end() ; it ++) {
		// 	v.push_back(*it);
		// }

		// sort(v.begin(), v.end(), cmp);

		for(auto it = m.rbegin() ; it != m.rend() ; it ++) {
			if(it-> second != 0)
				printf("%d %d ", it->second, it->first);
		}
		printf("\n");
	}
	return 0;
}