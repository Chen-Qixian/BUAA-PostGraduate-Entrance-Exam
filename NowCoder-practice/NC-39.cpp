#include <bits/stdc++.h>
using namespace std;
typedef pair<char, vector<int> > PCV;
map<char, vector<int> > m;
vector<PCV> v;


// 对map按照value排序，注意此处用pair&的形式
bool cmp(PCV &a, PCV &b) {
	return a.second[0] < b.second[0];
}

int main(void) {
	char s[110];
	while(scanf("%s", s) != EOF) {
		m.clear();
		v.clear();
		for(int i = 0 , len = strlen(s); i < len ; i ++) {
			m[s[i]].push_back(i);
		}
		for(auto it = m.begin() ; it != m.end() ; it ++) {
			v.push_back(*it);
		}
		// 注意此处排序需要使用begin(),end()获取头尾位置
		sort(v.begin(), v.end() , cmp);
		for(auto it = v.begin() ; it != v.end() ; it ++) {
			vector<int> tmp = it->second;
			int len = tmp.size();
			if(len > 1) {
				printf("%c:%d", it->first, tmp[0]);
				for(int i = 1 ; i < len ; i ++) {
					printf(",%c:%d", it->first, tmp[i]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}