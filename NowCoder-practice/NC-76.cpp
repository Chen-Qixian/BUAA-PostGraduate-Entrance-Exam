#include <bits/stdc++.h>
using namespace std;
#define N 1000

int a, n;
int ans[N];

void init() {
	for(int i = 0 ; i <= n ; i ++) {
		ans[i] = 0;
	}
}

int main(void) {
	while(scanf("%d%d", &a, &n) != EOF) {
		init();
		int carry = 0;
		for(int i = 0 ; i < n ; i ++) {
			int tmp = (n - i) * a + carry;
			ans[i] = tmp % 10;
			carry = tmp / 10;
		}
		if(carry != 0){
			printf("%d", carry);	
		}
		for(int i = n - 1 ; i >= 0; i --) {
			printf("%d", ans[i]);
		}
		printf("\n");
	}
	return 0;
}