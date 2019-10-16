#include <bits/stdc++.h>
#define isLeap(x) x % 100 != 0 && x % 4 == 0 || x % 400 == 0

int main(void) {
	int n;
	scanf("%d", &n);
	printf("%d\n", isLeap(n)? 1 : 0);
	return 0;
}