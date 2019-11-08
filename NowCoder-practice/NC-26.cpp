#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int m;
	double r, v;
	int x1, y1, z1, x2, y2, z2;
	while(scanf("%d", &m) != EOF) {
		while(m --) {
			scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
			r = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2) + pow((z1 - z2), 2));
			v = 4 * M_PI * pow(r, 3) / 3;
			printf("%.2lf %.2lf\n", r, v);
		}
	}
	return 0;
}