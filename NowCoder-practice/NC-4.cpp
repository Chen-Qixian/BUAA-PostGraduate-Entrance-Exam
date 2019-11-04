#include <bits/stdc++.h>
using namespace std;

int eNum = 0,gNum = 0;
int e[60],g[60];

int facSum(int x) {
	int res = 1;
	for(int i = 2 ; i < x ; i ++) {
		if(x % i == 0) {
			res += i;
		}
	}
	return res;
}

int main(void) {
	for(int i = 2 ; i <= 60 ; i ++) {
		if(i == facSum(i)) {
			e[eNum ++] = i;
		}
		else if(i < facSum(i)) {
			g[gNum ++] = i;
		}
	}
	printf("E: ");
	for(int i = 0; i < eNum ; i ++) {
		printf("%d ", e[i]);
	}
	printf("G: ");
	for(int i = 0 ; i < gNum ; i ++) {
		printf("%d ", g[i]);
	}
	return 0;
}