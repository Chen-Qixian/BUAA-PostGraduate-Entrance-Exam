/*
	注意用struct实现链表结构体中指针的使用
*/ 
#include <bits/stdc++.h>
using namespace std;

struct E {
	int num;
	E* link;
} e[60];

int main(void) {
	int m, n;
	vector<int> v;
	while(scanf("%d", &m) != EOF) {
		while(m --) {
			scanf("%d", &n);
			for(int i = 1 ; i <= n ; i ++) {
				e[i].num = i;
				e[i].link = &e[i + 1];
			}
			e[n].link = &e[1];
			int cnt = 1;
			int ans = 0;
			E *r = &e[n];
			E *tmp = &e[1];
			while(ans < n) {
				if(cnt == 3) {
					cnt = 1;
					printf("%d ", tmp->num);
					r->link = tmp->link;
					tmp = tmp->link;
					ans ++;
				}
				else {
					r = tmp;
					tmp = tmp -> link;
					cnt ++;
				}
			}
			printf("\n");
		}
	}
	return 0;
}