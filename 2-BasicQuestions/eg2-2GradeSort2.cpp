/*
使用重载运算符对struct排序
*/
#include <bits/stdc++.h>
#define SIZE 1100
using namespace std;


struct Student {
	char name[110];
	int age;
	int grade;
	bool operator < (const Student &a) const{
		if(grade != a.grade) return grade < a.grade;
		int tmp = strcmp(name, a.name);
		if(tmp != 0) return tmp < 0;
		else return age < a.age;
	}
}s[SIZE];



int main(void) {
	int n;
	while(scanf("%d", &n) != EOF) {
		for(int i = 0 ; i < n ; i ++) {
			scanf("%s%d%d", s[i].name, &s[i].age, &s[i].grade);
		}
		sort(s, s + n);
		for(int i = 0 ; i < n ; i ++) {
			printf("%s %d %d\n", s[i].name, s[i].age, s[i].grade);
		}
	}
	return 0;
}