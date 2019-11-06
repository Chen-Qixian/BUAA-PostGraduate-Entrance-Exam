#include <bits/stdc++.h>
using namespace std;

struct P {
	double x;
	double y;
	double operator - (const P &A) const{
		return sqrt(pow((A.x - x), 2) + pow((A.y - y), 2));
	}
}a, b;

int main(void) {
	int m;
	while(scanf("%d", &m) != EOF) {
		while(m --) {
			scanf("%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y);
			printf("%.2lf\n", a - b);
		}
	}
	return 0;
}