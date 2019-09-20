/*
	全排列
*/
#include <bits/stdc++.h>
using namespace std;

int num[10];
bool mark[10];
int n;
char ori[10];

bool cmp(char a, char b) {
	return a < b;
}

void perm(int k) {
	if(k == n) {
		for(int i = 0 ; i < n ; i ++) {
			// printf("%d", num[i]);
			printf("%c", ori[num[i]]);
		}
		printf("\n");
		return;
	}
	for(int i = 0 ; i < n ; i ++) {
		if(mark[i]) continue;
		num[k] = i;
		mark[i] = true;
		perm(k + 1);
		mark[i] = false;
	}
}


int main(void) {
	while(scanf("%s", ori) != EOF) {
		n = strlen(ori);
		for(int i = 0 ; i < n ; i ++) {
			mark[i] = false;
			num[i] = 0;
		}
		sort(ori, ori + n, cmp);
		perm(0);
		printf("\n");
	}
	return 0;
}