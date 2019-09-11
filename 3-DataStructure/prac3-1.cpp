/*
	堆栈的使用
*/
#include <bits/stdc++.h>
using namespace std;

stack<int> s;

int main(void) {
	int n, x;
	char c;
	while(scanf("%d" , &n) != EOF) {
		if(n == 0) break;
		while(!s.empty()) s.pop();
		for(int i = 0 ; i < n ; i ++) {
			getchar();
			scanf("%c" , &c);
			switch(c) {
				case 'P':{
					scanf("%d", &x);
					s.push(x);
					break;
				}
				case 'O':{
					if(!s.empty()){
						s.pop();
					}
					break;
				}
				case 'A':{
					if(s.empty()){
						printf("E\n");
					}
					else{
						printf("%d\n", s.top());
					}
					break;
				}
			}
		}
		printf("\n");
	}
	return 0;
}