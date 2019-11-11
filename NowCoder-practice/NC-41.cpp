#include <bits/stdc++.h>
using namespace std;
#define N 101

int mat[N][N];

int main(void) {
	int n;
	while(scanf("%d", &n) != EOF) {
		for(int i = 0 ; i < n ; i ++) {
			for(int j = 0 ; j < n ; j ++) {
				scanf("%d", &mat[i][j]);
			}
		}
		bool flag = true;
		for(int i = 0 ; i < n ; i ++) {
			for(int j = i + 1 ; j < n ; j ++) {
				if(mat[i][j] != mat[j][i]) {
					flag = false;
					break;
				}
			}
		}
		if(flag) {
			printf("Yes!\n");
		}
		else {
			printf("No!\n");
		}
	}
	return 0;
}