/*
	2018-1-G
*/
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n;
	int a[1100];
	stack<int> s;
	while(scanf("%d", &n) != EOF) {
		if(n == 0) break;
		while(true) {
			scanf("%d", &a[0]);
			if(a[0] == 0) {
				printf("\n");
				break;
			}
			while(s.empty() == false) s.pop();
			for(int i = 1 ; i < n ; i ++) {
				scanf("%d", &a[i]);
			}
			int cnt = 1;
			bool flag = true;
			for(int i = 0 ; i < n ; i ++) {
				while(cnt <= a[i]) {
					s.push(cnt ++);
				}
				if(s.top() == a[i]) {
					s.pop();
				}
				else {
					flag = false;
					break;
				}
			}
			if(flag) {
				printf("Yes\n");
			}
			else {
				printf("No\n");
			}
		}
 	}
	return 0;
}