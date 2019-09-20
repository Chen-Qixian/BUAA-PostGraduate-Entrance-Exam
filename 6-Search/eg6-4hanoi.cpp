/*
	汉诺塔问题
*/
#include <bits/stdc++.h>
using namespace std;

long long hanoi(int n) {
	if(n == 1) return 2;
	return 3 * hanoi(n - 1) + 2;
}

int main(void) {
	int n;
	while(scanf("%d", &n) != EOF) {
		printf("%lld\n", hanoi(n));
	}
	return 0;
}