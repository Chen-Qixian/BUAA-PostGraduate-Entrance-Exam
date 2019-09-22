/*
	字符串排序
*/
#include <bits/stdc++.h>
using namespace std;
#define N 50

bool cmp(char a, char b) {
	return a < b;
}

int main(void) {
	char s[N];
	while(scanf("%s", s) != EOF) {
		sort(s, s + strlen(s), cmp);
		printf("%s\n", s);
	}
	return 0;
}