#include <bits/stdc++.h>
using namespace std;

struct P {
	double x;
	double y;
} a, b ,c;

double dist2(P a, P b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main(void) {
	int m;
	while(scanf("%d", &m) != EOF) {
		while(m --) {
			scanf("%lf%lf%lf%lf%lf%lf",&a.x, &a.y, &b.x, &b.y, &c.x, &c.y);
			double la2 = dist2(a, b);
			double lb2 = dist2(b, c);
			double lc2 = dist2(c, a);
			if(la2 + lb2 == lc2 || la2 + lc2 == lb2 || lb2 + lc2 == la2) {
				printf("Yes\n");
			}
			else {
				printf("No\n");
			}
			double cir = sqrt(la2) + sqrt(lb2) + sqrt(lc2);
			printf("%.2lf\n", cir);
		}
	}
	return 0;
}