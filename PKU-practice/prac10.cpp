/*
	密码翻译
*/
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	char s[100];
	while(gets(s)) {
		int len = strlen(s);
		for(int i = 0 ; i < len ; i ++) {
			if(s[i] >= 'a' && s[i] <= 'z') {
				s[i] = (s[i] - 'a' + 1) % 26 + 'a';
			}
			else if(s[i] >= 'A' && s[i] <= 'Z') {
				s[i] = (s[i] - 'A' + 1) % 26 + 'A';
			}
		}
		printf("%s\n", s);
	}

	return 0;
}