#include <bits/stdc++.h>
using namespace std;

int main(void) {
	char s[220];
	while(scanf("%s", s) != EOF) {
		for(int i = 0, len = strlen(s) ; i < len ; i ++) {
			printf("%c", s[len-i-1]);
		}
		printf("\n");
	}
	return 0;
}