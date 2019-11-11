#include <bits/stdc++.h>
using namespace std;

int main(void) {
	char s[1001];
	bool flag = true;
	while(scanf("%s", s) != EOF) {
		flag = true;
		for(int i = 0 ,len = strlen(s); i < len / 2; i ++) {
			if(s[i] != s[len - i - 1]) {
				flag = false;
				break;
			}
		}
		if(flag) {
			printf("Yes!\n");
		}
		else {
			printf("No!\n");
		}
	}
	return 0;	
}