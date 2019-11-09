#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int _min = INT_MAX, _max = 0;
	vector<string> v[10010];
	char s[1001];
	while(gets(s)) {
		string t = s;
		int len = t.size();
		_max = max(_max, len);
		_min = min(_min, len);
		v[len].push_back(t);
	}
	for(int i = 0 , len = v[_min].size() ; i < len ; i ++) {
		cout << v[_min][i] << endl;
	}
	for(int i = 0 , len = v[_max].size() ; i < len ; i ++) {
		cout << v[_max][i] << endl;
	}
	return 0;
}