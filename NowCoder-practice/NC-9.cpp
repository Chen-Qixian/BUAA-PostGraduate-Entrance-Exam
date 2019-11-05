#include <bits/stdc++.h>
using namespace std;
#define N 100000

int com[N];
int ptr = 0;

void init() {
	for(int i = 6 ; i < N ; i ++) {
		int t = 1;
		int bound = (int)(sqrt(i) + 1);
		for(int j = 2 ; j < bound ; j ++) {
			if(i % j == 0) {
				if(i / j == j) t += j;
				else {
					t += (i / j + j);
				}
			}
		}
		if(t == i) com[ptr ++] = i;
	}
}

int main(void) {
	init();
	int a,b;
	while(scanf("%d%d",&a,&b) != EOF) {
		for(int i = 0 ; i < ptr ; i ++) {
			if(com[i] > b) break;
			if(com[i] >= a) {
				printf("%d\n", com[i]);
			}
		}
	}
	return 0;
}