/*
	成绩排序
*/

#include <bits/stdc++.h>
#define SIZE 1100
using namespace std;


struct Student {
	char name[110];
	int age;
	int grade;
}s[SIZE];

bool cmp(Student a, Student b) {
	if(a.grade != b.grade) return a.grade < b.grade;
	int tmp = strcmp(a.name, b.name);
	if(tmp != 0) return (tmp < 0);
	else return a.age < b.age;
}

int main(void) {
	int n;
	while(scanf("%d", &n) != EOF) {
		for(int i = 0 ; i < n ; i ++) {
			scanf("%s%d%d", s[i].name, &s[i].age, &s[i].grade);
		}
		sort(s, s + n, cmp);
		for(int i = 0 ; i < n ; i ++) {
			printf("%s %d %d\n", s[i].name, s[i].age, s[i].grade);
		}
	}
	return 0;
}