#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int a[5][5], b[5][5];
	int ans[5][5];
	for(int i = 0 ; i < 2; i ++) {
		for(int j = 0 ; j < 3 ; j ++) {
			scanf("%d", &a[i][j]);
		}
	}
	for(int i = 0 ; i < 3 ; i ++ ){
		for(int j = 0 ; j < 2 ; j ++) {
			scanf("%d", &b[i][j]);
		}
	}

	for(int i = 0 ; i < 2 ; i ++) {
		for(int j = 0 ; j < 2 ; j ++) {
			int tmp = 0;
			for(int k = 0 ; k < 3 ; k ++) {
				tmp += a[i][k] * b[k][j];
			}
			ans[i][j] = tmp;
		}
	}
	for(int i = 0 ; i < 2 ; i ++) {
		for(int j = 0 ; j < 2 ; j ++)  {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}