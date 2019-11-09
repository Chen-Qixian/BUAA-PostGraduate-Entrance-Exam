#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main(void) {
	int a[200];
	int x[10][10];
	int m;
	while(scanf("%d", &m) != EOF) {
		int cnt = 0;
		for(int i = 0 ; i < m ; i ++) {
			int tmp = 0;
			for(int j = 0 ; j < m ; j ++) {
				scanf("%d", &x[i][j]);
				tmp += x[i][j];
			}
			a[cnt ++] = tmp;
		}
		
		for(int j = 0 ; j < m ; j ++) {
			int tmp = 0;
			for(int i = 0 ; i < m ; i ++) {
				tmp += x[i][j];
			}
			a[cnt ++] = tmp;
		}
		int tmp = 0;
		for(int i = 0 ; i < m ; i ++) {
			tmp += x[i][i];
		}
		a[cnt ++] = tmp;
		tmp = 0;
		for(int i = 0 ; i < m ; i ++) {
			tmp += x[i][m - i - 1];
		}
		a[cnt ++] = tmp;
		sort(a, a + cnt, cmp);
		for(int i = 0 ; i < cnt ; i ++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}

	return 0;
}