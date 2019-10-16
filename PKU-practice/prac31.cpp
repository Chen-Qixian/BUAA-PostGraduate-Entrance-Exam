/*
	false coin
*/
#include <bits/stdc++.h>
using namespace std;
#define N 1010

bool mark[N];

int main(void) {
	int n, k;
	while(scanf("%d%d", &n, &k) != EOF) {
		for(int i = 1 ; i <= n ; i ++) {
			mark[i] = true;
		}
		while(k --) {
			int tmp, w[N];
			char op;
			scanf("%d", &tmp);
			tmp *= 2;
			for(int i = 0 ; i < tmp ; i ++) {
				scanf("%d", &w[i]);
			}
			getchar();
			scanf("%c", &op);
			if(op == '=') {
				for(int i = 0 ; i < tmp ; i ++) {
					mark[w[i]] = false;
				}
			}
		}
		int cnt = 0;
		int id = 0;
		for(int i = 0 ; i < n ; i ++) {
			if(mark[i]){
				cnt ++;
				id = i;
			}
		}
		if(cnt > 1) {
			printf("0\n");
		}
		else {
			printf("%d\n", id);
		}
	}
	return 0;
}