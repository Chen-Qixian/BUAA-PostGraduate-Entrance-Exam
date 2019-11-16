#include <bits/stdc++.h>
using namespace std;
#define N 101

int c[11];
char a[N], b[N];

bool judge() {
	int lb = strlen(b);
	if(lb < 5) {
		int t = b[0] - '0';
		for(int i = t + 1 ; i < 10 ; i ++) {
			if(c[i] >= lb) {
				return true;
			}
		}
	}
	else {
		int t = b[0] - '0';
		for(int i = t + 1 ; i < 6 ; i ++) {
			int j;
			for(j = 0 ; j < 5 ; j ++) {
				if(c[i+j] == 0) {
					break;
				}
			}
			if(j == 5) return true;
		}
	}
	return false;
}

int main(void) {
	while(scanf("%s%s", a, b) != EOF) {
		for(int i = 0 ; i < 10 ; i ++) {
			c[i] = 0;
		}
		for(int i = 0 ,len = strlen(a); i < len ; i ++) {
			c[a[i] - '0'] ++;
		}
		printf("%s", judge() ? "YES\n" : "NO\n");

	}	
	return 0;	
}