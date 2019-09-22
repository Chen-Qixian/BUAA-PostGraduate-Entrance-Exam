/*
	2018-1-A
*/
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
	int bound = (int)sqrt(x) + 1;
	for(int i = 2 ; i < bound ; i ++) {
		if(x % i == 0) return false;
	}
	return true;
}

int main(void) {
	int n;
	while(scanf("%d", &n) != EOF) {
		if(n == 1) {
			printf("2\n");
			continue;
		}
		int cnt = 1;
		for(int i = 3 ; i < 1000000000 ; i +=2) {
			if(isPrime(i)){
				cnt ++;
			}
			if(cnt == n){
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}