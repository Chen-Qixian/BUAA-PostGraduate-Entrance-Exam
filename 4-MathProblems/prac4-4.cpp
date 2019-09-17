/*
	对称平方数
*/
#include <bits/stdc++.h>
using namespace std;

bool isRev(int n){
	int len = 0;
	n = n * n;
	int a[100];
	while(n) {
		a[len ++] = n % 10;
		n /= 10;
	}
	for(int i = 0 ; i < len ; i ++) {
		if(a[i] != a[len - 1 - i]) {
			return false;
		}
	}
	return true;
}


int main(void) {
	for(int i = 1 ; i < 256 ; i ++) {
		if(isRev(i)) {
			printf("%d\n", i);
		}
	}
	return 0;
}