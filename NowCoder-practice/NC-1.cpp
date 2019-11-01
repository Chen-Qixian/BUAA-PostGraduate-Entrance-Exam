/*
	ProblemC
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50000;
int prime[MAXN], pnum = 0, p[MAXN] = {0};

void findPrime() {
	for(int i = 2; i < MAXN ; i ++) {
		if(p[i] == 0) {
			prime[pnum++] = i;
			for(int j = i + i; j < MAXN ; j += i) {
				p[j] = 1;
			}
		}
	}
}

int greatestFac(int n) {
	int ans = 0;
	int bound = (int) sqrt(1.0 * n);
	for(int i = 0 ; i < pnum && prime[i] < bound ; i ++) {
		if(n % prime[i] == 0) {
			ans = prime[i];
			while(n % prime[i] == 0) {
				n /= prime[i];
			}
		}
		if(n == 1) break;
	}
	if(n != 1) {
		ans = n;
	}
	return ans;
}


int main(void) {
	int n;
	char str[110];
	findPrime();
	while(scanf("%d", &n) != EOF) {
		while(n --) {
			scanf("%s", str);
			int num = 0;
			for(int i = 0, len = strlen(str) ; i < len ; i ++) {
				if(str[i] >= '0' && str[i] <= '9')
					num = num * 10 + (str[i] - '0');
			}
			if(num == 0) {
				printf("0\n");
			}
			else {
				int gf = greatestFac(num);
				printf("%d\n", gf);
			}
		}
	}
	return 0;
}