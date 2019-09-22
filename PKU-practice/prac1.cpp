/*
	简单密码
*/
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	char str[220];
	char ans[220];
	while(gets(str)) {
		if(strcmp(str, "ENDOFINPUT") == 0) break;
		if(strcmp(str, "START") == 0) continue;
		if(strcmp(str, "END") == 0) {
			printf("%s\n", ans);
			continue;
		}
		int len = strlen(str);
		for(int i = 0 ; i < len ; i ++){
			if(str[i] >='A' && str[i] <= 'Z') {
				ans[i] = (str[i] - 'A' - 5 + 26) % 26 + 'A'; 
			}
			else {
				ans[i] = str[i];
			}
		}
		ans[len] = 0;
	}

	return 0;
}