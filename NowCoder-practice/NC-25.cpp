#include <bits/stdc++.h>
using namespace std;

struct S {
	int id;
	char name[100];
	char sex[10];
	int age;
} stu[50];

int main(void) {
	int m, n, q;
	while(scanf("%d", &m) != EOF) {
		while(m --) {
			scanf("%d", &n);
			for(int i = 0 ; i < n ; i ++) {
				scanf("%d%s%s%d", &stu[i].id, stu[i].name, stu[i].sex, &stu[i].age);
			}
			scanf("%d", &q);
			for(int i = 0 ; i < n ; i ++) {
				if(stu[i].id == q) {
					printf("%d %s %s %d\n", stu[i].id, stu[i].name, stu[i].sex, stu[i].age);
				}
			}
		}
	}

	return 0;
} 