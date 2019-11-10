#include <bits/stdc++.h>
using namespace std;

long long num[50];

void fac(int n) {
	int ans = 1;
	for(int i = 1 ; i <= n ; i ++) {
		num[i] = ans;
		ans *= (i + 1);
	}
}

int main(void) {
	int n;
	long long y1, y2;
	fac(50);
	while(scanf("%d", &n) != EOF) {
		y1 = 0;
		y2 = 0;
		for(int i = 1 ; i <=n ; i ++) {
			if(i % 2 == 0) {
				y2 += num[i];
			}
			else {
				y1 += num[i];
			}
		}
		printf("%lld %lld\n", y1, y2);
	}
	return 0;
}