/*
	素数判定
*/
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
	if(n < 2) return false;
	int limit = sqrt(n);
	for(int i = 2 ; i <= limit; i ++) {
		if(n % i == 0) return false;
	}
	return true;
}

int main(void){
	int n;
	while(scanf("%d", &n) != EOF) {
		if(isPrime(n)){
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}
	return 0;
}