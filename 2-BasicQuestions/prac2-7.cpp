/*
	剩下的树
*/	
#include <bits/stdc++.h>
using namespace std;

int a[10005];

int main(void) {
	int l, m, s, e;
	int cnt;
	while(scanf("%d%d", &l, &m) != EOF) {
		cnt = 0;
		for(int i = 1 ; i <= l; i ++) {
			a[i] = 0;
		}
		for(int i = 0 ; i < m ; i ++) {
			scanf("%d%d", &s, &e);
			for(int j = s ; j <= e ; j ++) {
				a[j] ++;
			}
		}
		for(int i = 0 ; i <= l ; i ++) {
			if(a[i] == 0) {
				cnt ++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}