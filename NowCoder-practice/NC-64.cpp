#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n;
	while(scanf("%d", &n) != EOF) {
		int odd = 0, even = 0;
		int x;
		while(n --) {
			scanf("%d", &x);
			if(x & 1 == 1) {
				odd ++;
			}
			else {
				even ++;
			}
		}
		// printf("%d %d\n", even, odd);
		printf("%s\n", (even > odd) ? "NO" : "YES");
	}
	return 0;
}