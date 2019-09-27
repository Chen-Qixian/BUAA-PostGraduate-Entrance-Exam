/*
	鸡兔同笼
*/
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int a;
	while(scanf("%d", &a) != EOF) {
		if(a & 1 == 1 || a < 2) {
			printf("0 0\n");
			continue;
		}
		int min = 0, max = 0;
		max = a / 2;
		min = a / 4;
		if(a % 4 != 0) {
			min ++;
		}
		printf("%d %d\n", min, max);
	}
	return 0;
}