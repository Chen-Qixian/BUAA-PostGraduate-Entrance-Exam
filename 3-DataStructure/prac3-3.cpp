/*
	树查找
*/
#include <bits/stdc++.h>
using namespace std;

int a[1005];

int main(void) {
	int n, level;
	int s, e, i;
	while(scanf("%d", &n) != EOF) {
		for(int i = 1 ; i <= n ; i ++) {
			scanf("%d", &a[i]);
		}
		scanf("%d", &level);
		s = pow(2, level - 1);
		e = pow(2, level);
		if(s > n){
			printf("EMPTY");
		}
		else{
			i = s;
			printf("%d", a[i ++]);
			while(i <= n && i < e) {
				printf(" %d", a[i ++]);
			}
		}
		
		printf("\n");
	}
	return 0;
}