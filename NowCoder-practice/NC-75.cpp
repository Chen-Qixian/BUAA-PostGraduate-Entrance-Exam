#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int a[11];
	while(scanf("%d", &a[0] ) != EOF) {
		for(int i = 1 ; i < 10 ; i ++) {
			scanf("%d", &a[i]);
		}
		sort(a, a + 10);
		printf("max=%d\n", a[9]);
	}

	return 0;
}