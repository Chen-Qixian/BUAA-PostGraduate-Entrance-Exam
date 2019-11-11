#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b) {
	if(a.size() != b.size()) return a.size() < b.size();
	return a < b;
}

int main(void) {
	int n;
	while(cin >> n) {
		vector<string> v;
		while(n--) {
			string tmp;
			cin >> tmp;
			v.push_back(tmp);
		}
		sort(v.begin(), v.end() , cmp);
		for(int i = 0 ; i < v.size() ; i ++) {
			cout << v[i] << endl;
		}
	}
	return 0;
}