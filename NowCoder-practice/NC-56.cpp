#include <bits/stdc++.h>
using namespace std;
int a[101], b;

bool search(int n) {
	int left = 0, right = n, mid = left + (right - left) / 2;
	while(left <= right) {
		mid = left + (right - left) / 2;
		if(b == a[mid]) return true;
		else if(b > a[mid]) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return false;
}

int main(void) {
	int n, m;
	while(scanf("%d", &n) != EOF) {
		for(int i = 0 ; i < n ; i ++) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		scanf("%d", &m);
		for(int i = 0 ; i < m ; i ++) {
			scanf("%d", &b);
			printf("%s", search(n) ? "YES\n" : "NO\n");
		}
	}
	return 0;
}