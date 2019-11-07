#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int m;
	char str[100];
	int idx[100];
	while(scanf("%d", &m) != EOF) {
		while(m --) {
			scanf("%s", str);
			int p = 0;
			for(int i = 0 ,len = strlen(str); i < len ; i ++) {
				if(str[i] >= '0'  && str[i] <= '9') {
					idx[p ++] = i;
				}
			}
			for(int i = 0 ; i < p ; i ++) {
				printf("%d ", idx[i] + 1);
			}
			printf("\n");
		}
	}
	return 0;
}