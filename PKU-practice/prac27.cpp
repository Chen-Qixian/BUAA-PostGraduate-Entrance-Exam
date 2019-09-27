/*
	整数奇偶排序
*/
#include <bits/stdc++.h>
using namespace std;

int a[20];

bool cmp1(int a, int b) {
	return a < b;
}

bool cmp2(int a, int b) {
	return a > b;
}

int main(void) {
	while(scanf("%d%d%d%d%d%d%d%d%d%d", a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]) != EOF) {
		int odd = 0, even = 0;
		int b[20];
		for(int i = 0 ; i < 10 ; i ++) {
			if(a[i] & 1 == 1) {
				b[odd ++] = a[i];
			}
		}
		sort(b, b + odd, cmp2);
		for(int i = 0 ; i < odd; i ++) {
			printf("%d ", b[i]);
		}
		printf("\n");
		for(int i = 0 ; i < 10 ; i ++) {
			if(a[i] & 1 == 0) {
				b[even ++] = a[i];
			}
		}
		sort(b, b + even , cmp1);
		for(int i = 0 ; i < even; i ++) {
			printf("%d ", b[i]);
		}
		printf("\n");
	}

	return 0;
}