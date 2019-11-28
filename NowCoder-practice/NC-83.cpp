#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n;
	int a[100];
	while(scanf("%d", &n) != EOF) {
		int max,maxidx = 0, min, minidx = 0;
		scanf("%d", &a[0]);
		max = min = a[0];
		for(int i = 1 ; i < n ; i ++) {
			scanf("%d", &a[i]);
			if(a[i] > max) {
				max = a[i];
				maxidx = i;
			}
			if(a[i] < min) {
				min = a[i];
				minidx = i;
			}
		}
		int t = a[maxidx];
		a[maxidx] = a[minidx];
		a[minidx] = t;
		for(int i = 0 ; i < n ; i ++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	return 0;
}