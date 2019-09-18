/*
	质因数的个数
	注意：超大质因数的处理方案
*/
#include <bits/stdc++.h>
#define SIZE 100000
#define BATCH 30
using namespace std;

bool mark[SIZE];
int prime[SIZE];
int num = 0;

void init() {
	for(int i = 0 ; i < SIZE ; i ++) {
		mark[i] = false;
	}
	for(int i = 2 ; i < SIZE ; i ++) {
		if(mark[i]) continue;
		prime[num ++] = i;
		for(int j = i * i ; j < SIZE ; j += i) {
			mark[j] = true;
		}
	}
}

int main(void) {
	init();
	int n;
	int ptr;
	int fac[BATCH] = {0};
	int con[BATCH] = {0};
	while(scanf("%d", &n) != EOF) {
		ptr = 0;	
		for(int i = 0 ; i < num ; i ++) {
			if(n % prime[i] == 0) {
				fac[ptr] = prime[i];
				con[ptr] = 1;
				n /= prime[i];
				while(n % prime[i] == 0) {
					con[ptr] ++;
					n /= prime[i];
				}
				ptr ++;
				if(n == 1) break;
			}
		}
		if(n != 1) {
			fac[ptr] = n;
			con[ptr ++] = 1;
		}
		int ans = 0;
		for(int i = 0 ; i < ptr ; i ++) {
			ans += con[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}








