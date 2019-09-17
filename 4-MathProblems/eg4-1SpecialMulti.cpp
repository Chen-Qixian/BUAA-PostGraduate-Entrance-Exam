/*
	特殊乘法
*/	
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	char a[20], b[20];
	int ans;
	while(scanf("%s%s", a, b) != EOF) {
		ans = 0;
		for(int i = 0; a[i] != 0 ; i ++) {
			for(int j = 0 ; b[j] != 0 ; j ++) {
				ans += (a[i] - '0') * (b[j] - '0');
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}