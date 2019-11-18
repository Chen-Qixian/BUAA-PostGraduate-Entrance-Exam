#include <bits/stdc++.h>
using namespace std;

int n, k;
int m[11][11];
int tmp[11][11];
int ans[11][11];

void init() {
	for(int i = 0 ; i < n ; i ++) {
		for(int j = 0 ; j < n ; j ++) {
			ans[i][j] = 0;
		}
		ans[i][i] = 1;
	}
}

void multi() {
	for(int i = 0 ; i < n ; i ++) {
		for(int j = 0 ; j < n ; j ++) {
			int  t = 0;
			for(int k = 0 ; k < n ; k ++) {
				t += ans[i][k] * m[k][j];
			}
			tmp[i][j] = t;
		}
	}
	for(int i = 0 ; i < n ; i ++) {
		for(int j = 0 ; j < n ; j ++) {
			ans[i][j] = tmp[i][j];
		}
	}
}

void square() {
	for(int i = 0 ; i < n ; i ++) {
		for(int j = 0 ; j < n ; j ++) {
			int t = 0;
			for(int k = 0 ; k < n ; k ++) {
				t += m[i][k] * m[k][j];
			}
			tmp[i][j] = t;
		}
	}
	for(int i = 0 ; i < n ; i ++) {
		for(int j = 0 ; j < n ; j ++) {
			m[i][j] = tmp[i][j];
		}
	}
}

void output() {
	for(int i = 0 ; i < n ; i ++) {
		for(int j = 0; j < n ; j ++) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
}

int main(void) {
	while(scanf("%d%d", &n, &k) != EOF) {
		init();
		for(int i = 0 ; i < n ; i ++) {
			for(int j = 0 ; j < n ; j ++) {
				scanf("%d", &m[i][j]);
			}
		}
		while(k) {
			if(k % 2 == 1) {
				multi();
			}
			square();
			k /= 2;
		}
		output();
	}
	return 0;
}