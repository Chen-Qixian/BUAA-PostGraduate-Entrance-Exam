/*
	百鸡问题
	枚举
*/
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n;
	while(scanf("%d", &n) != EOF) {
		n *= 3;
		for(int i = 0 ; i <= 100 ; i ++) {
			for(int j = 0 ; j <= 100 ; j ++) {
				if(i * 15 + j * 9 + (100 - i - j) <= n) {
					printf("x=%d,y=%d,z=%d\n", i, j, 100 - i - j);
				}
				else {
					break;
				}
			}
		}
	}
	return 0;
}