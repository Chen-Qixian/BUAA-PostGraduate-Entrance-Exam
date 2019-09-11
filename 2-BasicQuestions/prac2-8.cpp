/*
	打印极值点下标
*/
#include <bits/stdc++.h>
using namespace std;

int a[100];
int ans[100];
int main(void) {
	int k;
	int cnt;
	while(scanf("%d", &k) != EOF) {
		cnt = 0;
		for(int i = 0 ; i < k ; i ++) {
			scanf("%d", &a[i]);
		}
		if(a[0] != a[1]){
			ans[cnt ++] = 0;
		}
		for(int i = 1 ; i < k - 1 ; i ++) {
			if(a[i] > a[i - 1] && a[i] > a[i + 1] || a[i] < a[i - 1] && a[i] < a[i + 1]) {
				ans[cnt ++] = i;
			}
		}
		if(a[k - 2] != a[k - 1]){
			ans[cnt ++] = k - 1;
		}
		for(int i = 0 ; i < cnt; i ++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	return 0;
}