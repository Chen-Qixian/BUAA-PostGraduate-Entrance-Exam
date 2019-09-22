/*
	浮点数加法
*/
#include <bits/stdc++.h>
using namespace std;
#define N 10000

char a1[N], b1[N], ans[N];
string a, b;

void adjust() {
	int p1, p2;
	for(int i = 0 ; i < a.size() ;i ++) {
		if(a[i] == '.'){
			p1 = i;
			break;
		}
	}
	for(int i = 0 ; i < b.size() ; i ++) {
		if(b[i] == '.'){
			p2 = i;
			break;
		}
	}
	if(p1 > p2) {
		for(int i = 0 ; i < p1 - p2 ; i ++){
			b = "0" + b;
		}
	}
	else {
		for(int i = 0 ; i < p2 - p1 ; i ++) {
			a = "0" + a;
		}
	}
	p1 = a.size();
	p2 = b.size();
	if(p1 > p2) {
		for(int i = 0 ; i < p1 - p2 ; i ++) {
			b = b + "0";
		}
	}
	else {
		for(int i = 0 ; i < p2 - p1 ; i ++) {
			a = a + "0";
		}
	}
}

int main(void) {
	while(scanf("%s%s", a1, b1) != EOF) {
		a = a1;
		b = b1;
		adjust();
		int len = a.size();
		int carry = 0;
		int j = 0; 
		for(int i = len - 1; i >= 0 ; i --, j ++) {
			if(a[i] == '.'){
				ans[j] = '.';
				continue;
			}
			int tmp = (a[i] - '0') + (b[i] - '0') + carry;
			carry = tmp / 10;
			tmp %= 10;
			ans[j] = tmp + '0'; 
		}
		if(carry != 0) {
			ans[j ++] = carry;
		}
		for(int i = j - 1 ; i >= 0 ; i --) {
			printf("%c",ans[i]);
		}
		printf("\n");
	}
	return 0;
}