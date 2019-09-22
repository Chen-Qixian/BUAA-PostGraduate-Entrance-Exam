/*
	中位数
*/
#include <bits/stdc++.h>
using namespace std;
#define N 10001

int main(void) {
	int n;
	int a[N];
	while(scanf("%d", &n) != EOF) {
		if(n == 0) break;
		for(int i = 0 ; i < n ; i ++) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		if(n % 2 == 1) {
			printf("%d\n", a[n / 2]);
		}
		else {
			printf("%d\n", (a[n / 2 - 1] + a[n / 2]) / 2);
		}
	}
	return 0;
}