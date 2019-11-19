#include <bits/stdc++.h>
using namespace std;


int main(void) {
	int n;
	while(scanf("%d", &n) != EOF) {
		int a = 0, b = 0;
		int m = n * n;
		while(n) {
			a += (n % 10);
			n /= 10;
		}
		while(m) {
			b += (m % 10);
			m /= 10;
		}
		printf("%d %d\n", a, b);
	}
	return 0;
}