#include <bits/stdc++.h>
using namespace std;

int main(void) {
	char s[5];
	while(scanf("%s", s) != EOF) {
		for(int i = 3 ; i >= 0 ; i --) {
			printf("%c", s[i]);
		}
		printf("\n");
	}
	return 0;
}