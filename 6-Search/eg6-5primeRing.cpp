/*
	prime ring
	全排列 + 每次新加入的最后两位元素之和要为质数
*/
#include <bits/stdc++.h>
using namespace std;

bool flag[20];
int num[20];
int n;
int prime[13] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

bool isPrime(int x) {
	for(int i = 0 ; i < 13 ; i ++) {
		if(prime[i] == x) return true;
	}
	return false;
}

void ring(int k) {
	if(k > 1){
		if(isPrime(num[k] + num[k - 1]) == false) return;
	}
	if(k == n) {
		if(isPrime(num[1] + num[k]) == true) {
			for(int i = 1 ; i <= n ; i ++) {
				printf("%d ", num[i]);
			}
			printf("\n");
		}
		return;
	}

	for(int i = 1 ; i <= n ; i ++) {
		if(flag[i]) continue;
		num[k + 1] = i;
		flag[i] = true;
		ring(k + 1);
		flag[i] = false;
	}
}

int main(void) {
	int cas = 1;
	while(scanf("%d", &n) != EOF) {
		for(int i = 1 ; i <= n ; i ++) {
			num[i] = 0;
			flag[i] = false;
		}
		printf("Case %d:\n", cas ++);
		num[1] = 1;
		flag[1] = true;
		ring(1);
		printf("\n");
	}
	return 0;
}