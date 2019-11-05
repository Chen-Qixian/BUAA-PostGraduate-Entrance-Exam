/*
	注意存储用数据结构设计
	注意每个用例循环开始时需要清空map和set
*/
#include <bits/stdc++.h>
using namespace std;
#define N 110

int main(void) {
	int M,n;
	int a[N], b[N];
	map<int,map<int, int> > m;
	set<int> s;
	while(scanf("%d", &M) != EOF) {
		while(M --) {
			scanf("%d", &n);
			s.clear();
			m.clear();
			for(int i = 0 ; i < n ; i ++) {
				scanf("%d", &a[i]);
				s.insert(a[i]);
			}
			for(int i = 0 ; i < n ; i ++) {
				scanf("%d", &b[i]);
				if(m.find(b[i]) == m.end()) {
					map<int, int> t;
					for(auto it = s.begin() ; it != s.end() ; it ++) {
						t[*it] = 0;
					}
					m[b[i]] = t;
				}
				m[b[i]][a[i]] ++;
			}
			for(auto it = m.begin() ; it != m.end() ; it ++) {
				printf("%d={", it->first);
				map<int, int> t = it->second;
				bool flag = true;
				for(auto iter = t.begin() ; iter != t.end() ; iter ++) {
					if(flag) {
						flag = false;
						printf("%d=%d",iter->first,iter->second);
					}
					else {
						printf(",%d=%d",iter->first,iter->second);
					}
				}
				printf("}\n");
			}
		}
	}
	return 0;
}