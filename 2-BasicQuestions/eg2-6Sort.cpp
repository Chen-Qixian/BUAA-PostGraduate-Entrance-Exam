/*
	Sort
*/
#include <bits/stdc++.h>
#define SIZE 1000001
#define BASE 500000
using namespace std;

int a[SIZE];

int main(void) {
	int n, m, num;
	while(scanf("%d%d", &n, &m) != EOF) {
		for(int i = -500000 ; i <= 500000 ; i ++) {
			a[i + BASE] = 0;
		}
		for(int i = 0 ; i < n ; i ++) {
			scanf("%d", &num);
			a[num + BASE] ++;
		}
		for(int i = 500000; i >= -500000 && m > 0; i --) {
			if(a[i + BASE] > 0) {
				printf("%d ", i);
				m --;
			}
		}
		printf("\n");
	}

	return 0;
}