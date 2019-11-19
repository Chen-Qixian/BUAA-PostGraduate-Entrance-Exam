#include <bits/stdc++.h>
using namespace std;
#define N 1002

void trans(char *s, char *t) {
	for(int i = 0 , len = strlen(s); i < len ; i ++) {
		t[i] = s[i];
		if(s[i] >= 'A' && s[i] <= 'Z') {
			t[i] += 0x20;
		}
	}
}

int main(void) {
	int n;
	char s[N][N];
	char t[N][N];
	char reg[N];
	while(scanf("%d", &n) != EOF) {
		for(int i = 1; i <= n ; i ++) {
			scanf("%s", s[i]);
			trans(s[i], t[i]);
		}
		scanf("%s", reg);
		trans(reg, t[0]);
		for(int i = 1 ; i <= n ; i ++) {
			if(regex_match(t[i], regex(t[0]))){
				printf("%d %s\n", i, s[i]);
			}
		}
	}
	return 0;
}