#include <bits/stdc++.h>
using namespace std;

int main(void) {
	set<int> s;
	for(int i = 0 ; i <= 5 ; i ++) {
		for(int j = 0 ; j <= 4 ; j ++) {
			for(int k = 0 ; k <= 6 ; k ++) {
				s.insert(i * 8 + j * 10 + k * 18);
			}
		}
	}
	int ans = s.size() - 1;
	printf("%d", ans);
	return 0;
}