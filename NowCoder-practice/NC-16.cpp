#include <bits/stdc++.h>
using namespace std;

struct E {
	int x;
	int y;

	E operator + (const E &A) const {
		E ret;
		ret.x = x + A.x;
		ret.y = y + A.y;
		return ret;
	}
}a, b;	

int main(void) {
	int x, y;
	E tri;
	tri.x = 0;
	tri.y = 0;
	while(scanf("%d", &x) != EOF) {
		if(x == 0) break;
		scanf("%d", &y);
		E tmp;
		tmp.x = x;
		tmp.y = y;
		tri = tri + tmp;
	}
	printf("A(0,%d),B(0,0),C(%d,0)\n", tri.x, tri.y);
	return 0;
}