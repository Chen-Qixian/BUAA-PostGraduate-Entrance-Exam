#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int m;
	double x, y;
	while(scanf("%d",&m) != EOF) {
		while(m --) {
			double ans;
			scanf("%lf%lf", &x, &y);
			ans = sin((x - y) * M_PI / 180);
			printf("%.2lf\n", ans);
		}
	}
	return 0;
}