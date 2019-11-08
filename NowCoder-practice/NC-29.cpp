#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int m, n;
	int a[300];
	int sum = 0;
	for(int i = 0 ; i <= 200 ; i ++) {
		sum += i;
		a[i] = sum;
	}
	while(scanf("%d", &m) != EOF) {
		while(m --) {
			int ans;
			scanf("%d", &n);
			if(n > 0) {
				ans = a[2 * n] - a[n - 1];
			}
			else if(n == 0) {
				ans = 0;
			}
			else {
				ans = -(a[-2 * n] - a[-1 - n]);
			}
			printf("%d\n", ans);
		}
	}

	return 0;
}