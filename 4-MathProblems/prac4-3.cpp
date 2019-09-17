/*
	反序数
*/
#include <bits/stdc++.h>
using namespace std;

bool isRev(int n) {
	int k = n * 9;
	int len = 0;
	int a[5], b[5];
	while(len < 4) {
		a[len] = n % 10;
		b[len] = k % 10;
		n /= 10;
		k /= 10;
		len ++;
	}
	for(int i = 0 ; i < 4 ; i ++) {
		if(a[i] != b[3 - i]) {
			return false;
		}
	}
	return true;
}

int main(void) {
	for(int i = 1000; i < 2000 ; i ++) {
		if(isRev(i)) {
			printf("%d\n", i);
		}
	}
	return 0;
}