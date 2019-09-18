/*
	二分求幂
*/
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int a, b;
	while(scanf("%d%d", &a, &b) != EOF) {
		if(a == 0 && b == 0) break;
		int ans = 1;
		while(b) {
			if(b % 2 == 1) {
				ans *= a;
			}
			a *= a;
			a %= 1000;
			ans %= 1000;
			b /= 2;
		}
		printf("%d\n", ans);
	}
	return 0;
}