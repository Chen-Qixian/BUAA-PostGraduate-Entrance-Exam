
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int m,n,x;
	int a[20];
	while(scanf("%d", &m) != EOF) {
		while(m --) {
			scanf("%d", &n);
			for(int i = 0 ; i <= n ; i ++) {
				scanf("%d", &a[i]);
			}
			scanf("%d", &x);
			long long ans = 0;
			for(int i = 0 ; i <= n ; i ++) {
				ans += a[i] * pow(x, i);
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}