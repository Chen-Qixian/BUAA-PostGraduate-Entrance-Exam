#include <bits/stdc++.h>
using namespace std;
#define L 4
#define R 5

int m[10][10]; 

int main(void) {
	bool stop = false;
	int t[5];
	int res[10][10];
	while(true) {
		for(int i = 0 ; i < L ; i ++) {
			for(int j = 0 ; j < R ; j ++ ){
				if(scanf("%d", &m[i][j]) == EOF) {
					stop = true;
					break;
				}
			}
			if(stop) {
				break;
			}
		}
		if(stop) break;
		for(int i = 0 ; i < R ; i ++) {
			int k = 0;
			for(int j = 0 ; j < L ; j ++) {
				t[k ++] = m[j][i];
			}
			sort(t, t + k);
			k = 0;
			bool flag = true;
			for(int j = 0 ; j < L ; j ++) {
				if(m[j][i] == t[3]) {
					res[k ++][i] = m[j][i];
				}
				else if(m[j][i] == t[2] && flag) {
					
					res[k ++][i] = m[j][i];
					flag = false;
				}
			}
		}
		for(int i = 0 ; i < 2 ; i ++) {
			for(int j = 0 ; j < R ; j ++) {
				printf("%d ", res[i][j]);
			}
			printf("\n");
		}
	} 
	return 0;
}