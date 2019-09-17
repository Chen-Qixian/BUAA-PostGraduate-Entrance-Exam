/*
	Digital Roots
*/
#include <bits/stdc++.h>
using namespace std;

int digitRoot(int n) {
	if(n < 10) return n;
	int root = 0;
	while(n) {
		root += (n % 10);
		n /= 10;
	}
	return digitRoot(root);
}

int main(void) {
	char s[1000];
	while(scanf("%s", s) != EOF) {
		int root = 0;
		for(int i = 0 ; s[i] != 0 ; i ++) {
			root += (s[i] - '0');
		}
		if(root < 10){
			printf("%d\n", root);
		}
		else {
			printf("%d\n", digitRoot(root));
		}
	}
	return 0;
}