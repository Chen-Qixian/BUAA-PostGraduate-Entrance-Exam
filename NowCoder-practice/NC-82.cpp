#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int a[3];
	while(scanf("%d%d%d", &a[0], &a[1], &a[2]) != EOF) {
		sort(a, a + 3);
		if(a[0] * a[0] + a[1] * a[1] > a[2] * a[2]) {
			printf("锐角三角形\n");
		}
		else if(a[0] * a[0] + a[1] * a[1] == a[2] * a[2]) {
			printf("直角三角形\n");
		}
		else {
			printf("钝角三角形\n");
		}
	}
	return 0;
}