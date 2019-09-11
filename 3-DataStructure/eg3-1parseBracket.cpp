/*
	括号匹配问题
*/
#include <bits/stdc++.h>
using namespace std;

stack<char> S;
char str[110];
char res[110];

int main(void) {
	while(scanf("%s", str) != EOF) {
		memset(res, 0 , sizeof(res));
		int i;
		for(i = 0 ; str[i] != '\0'; i ++) {
			res[i] = ' ';
			if(str[i] == '(') {
				S.push(i);
			}
			else if(str[i] == ')') {
				if(S.empty() == true) {
					res[i] = '?';
				}
				else {
					S.pop();
				}
			}
		}
		res[i] = '\0';
		while(S.empty() != true) {
			res[S.top()] = '$';
			S.pop();
		}
		printf("%s\n%s\n", str, res);
	}
	return 0;
}