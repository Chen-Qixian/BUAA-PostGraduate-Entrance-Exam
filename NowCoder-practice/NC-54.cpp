#include <bits/stdc++.h>
using namespace std;

int main(void) {
	char s1[101], s2[101];
	char s[202];
	while(scanf("%s", s1) != EOF) {
		scanf("%s", s2);
		int l = strlen(s1), lim = l * 2;
		bool toggle = true;
		for(int i = 0 ; i < lim ; i ++) {
			if(toggle) {
				s[i] = s1[i/2];
			}
			else {
				s[i] = s2[l - 1 - i/2];
			}
			toggle = !toggle;
		}
		s[lim] = 0;
		printf("%s\n", s);
	}

	return 0;
}