#include <bits/stdc++.h>
using namespace std;
#define N 110

int main(void) {
	char s[N];
	int n;
	char op[N];
	while(scanf("%s", s) != EOF) {
		scanf("%d", &n);
		while(n --) {
			scanf("%s", op);
			int beg = op[1] - '0', len = op[2] - '0';
			if(op[0] == '0') {
				char t;
				for(int i = 0 ; i < len / 2 ; i ++) {
					t = s[beg + i];
					s[beg + i] = s[beg + len - 1 - i];
					s[beg + len - 1 - i] = t;
				}
				printf("%s\n", s);
			}
			else if(op[0] == '1') {
				char t[N];
				int i;
				for(i = 0 ; i < beg ; i ++) {
					t[i] = s[i];
				}
				for(int j = 3 ; j < strlen(op) ; j ++, i ++) {
					t[i] = op[j];
				}
				for(int j = beg + len ; j < strlen(s) ; j ++, i ++) {
					t[i] = s[j];
				}
				t[i] = 0;
				memset(s, 0, sizeof(s));
				strcpy(s, t);
				printf("%s\n", s);
			}
		}
	}

	return 0;
}