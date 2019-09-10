/*
	找x
*/
#include <bits/stdc++.h>
using namespace std;

int a[220];

int find(int x, int n) {
	for(int i = 0 ; i < n ; i ++) {
		if(a[i] == x) {
			return i;
		}
	}
	return -1;
}

int main(void){
	int n, x;
	while(scanf("%d", &n) != EOF) {
		for(int i = 0 ; i < n ; i ++) {
			scanf("%d", &a[i]);
		}
		scanf("%d" , &x);
		printf("%d\n", find(x, n));
	}

	return 0;
}