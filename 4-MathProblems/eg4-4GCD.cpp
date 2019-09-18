/*
	最大公约数
*/
#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b) {
	if(b == 0) return a;
	return gcd(b ,a % b);
}

int main(void) {
	int a, b;
	while(scanf("%d%d",&a ,&b) != EOF) {
		printf("%d\n", gcd(a, b));
	}
	return 0;
}