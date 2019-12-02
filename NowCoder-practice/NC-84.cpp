#include <bits/stdc++.h>
using namespace std;

struct S {
	char name[20];
	int mark;
} stu[1100], tmp;

int n;

void sortstu(int way) {
	for(int i = 0 ; i < n - 1 ; i ++) {
		for(int j = n - 1 ; j > i ; j --) {
			if(way == 1) {
				if(stu[j].mark < stu[j-1].mark) {
					tmp = stu[j];
					stu[j] = stu[j-1];
					stu[j-1] = tmp;
				}
			}
			else {
				if(stu[j].mark > stu[j-1].mark) {
					tmp = stu[j];
					stu[j] = stu[j-1];
					stu[j-1] = tmp;
				}
			}
		}
	}
}

int main(void) {
	int way;
	while(scanf("%d", &n) != EOF) {
		scanf("%d", &way);
		for(int i = 0 ; i < n ; i ++) {
			scanf("%s%d", stu[i].name, &stu[i].mark);
		}
		sortstu(way);
		for(int i = 0 ; i < n ; i ++) {
			printf("%s %d\n", stu[i].name, stu[i].mark);
		}
	}
	return 0;
}