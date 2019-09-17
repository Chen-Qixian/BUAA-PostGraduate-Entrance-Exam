/*
	守形数
*/
#include <bits/stdc++.h>
using namespace std;

int getLen(int n) {
	int len = 0;
	while(n) {
		n /= 10;
		len ++;
	}
	return len;
}

int main(void) {
	int n;
	int len;
	while(scanf("%d", &n) != EOF) {
		len = getLen(n);
		len = pow(10, len);
		if(n * n % len == n) {
			printf("Yes!\n");
		}
		else {
			printf("No!\n");
		}
	}
	return 0;	
}