#include <bits/stdc++.h>
using namespace std;

int main(void) {
	char s[101];
	int res[8];
	while(scanf("%s", s) != EOF) {
		for(int i = 0 , len = strlen(s); i < len ; i ++) {
			int t = (int)s[i];
			// printf("%d", t);
			int sum = 0;
			for(int j = 7 ; j >= 1 ; j --) {
				res[j] = t % 2;
				t /= 2;
				sum += res[j];
			}
			res[0] = (sum & 1 == 1) ? 0 : 1;
			for(int k = 0 ; k < 8 ; k ++) {
				printf("%d", res[k]);
			} 
			printf("\n");
		}
	}
	return 0;
}