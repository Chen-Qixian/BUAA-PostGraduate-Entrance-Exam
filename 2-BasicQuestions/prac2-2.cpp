#include <bits/stdc++.h>
#define SIZE 100010
using namespace std;

struct E {
	char no[10];
	char name[10];
	int grade;
} s[SIZE];

bool cmp1(E a, E b) {
	return strcmp(a.no, b.no) < 0;
}

bool cmp2(E a, E b) {
	if(strcmp(a.name, b.name) == 0){
		return strcmp(a.no, b.no) < 0;
	}
	return strcmp(a.name, b.name) < 0;
}

bool cmp3(E a, E b) {
	if(a.grade == b.grade) {
		return strcmp(a.no, b.no) < 0;
	}
	return a.grade < b.grade;
}

int main(void) {
	int n , c;
	while(scanf("%d", &n) != EOF) {
		if(n == 0) break;
		scanf("%d", &c);
		for(int i = 0 ; i < n ; i ++) {
			scanf("%s%s%d", s[i].no, s[i].name, &s[i].grade);
		}
		switch(c){
			case 1:{
				sort(s, s + n, cmp1);
				break;
			}
			case 2:{
				sort(s, s + n, cmp2);
				break;
			}
			case 3:{
				sort(s, s + n, cmp3);
				break;
			}
		}
		printf("Case:\n");
		for(int i = 0; i < n ; i ++) {
			printf("%s %s %d\n", s[i].no, s[i].name, s[i].grade);
		}
	}
	return 0;
}