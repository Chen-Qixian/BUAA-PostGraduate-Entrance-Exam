/*
	字符串排序
*/
#include <bits/stdc++.h>
using namespace std;
#define N 1000

char q[N];

void bubble() {
	int len = strlen(q);
	for(int i = 0 ; i < len - 1 ; i ++) {
		for(int j = len - 1 ; j > i ; j --) {
			char a = q[j], b = q[j - 1];
			if(a >= 'A' && a <= 'Z') a += 0x20;
			if(b >= 'A' && b <= 'Z') b += 0x20;
			if(a < b){
				char t = q[j];
				q[j] = q[j-1];
				q[j-1] = t;
			}
		}
	}
}

int main(void) {
	char str[N], ans[N];
	bool mark[N];
	while(gets(str)) {
		int len = strlen(str);
		for(int i = 0 ; i < len ; i ++) {
			mark[i] = false;
		}
		int j = 0;
		for(int i = 0 ; i < len ; i ++) {
			if(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z') {
				q[j ++] = str[i];
			}
			else {
				ans[i] = str[i];
				mark[i] = true;
			}
		}
		q[j] = 0;
		bubble();
		int l = 0;
		for(int i = 0 ; i < len ; i ++) {
			if(mark[i]) continue;
			ans[i] = q[l ++];
		}
		ans[len] = 0;
		printf("%s\n", ans);
	}
	return 0;
}