/*
	2018-1-B
*/
#include <bits/stdc++.h>
#define N 110
using namespace std;

int main(void) {
	char src[N], dst[N], str[N];
	map<char, char> m;
	while(scanf("%s", src) != EOF) {
		scanf("%s%s", dst, str);
		int len = strlen(src);
		m.clear();
		bool flag = false;
		int cnt = 0;
		for(int i = 0 ; i < len ; i ++) {
			if(m.find(src[i]) == m.end()) {
				m[src[i]] = dst[i];
				cnt ++;
			}
			else {
				if(m[src[i]] != dst[i]){
					flag = true;
					break;
				}
			}
		}
		if(flag || cnt != 26){
			printf("Failed\n");
			continue;
		}
		else {
			for(int i = 0 ; str[i] != 0 ; i ++) {
				printf("%c",m[str[i]]);
			}
			printf("\n");
		}
	}
	return 0;
}