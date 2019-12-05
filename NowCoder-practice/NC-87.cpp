#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int m[26] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
	char s[101];
	while(scanf("%s", s) != EOF) {
		int cnt = m[s[0] - 'a'];
		for(int i = 1, len = strlen(s) ; i < len ; i ++) {
			cnt += (m[s[i] - 'a']);
			if(m[s[i] - 'a'] - m[s[i-1] - 'a'] == s[i] - s[i-1]) {
				cnt += 2;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}