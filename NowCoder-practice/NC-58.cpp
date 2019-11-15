#include <bits/stdc++.h>
using namespace std;
struct P {
	int x;
	int y;

	bool operator < (const P &a) const {
		int mod1 = sqrt(pow(x, 2) + pow(y, 2));
		int mod2 = sqrt(pow(a.x, 2) + pow(a.y, 2));
		if(mod1 != mod2) return mod1 > mod2;
		return y < a.y;
	}
};

int main(void) {
	int n;
	char op[10];
	vector<P> v;
	while(scanf("%d", &n) != EOF) {
		v.clear();
		while(n --) {
			scanf("%s", op);
			if(strcmp(op, "Pop") == 0) {
				if(v.size() == 0) {
					printf("empty\n");
				}
				else {
					sort(v.begin(), v.end());
					printf("%d+i%d\n", v[0].x, v[0].y);
					v.erase(v.begin(), v.begin() + 1);
					printf("SIZE = %d\n", v.size());
				}
			}
			else if(strcmp(op, "Insert") == 0) {
				P tmp;
				scanf("%d+i%d", &tmp.x, &tmp.y);
				v.push_back(tmp);
				printf("SIZE = %d\n", v.size());
			}
		}
	}
	return 0;
}