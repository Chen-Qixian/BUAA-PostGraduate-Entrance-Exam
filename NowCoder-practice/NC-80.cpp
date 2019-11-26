#include <bits/stdc++.h>
using namespace std;
#define N 10010
int a[N];
int cnt = 0;
void init() {
	for(int i = 6 ; i < N ; i ++) {
		int bound = (int)(sqrt(i) + 1);
		int sum = 1;
		for(int j = 2 ; j < bound ; j ++) {
			if(i % j == 0) {
				sum += j;
				if(i != j * j){
					sum += (i / j);
				}
			}
		}
		if(sum == i) {
			a[cnt ++] = i;
		}
	}
}

int main(void) {	
	init();
	int n;
	while(scanf("%d", &n) != EOF) {
		for(int i = 0 ; i < cnt ; i ++) {
			if(a[i] <= n) {
				printf("%d " , a[i]);
			}
		}
		printf("\n");
	}
	return 0;	
}