#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n;
	map<char, char> m;
	m['('] = ')';
	m['['] = ']';
	m['{'] = '}';
	char str[10010];
	while(scanf("%d", &n) != EOF) {
		while(n --) {
			bool flag = true;
			stack<char> s;
			scanf("%s", str);		
			while(!s.empty()) s.pop();
			for(int i = 0,len = strlen(str) ; i < len ; i ++) {
				if(str[i] == '(' || str[i] == '[' || str[i] == '{') {
					s.push(str[i]);
				}
				else if(str[i] == ')' || str[i] == ']' || str[i] == '}') {
					if(s.empty()) {
						flag = false;
						break;
					}
					if(str[i] == m[s.top()]) {
						s.pop();
					}
					else{
						flag = false;
						break;
					}
				}
			}
			if(flag && s.empty()) {
				printf("yes\n");
			}	
			else {
				printf("no\n");
			}
		}
	}
	return 0;
}