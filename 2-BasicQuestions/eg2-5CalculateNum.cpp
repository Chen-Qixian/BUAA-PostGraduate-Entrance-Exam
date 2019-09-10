/*
	统计同成绩学生人数
*/
#include <bits/stdc++.h>
#define SIZE 1100
using namespace std;

int a[SIZE];

int main(void) {
	int n, g, d;
	while(scanf("%d", &n) != EOF) {
		if(n == 0) break;
		for(int i = 0 ; i < SIZE ; i ++) {
			a[i] = 0;
		}
		for(int i = 0 ; i < n ; i ++) {
			scanf("%d", &g);
			a[g] ++;	
		}
		scanf("%d", &d);
		printf("%d\n", a[d]);
	}
	return 0;
}