#include <bits/stdc++.h>
using namespace std;
#define N 101

int a[N][N],b[N][N];

int main(void) {
	int n;
	int tmp;
	while(scanf("%d", &n) != EOF) {
		for(int i = 0 ; i < n ; i ++) {
			for(int j = 0 ; j < n ; j ++) {
				scanf("%d", &tmp);
				a[j][i] = tmp;
			}
		}
		for(int i = 0 ; i < n ; i ++) {
			for(int j = 0 ; j < n ; j ++) {
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}