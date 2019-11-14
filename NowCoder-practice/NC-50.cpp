#include <bits/stdc++.h>
using namespace std;

int main(void) {
	char s[10001];
	while(gets(s)) {
		int cnt = 0;
		for(int i = 0 , len = strlen(s); i < len ; i ++) {
			if(s[i] == ' ') {
				if(cnt > 0){
					printf("%d ", cnt);
					cnt = 0;
				}
			}
			else {
				cnt ++;
			}
		}
		printf("%d\n", cnt - 1);
	}
	return 0;
}