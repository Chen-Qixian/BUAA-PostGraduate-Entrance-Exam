#include <bits/stdc++.h>
using namespace std;

void MyStrcat(char *a, char *b) {
    int total = strlen(a) + strlen(b);
	for(int i = strlen(a), j = 0, len = strlen(b) ; j < len ; i ++, j ++) {
		a[i] = b[j];
	}
	a[total] = 0;
}

int main(void) {
	char a[1000], b[1000];
	while(scanf("%s%s", a, b) != EOF) {
		MyStrcat(a, b);
		printf("%s\n", a);
	}
	return 0;
}