#include <bits/stdc++.h>
using namespace std;

bool judge(char *s) {
	regex reg("^\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}$");
	int a, b, c, d;
	if(regex_match(s, reg)) {
		sscanf(s, "%d.%d.%d.%d", &a, &b, &c, &d);
		if(a > 255 || a < 0 || b > 255 || b < 0 || c > 255 || c < 0 || d > 255 || d < 0) {
			return false;
		}
	}
	else {
		return false;
	}
	return true;
}

int main(void) {
	char ip[100];
	while(scanf("%s", ip) != EOF) {
		if(judge(ip)) {
			printf("Yes!\n");
		}
		else {
			printf("No!\n");
		}
	}
	return 0;
}