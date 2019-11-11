#include <bits/stdc++.h>
using namespace std;
#define N 101
int mat[N][N];

int main(void) {
	int m, n;
	while(scanf("%d%d", &m, &n) != EOF) {
		for(int i = 0 ; i < m ; i++) {
			int tmp = 0;
			int max = INT_MIN;
			int idx = 0;
			for(int j = 0 ; j < n ; j ++) {
				scanf("%d", &mat[i][j]);
				tmp += mat[i][j];
				if(mat[i][j] > max) {
					max = mat[i][j];
					idx = j;
				}
			}
			mat[i][idx] = tmp;
		}

		for(int i = 0 ; i < m ; i ++) {
			for(int j = 0 ; j < n ; j ++) {
				printf("%d ", mat[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}