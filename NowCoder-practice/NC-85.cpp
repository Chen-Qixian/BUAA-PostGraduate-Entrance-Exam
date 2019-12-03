#include <bits/stdc++.h>
using namespace std;

int solve(char p[1001][20], int n, char s[5001][20], int m) {
	int max = -1, i, j;
	for(i = 0 ; i < n ; i ++) {
		for(j = 0 ; j < m ; j ++) {
			if(strcmp(p[i], s[j]) == 0) {
				if(j > max) {
					max = j;
				}
				break;
			}
		}
		if(j == m) {
			return 0;
		}
	}
	if(n == 1 && max != -1) {
		return -1;
	}
	return 1 + solve(p, n, s + max, m - max);
}

int main(void) {
	int n, m;
	char p[1001][20], s[5001][20];
	while(scanf("%d", &n) != EOF) {
		for(int i = 0 ; i < n ; i ++) {
			scanf("%s", p[i]);
		}
		scanf("%d", &m);
		for(int i = 0 ; i < m ; i ++) {
			scanf("%s", s[i]);
		}
		printf("%d\n", solve(p, n, s, m));
	}
	return 0;
}