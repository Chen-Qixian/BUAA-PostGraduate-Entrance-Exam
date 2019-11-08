/*
	注意浮点数除法的精度问题
*/
#include <bits/stdc++.h>
using namespace std;

double f(int x) {
	double y = 0.0;
	if(x >= 0 && x < 2) {
		y = -x + 2.5;
	}
	else if(x >= 2 && x < 4) {
		y = 2 - 1.5 * (x - 3) * (x - 3);
	}
	else if(x >= 4 && x < 6) {
		y = x * 1.0 / 2 - 1.5;
	}
	return y;
}

int main(void) {
	int m, x, y;
	while(scanf("%d", &m) != EOF) {
		while(m --) {
			scanf("%d", &x);
			printf("y=%.1lf\n", f(x));
		}
	}
	return 0;
}