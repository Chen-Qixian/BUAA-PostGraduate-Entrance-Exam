#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int m, n;
	double h;
	while(scanf("%d", &m) != EOF) {
		while(m --) {
			scanf("%lf%d", &h, &n);
			double ans = h;
			n --;
			while(n > 0) {
				ans += h; 
				n --;
				h /= 2;
			}
			printf("%.2lf\n", ans);	
		}
	}

	return 0;
}