#include <bits/stdc++.h>
using namespace std;

struct P{
	int x;
	int y;
	bool operator < (const P &a) const{
		if(x != a.x) return x < a.x;
		return y < a.y;
	}
} p[1001];

int main(void) {
	int n;
	while(scanf("%d", &n) != EOF) {
		for(int i = 0 ; i < n ; i ++) {
			scanf("%d%d", &p[i].x, &p[i].y);
		}
		sort(p, p + n);
		printf("%d %d\n", p[0].x, p[0].y);
	}
	return 0;	
}