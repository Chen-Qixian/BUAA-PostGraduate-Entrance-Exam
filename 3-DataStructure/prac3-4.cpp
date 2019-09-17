/*
	二叉树
*/
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int m, n;
	while(scanf("%d%d", &m, &n) != EOF) {
		int num = 1;
		int left = 2 * m;
		int right = 2 * m + 1;
		while(right < n) {
			num += (right - left + 1);
			left = left * 2;
			right = right * 2 + 1;
		}
		if(n > left) {
			num += (n - left) + 1;
		}
		printf("%d\n", num);
	}
	return 0;
}