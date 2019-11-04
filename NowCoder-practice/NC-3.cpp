#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int a[10], b[10];
	for(int i = 1000 ; i <= 1500 ; i ++) {
		int n = i, n9 = i * 9, cnt = 0;
		while(n) {
			a[cnt] = n % 10;
			b[cnt ++] = n9 % 10;
			n /= 10;
			n9 /= 10;
		}
		bool flag = true;
		for(int j = 0 ; j < 4 ; j ++) {
			if(a[j] != b[3 - j]) {
				flag = false;
				break;
			}
		}
		if(flag){
			printf("%d\n", i);
		}
	}
	return 0;
}