/*
	N阶楼梯上楼问题
*/
#include <bits/stdc++.h>
using namespace std;

int nstep(int x) {
	if(x == 1) return 1;
	if(x == 2) return 2;
	return nstep(x - 1) + nstep(x - 2);
}

int main(void) {
	int n;
	while(scanf("%d", &n) != EOF) {
		printf("%d\n", nstep(n));
	}
	return 0;
}