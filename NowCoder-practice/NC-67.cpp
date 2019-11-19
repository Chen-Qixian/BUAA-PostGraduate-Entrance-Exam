#include <bits/stdc++.h>
using namespace std;
#define N 10

int a[N][N], b[N][N];
int n;

bool is0(){
	bool flag = true;
	for(int i = 0 ; i < n ; i ++) {
		for(int j = 0 ; j < n ; j ++) {
			if(a[i][j] != b[i][j]){
				flag = false;
				break;
			}
		}
		if(!flag) {
			break;
		}
	}
	return flag;
}

bool is90() {
	bool flag = true;
	for(int i = 0 ; i < n ; i ++) {
		for(int j = 0 ; j < n ; j ++) {
			if(a[i][j] != b[j][n-1-i]){
				flag = false;
				break;
			}
		}
		if(!flag){
			break;
		}
	}
	return flag;
}

bool is180() {
	bool flag = true;
	for(int i = 0 ; i < n ; i ++) {
		for(int j = 0 ; j < n ; j ++) {
			if(a[i][j] != b[n-1-i][n-1-j]){
				flag = false;
				break;
			}
		}
		if(!flag) break;
	}
	return flag;
}

bool is270() {
	bool flag = true;
	for(int i = 0 ; i < n ; i ++) {
		for(int j = 0 ; j < n ; j ++) {
			if(a[i][j] != b[n-1-j][i]) {
				flag = false;
				break;
			}
		}
		if(!flag){
			break;
		}
	}
	return flag;
}

int main(void) {
	while(scanf("%d", &n) != EOF) {
		for(int i = 0 ; i < n ; i ++) {
			for(int j = 0 ; j < n ; j ++) {
				scanf("%d", &a[i][j]);
			}
		}
		for(int i = 0 ; i < n ; i ++) {
			for(int j = 0 ; j < n ; j ++) {
				scanf("%d", &b[i][j]);
			}
		}
		if(is0()){
			printf("0\n");
		}	
		else if(is90()) {
			printf("90\n");
		}
		else if(is180()) {
			printf("180\n");
		}
		else if(is270()) {
			printf("270\n");
		}
		else {
			printf("-1");
		}
	}
	return 0;
}