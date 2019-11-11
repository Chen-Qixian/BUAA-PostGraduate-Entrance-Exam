#include <bits/stdc++.h>
using namespace std;

struct S {
	int id;
	char name[11];
	int age;

	bool operator < (const S &a) const{
		if(age != a.age) return age < a.age;
		if(id != a.id) return id < a.id;
		return strcmp(name, a.name) < 0;
	}
}s[31];


int main(void) {
	int n;
	while(scanf("%d", &n) != EOF) {
		for(int i = 0 ; i < n ; i ++) {
			scanf("%d%s%d", &s[i].id, s[i].name, &s[i].age);
		}
		sort(s, s + n);
		int num = min(n, 3);
		for(int i = 0 ; i < num ; i ++) {
			printf("%d %s %d\n", s[i].id, s[i].name, s[i].age);
		}
	}
	return 0;
}