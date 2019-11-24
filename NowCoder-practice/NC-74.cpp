#include <bits/stdc++.h>
using namespace std;
#define N 1010

int main(void) {
	char s[N],ans[N];
	char c;
	while(scanf("%s", s) != EOF) {
		getchar();
		scanf("%c", &c);
		int j = 0;
		for(int i = 0 , len = strlen(s); i < len ; i ++) {
			if(s[i] == c) continue;
			ans[j ++] = s[i];
		}
		ans[j] = 0;
		printf("%s\n", ans);
	}
	return 0;	
}