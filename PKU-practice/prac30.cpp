/*
	Candy Sharing Game
*/
#include <bits/stdc++.h>
using namespace std;
#define N 110

int n;
int a[N];

int findMax() {
	int ret = a[0];
	for(int i = 0 ; i < n ; i ++) {
		ret = max(ret, a[i]);
	}
	return ret;
}

int findMin() {
	int ret = a[0];
	for(int i = 0 ; i < n ; i ++) {
		ret = min(ret, a[i]);
	}
	return ret;
}

int main(void) {
	while(scanf("%d", &n) != EOF) {
		for(int i = 0 ; i < n ; i ++) {
			scanf("%d", &a[i]);
			if(a[i] % 2 == 1) {
				a[i] ++;
			}
		}
		int time = 0;
		int _min = findMin();
		int _max = findMax();
		while(_min != _max) {
			int tmp = a[n-1];
			for(int i = n - 1; i > 0 ; i --) {
				a[i] -= a[i] / 2;
				a[i] += a[i-1] / 2;
				if(a[i] % 2 == 1) a[i] ++; 
			}
			a[0] -= a[0] / 2;
			a[0] += tmp / 2;
			if(a[0] % 2 == 1) a[0] ++;
			_min = findMin();
			_max = findMax();
			time ++;
		}
		printf("%d %d\n", time, _min);
	}
	return 0;
}