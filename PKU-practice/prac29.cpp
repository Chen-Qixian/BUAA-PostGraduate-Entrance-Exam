/*
	子串计算
*/
#include <bits/stdc++.h>
using namespace std; 

int main(void) {
	map<string, int> mp;
	string s;
	while(cin >> s) {
		for(int i = 0 ; i <= s.size() ; i ++) {
			for(int j = 0 ; j < i ; j ++) {
				mp[s.substr(j, i-j)] ++;
			}
		}
		for(auto it = mp.begin() ; it != mp.end() ; it ++) {
			if(it -> second > 1) {
				cout << it->first << ' ' << it->second << endl;
			}
		}
	}
	return 0;
}