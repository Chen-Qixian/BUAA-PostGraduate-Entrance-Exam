/*
	谁是你的潜在朋友
*/
#include <bits/stdc++.h>
using namespace std;

int a[220];
int b[220];

int main(void) {
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF) {
		for(int i = 1; i <= m ; i ++) {
			a[i] = 0;
		}
		for(int i = 0 ; i < n ; i ++) {
			scanf("%d" , &b[i]);
			a[b[i]] ++;
		}
		for(int i = 0 ; i < n ; i ++) {
			if(a[b[i]] > 1) {
				printf("%d\n", a[b[i]] - 1);
			}
			else {
				printf("BeiJu\n");
			}
		}
	}

	return 0;
}