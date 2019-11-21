#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int m, n;
	while(scanf("%d%d", &n, &m) != EOF) {
		if(n == 0 && m == 0) break;
		int ans = 0;
		for(int i = n - m + 1 ; i <= n ; i ++) {
			int t = i;
			while(t > 0 && t % 2 == 0) {
				ans ++;
				t /= 2;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}