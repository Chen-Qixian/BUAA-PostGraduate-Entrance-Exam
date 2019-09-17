/*
	又一版A + B
*/
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	long long a, b;
	int m;
	int ans[20];
	while(scanf("%d", &m) != EOF) {
		if(m == 0) break;
		scanf("%lld%lld", &a, &b);
		a = a + b;
		int i = 0;
		if(a == 0){
			printf("0\n");
		}
		while(a) {
			ans[i ++] = (a % m);
			a /= m;
		}
		
		for(i = i - 1; i >= 0 ; i --) {
			printf("%d", ans[i]);
		}

		printf("\n");
	}
	return 0;
}