#include <bits/stdc++.h>
using namespace std;

int main(void) {
	char s[100];
	while(scanf("%s", s) != EOF) {
		if(s[0] == '!') break;
		for(int i = 0 , len = strlen(s) ; i < len ; i ++) {
			if(s[i] >= 'a' && s[i] <= 'z') {
				s[i] = (25 - (s[i] - 'a')) + 'a';
			}
			else if(s[i] >= 'A' && s[i] <= 'Z') {
				s[i] = (25 - (s[i] - 'A')) + 'A';
			}
		}
		printf("%s\n", s);
	}
	return 0;	
}