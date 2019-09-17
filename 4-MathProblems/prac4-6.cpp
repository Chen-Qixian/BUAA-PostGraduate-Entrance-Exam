/*
	八进制
*/
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n;
	int ans[100];
	while(scanf("%d", &n) != EOF) {
		if(n == 0) printf("0");
		int i = 0;
		while(n) {
			ans[i ++] = (n % 8);
			n /= 8;
		}
		for(i = i - 1; i >= 0 ; i --) {
			printf("%d",ans[i]);
		}
		printf("\n");
	} 
	return 0;
}