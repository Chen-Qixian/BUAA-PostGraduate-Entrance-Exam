/*
	最简真分数
*/
#include <bits/stdc++.h>
using namespace std;
#define N 601

int gcd(int x, int b) {
	if(b == 0) return x;
	return gcd(b, x % b);
}

int a[N];

int main(void) {
	int n;
	while(scanf("%d", &n) != EOF) {
		int cnt = 0;
		for(int i = 0 ; i < n ; i ++) {
			scanf("%d", &a[i]);
		}
		for(int i = 0 ; i < n - 1; i ++) {
			for(int j = i + 1; j < n ; j ++) {
				if(gcd(a[i], a[j]) == 1) {
					cnt ++;
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}