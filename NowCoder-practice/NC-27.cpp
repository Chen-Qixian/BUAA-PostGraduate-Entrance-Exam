#include <bits/stdc++.h>
using namespace std;

long long fac(int n) {
	if(n == 1) return 1;
	return fac(n - 1) * n;
}

int main(void) {
	int n, m;
	long long ans;
	while(scanf("%d", &m) != EOF) {
		while(m --) {
			scanf("%d", &n);
			ans = fac(n);
			printf("%lld\n", ans);
		}
	}
	return 0;
}