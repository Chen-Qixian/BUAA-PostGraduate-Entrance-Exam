/*
	特殊排序
*/
#include <bits/stdc++.h>
#define SIZE 1100
using namespace std;

int buf[SIZE];

int main(void) {
	int n;
	while(scanf("%d",&n) != EOF) {
		for(int i = 0 ; i < n ; i ++) {
			scanf("%d" , &buf[i]);
		}
		sort(buf, buf + n);
		printf("%d\n", buf[n - 1]);
		if(n == 1) printf("-1");
		for(int i = 0 ; i < n - 1 ; i ++) {
			printf("%d ", buf[i]);
		}
	}
	return 0;
}