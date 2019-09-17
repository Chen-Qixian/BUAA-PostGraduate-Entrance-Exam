/*
	数制转换
*/
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int a,b;
	char n[100];
	long long t;
	int tmp;
	int ans[100];
	while(scanf("%d%s%d",&a,n,&b) != EOF) {
		t = 0;
		for(int i = strlen(n) - 1, j = 1 ; i >= 0 ; i --, j *= a) {
			tmp = 0;
			if(n[i] >= '0' && n[i] <= '9') {
				tmp = n[i] - '0';
			}
			else if(n[i] >= 'a' && n[i] <= 'z'){
				tmp = n[i] - 'a' + 10;
			}
			else {
				tmp = n[i] - 'A' + 10;
			}
			t += tmp * j;
		}
		if(t == 0) printf("0");
		tmp = 0;
		while(t) {
			if(t % b < 10) {
				ans[tmp] = t % b + '0';
			}
			else {
				ans[tmp] = t % b - 10 + 'A';
			}
			t /= b;
			tmp ++;
		}
		for(int i = tmp - 1; i >= 0 ; i --) {
			printf("%c",ans[i]);
		}
		printf("\n");
	}
	return 0;
}