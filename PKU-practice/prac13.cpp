/*
	小白鼠排队
*/
#include <bits/stdc++.h>
using namespace std;
#define N 110

struct E {
	int w;
	char co[20];
	bool operator < (const E &a) const {
		return w > a.w;
	}
} e[N];

int main(void) {
	int n;
	while(scanf("%d", &n) != EOF) {
		for(int i = 0 ; i < n ; i ++) {
			scanf("%d%s", &e[i].w, e[i].co);
		}
		sort(e, e + n);
		for(int i = 0 ; i < n ; i ++) {
			printf("%s\n", e[i].co);
		}
	}
	return 0;
}