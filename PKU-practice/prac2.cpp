/*
	加减乘除
*/
#include <bits/stdc++.h>
using namespace std;

int fac(int a) {
	if(a == 1) return 1;
	return a * fac(a - 1);
}

int main(void) {
	int a, b;
	char op;
	while(scanf("%d %c", &a, &op) != EOF) {
		int ans = 0;
		bool flag = true;
		if(op != '!') {
			scanf("%d", &b);
			switch(op) {
				case '+' :{
					ans = a + b;
					break;
				}
				case '-' :{
					ans = a - b;
					break;
				}
				case '*' :{
					ans = a * b;
					break;
				}
				case '/' :{
					if(b == 0){
						flag = false;
					}
					else {
						ans = a / b;
					}
					break;
				}
				case '%' :{
					if(b == 0) {
						flag = false;
					}
					else {
						ans = a % b;
					}
					break;
				}
			}
		}
		else {
			ans = fac(a);
		}
		if(flag) {
			printf("%d\n", ans);
		}
		else {
			printf("error\n");
		}
	}
	return 0;
}