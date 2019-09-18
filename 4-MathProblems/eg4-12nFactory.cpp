/*
	n的阶乘
	高精度整数运算
*/
#include <bits/stdc++.h>
#define SIZE 10000
using namespace std;

struct bigInt{
	int digit[SIZE];
	int size;

	void init() {
		size = 0;
		for(int i = 0 ; i < SIZE ; i ++) {
			digit[i] = 0;
		}
	}

	void set(int x) {
		init();
		digit[size ++] = x;
	}

	void output() {
		for(int i = size - 1 ; i >= 0 ; i --) {
			if(i != size - 1)
				printf("%04d", digit[i]);
			else
				printf("%d", digit[i]);
		}
		printf("\n");
	}

	bigInt operator * (int x) const {
		bigInt ret;
		ret.init();
		int carry = 0;
		for(int i = 0 ; i < size ; i ++) {
			int tmp = x * digit[i] + carry;
			carry = tmp / 10000;
			tmp %= 10000;
			ret.digit[ret.size ++] = tmp;
		}
		if(carry != 0) {
			ret.digit[ret.size ++] = carry;
		}
		return ret;
	}
}a;

int main(void) {
	int n;
	while(scanf("%d", &n) != EOF) {
		if(n == 0) printf("0\n");
		else if(n == 1) printf("1\n");
		else {
			a.set(1);
			for(int i = 1 ; i <= n ; i ++) {
				a = a * i;
			}
			a.output();
		}
	}
	return 0;
}
