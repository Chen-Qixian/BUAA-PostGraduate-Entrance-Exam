#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int a[11], x;
	while(scanf("%d", &x) != EOF) {
		for(int i = 1 ; i <= 10 ; i ++) {
			a[i] = 0;
		}
		a[x] ++;
		for(int i = 1; i < 20 ; i ++) {
			scanf("%d", &x);
			a[x] ++;
		}
		int max = 0;
		int idx = 1;
		for(int i = 1 ; i <= 10 ; i ++) {
			if(a[i] > max) {
				max = a[i];
				idx = i;
			}	
		}
		printf("%d\n", idx);
	}

	return 0;
}