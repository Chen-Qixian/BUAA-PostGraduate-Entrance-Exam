/*
	总结：对map进行排序
	1.对key进行排序：默认key生序，可通过map第三个参数自定义key排序方式
	2.对value进行排序：可关联一个vector，对该vector进行排序
*/
#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string,int>& a, pair<string,int>& b) {
	if(a.second != b.second) return a.second > b.second;
	return a.first < b.first;
}

int main(void) {
	char s[1100];
	map<string, int> m;
	vector<pair<string,int> > v;
	string tmp = "";
	while(gets(s)) {
		for(int i = 0, len = strlen(s) ; i < len ; i ++) {
			if(s[i] == ' ' || s[i] == ',' || s[i] == '.') {
				if(tmp == "") continue;
				if(m.find(tmp) == m.end()) {
					m[tmp] = 0;
				}
				m[tmp] ++;
				tmp = "";
			}
			else {
				string t(1,tolower(s[i]));
				tmp = tmp + t;
			}
		}

		for(auto it = m.begin() ; it != m.end() ; it ++) {
			v.push_back(*it);
		}

		sort(v.begin(), v.end() , cmp);

		for(auto it = v.begin() ; it != v.end() ; it ++) {
			cout << it->first << ":" << it->second << endl;
		}
	}
	return 0;
}