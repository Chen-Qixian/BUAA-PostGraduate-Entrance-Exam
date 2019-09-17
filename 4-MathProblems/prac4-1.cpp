/*
	还是A+B
*/
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int a, b, k;
	while(scanf("%d%d%d", &a, &b , &k) != EOF) {
		if(a == 0 && b == 0) break;
		k = pow(10, k);
		if(a % k == b % k) {
			printf("-1\n");
		}
		else {
			printf("%d\n", a + b);
		}
	}
	return 0;
}