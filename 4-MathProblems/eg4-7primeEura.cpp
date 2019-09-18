/*
	素数
	注意：素数的欧拉筛法
*/
#include <bits/stdc++.h>
using namespace std;

bool mark[10010];
int prime[10010];

void init() {
	for(int i = 0 ; i < 10010 ; i ++) {
		mark[i] = false;
	}
	int n = 0;
	for(int i = 2 ; i <= 10000 ; i ++) {
		if(mark[i]) continue;
		prime[n ++] = i;
		for(int j = i * i ; j <= 10000 ; j += i) {
			mark[j] = true;
		}
	}
}

int main(void) {
	int n;
	bool flag;
	init();
	while(scanf("%d", &n) != EOF) {
		flag = true;
		if(n < 12) {
			printf("-1");
		}
		for(int i = 0 ; prime[i] < n ; i ++) {
			if(prime[i] % 10 == 1) {
				if(flag) {
					printf("%d", prime[i]);
					flag = false;
				}
				else {
					printf(" %d", prime[i]);
				}
			}
		}
		printf("\n");
	}
	return 0;
}