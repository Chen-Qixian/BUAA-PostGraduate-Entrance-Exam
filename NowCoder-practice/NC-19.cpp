#include <bits/stdc++.h>
using namespace std;

struct I {
	int x;
	int y;

	void init() {
		x = 0;
		y = 0;
	}

	I operator + (const I &A) const {
		I res;
		res.x = x + A.x;
		res.y = y + A.y;
		return res;
	}

	void output() {
		if(y > 0) {
			printf("%d+%di\n", x, y);
		}	
		else if(y == 0) {
			printf("%d\n", x);
		}
		else {
			printf("%d-%di\n", x, -y);
		}
	}
}a, b;

int main(void) {
	int m;
	while(scanf("%d", &m) != EOF) {
		while(m --) {
			a.init();
			b.init();
			scanf("%d%d%d%d", &a.x, &a.y, &b.x, &b.y);
			I res = a + b;
			res.output();
		}
	}
	return 0;
}