/*
	字符串内排序
*/
#include <bits/stdc++.h>
#define SIZE 220
using namespace std;

char buf[SIZE];

bool cmp(char a, char b) {
	return a < b;
}

int main(void) {
	char c;
	int len = 0;
	memset(buf, 0 , sizeof(buf));
	scanf("%c", &c);
	while(c != '\n'){
		buf[len ++] = c;
		scanf("%c", &c);
	}
	sort(buf, buf + len, cmp);
	buf[len] = '\0';
	printf("%s", buf);
	return 0;
}