#include <bits/stdc++.h>
using namespace std;

char res[100];
char ret[100];


long long toDec(char* x, int m) {
	long long res = 0;
	// pow 的类型转换也要用 long long
	for(int i = strlen(x) - 1, j = 0; i >= 0 ; i --, j ++) {
		if(x[i] >= 'A') {
			res += (x[i] - 'A' + 10) * (long long)pow(m, j);
		}
		else {
			res += (x[i] - '0') * (long long)pow(m, j);
		}
	}
	return res;
}

void toDst(long long dec, int n) {
	int len = 0;
	while(dec) {
		int tmp = dec % n;
		if(tmp >= 10) {
			res[len ++] = (tmp - 10) + 'a';
		}
		else {
			res[len ++] = tmp + '0';
		}
		dec /= n;
	}
	for(int i = 0 ; i < len ; i ++) {
		ret[i] = res[len - i - 1];
	}
	ret[len] = 0;
}

int main(void) {
	char x[100];
	int m, n;
	while(scanf("%d", &m) != EOF) {
		scanf("%d%s", &n, x);
		long long dec = toDec(x, m);
		toDst(dec, n);
		printf("%s\n", ret);
	}
	return 0;
}