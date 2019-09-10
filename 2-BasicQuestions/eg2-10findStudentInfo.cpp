/*
	查找学生信息
*/
#include <bits/stdc++.h>
using namespace std;

struct E {
	int no;
	char name[100];
	char sex[10];
	int age;
	bool operator< (const E &a) const{
		return no < a.no;
	}
} s[1100];

int main(void) {
	int n, m;
	int dst;
	bool flag;
	while(scanf("%d", &n) != EOF) {
		for(int i = 0 ; i < n ; i ++) {
			scanf("%d%s%s%d", &s[i].no, s[i].name, s[i].sex, &s[i].age);
		}
		sort(s , s + n);
		scanf("%d", &m);
		while(m --) {
			flag = false;
			scanf("%d", &dst);
			int left = 0, right = n - 1, mid = left + (right - left) / 2;
			while(left <= right) {
				if(dst == s[mid].no) {
					flag = true;
					printf("%d %s %s %d\n", s[mid].no, s[mid].name, s[mid].sex, s[mid].age);
					break;
				}
				else if(dst > s[mid].no) {
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
				mid = left + (right - left) / 2;
			}
			if(!flag){
				printf("No Answer!\n");
			}
		}
	}
	return 0;
}