/*
	大整数因子
*/
#include <bits/stdc++.h>
using namespace std;

struct bigInt{
	int digit[10];
	int size;

	void init() {
		for(int i = 0 ; i < 10 ; i ++) {
			digit[i] = 0;
		}
		size = 0;
	}

	void set(char s[]) {
		init();
		for(int i = strlen(s) - 1 , t = 0 , j = 0 , c = 1 ; i >= 0 ; i --) {
			t += (s[i] - '0') * c;
			j ++;
			c *= 10;
			if(i == 0 || j == 4) {
				digit[size ++] = t;
				j = 0;
				t = 0;
				c = 1;
			}
		}
	}

	int operator % (int x) const {
		int r = 0;
		for(int i = size - 1; i >= 0; i --) {
			r = (r * 10000 + digit[i]) % x;
		}
		return r;
	}
} c;

int main(void) {
	char s[50];
	while(scanf("%s", s) != EOF) {
		c.set(s);
		bool flag = true;
		for(int i = 2 ; i <= 9 ; i ++) {
			if(c % i == 0) {
				printf("%d ", i);
				flag = false;
			}
		}
		if(flag){
			printf("none");
		}
		printf("\n");
	}
	
	return 0;
}