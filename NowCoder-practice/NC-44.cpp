/*
	未通过：
	第二题
*/
#include <bits/stdc++.h>
using namespace std;

int str2int(char *s) {
	int ret = 0;
	for(int i = 0, len = strlen(s) ; i < len ; i ++) {
		ret *= 10;
		ret += s[i] - '0';
	}
	return ret;
}

bool isLegal(char *s) {
	// printf("$$$$%s\n", s);
	for(int i = 0 , len = strlen(s) ; i < len ; i ++) {
		if(s[i] >'9' || s[i] < '0') {
			// printf("####%c\n", s[i]);
			return false;
		}
	}
	return true;
}

int main(void) {
	char str[10010], tmp[20];
	while(gets(str)) {
		int j = 0, k = 0;
		bool flag = true;
		int a[100];
		int sum = 0;
		for(int i = 0 , len = strlen(str) ; i < len ; i ++) {
			if(str[i] == ' ') {
				tmp[j] = 0;
				if(isLegal(tmp)) {
					a[k] = str2int(tmp);
					sum += a[k ++];
				}
				else {
					flag = false;
					break;
				}
				j = 0;
			}
			else {
				tmp[j ++] = str[i];
			}
		}
		tmp[j] = 0;
		if(isLegal(tmp)) {
			a[k] = str2int(tmp);
			sum += a[k ++];
		}
		else {
			flag = false;
		}
		if(flag) {
			sort(a, a + k);
			int total = 0;
			bool even = true;
			int tmp1, tmp2;
			for(int i = 0; i < k ; i ++) {
				int ptr = i / 2;
				if(even) {
					// printf("a[i]=%d,total=%d\n", a[ptr], total);
					total += a[ptr];
				}
				else {
					// printf("a[k-i-1]=%d,total=%d\n", a[k-ptr-1], total);
					total += a[k - ptr - 1];
				}
				if(total >= sum / 2) {
					tmp1 = total;
					break;
				}
				even = !even;
			}
			even = false;
			for(int i = 0; i < k ; i ++) {
				int ptr = i / 2;
				if(even) {
					// printf("a[i]=%d,total=%d\n", a[ptr], total);
					total += a[ptr];
				}
				else {
					// printf("a[k-i-1]=%d,total=%d\n", a[k-ptr-1], total);
					total += a[k - ptr - 1];
				}
				if(total >= sum / 2) {
					tmp2 = total;
					break;
				}
				even = !even;
			}
			int res = min(tmp1, tmp2);
			printf("%d %d\n", res, sum - res);
		}
		else {
			printf("ERROR\n");
		}
		
	}
	return 0;
}