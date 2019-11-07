#include <bits/stdc++.h>
using namespace std;

double calDelta(double a, double b, double c) {
	return b * b - 4 * a * c;
}

int main(void) {
	int m;
	double a, b, c;
	while(scanf("%d", &m) != EOF) {
		while(m --) {
			scanf("%lf%lf%lf", &a, &b, &c);
			double delta = calDelta(a, b, c);
			if(a == 0) {
				if(b == 0) {
					printf("-1\n");
				}
				else {
					double ans = -c / b;
					printf("x=%.2lf\n", ans);
				}
				continue;
			}
			if(delta < 0) {
				printf("-1\n");
			}
			else if (delta == 0) {
				double ans = -b / (2 * a);
				if(b == 0){
					printf("x=0.00\n");
				}
				else{
					printf("x=%.2lf\n", ans);
				}
			}
			else {
				double ans1 = (-b - sqrt(delta)) / (2 * a);
				double ans2 = (-b + sqrt(delta)) / (2 * a);
				printf("x1=%.2lf,x2=%.2lf\n", ans1, ans2);
			}
		}
	}
	return 0;
}