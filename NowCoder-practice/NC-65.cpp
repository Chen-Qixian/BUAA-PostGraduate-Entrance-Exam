#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int b[100], len;
	int n;
	while(scanf("%d", &n) != EOF) {
		len = 0;
		while(n) {
			b[len ++] = n % 2;
			n /= 2;
		}
		for(int i = len - 1 ; i >= 0 ; i --) {
			printf("%d", b[i]);
		}
		printf("\n");
	}
	return 0;
}