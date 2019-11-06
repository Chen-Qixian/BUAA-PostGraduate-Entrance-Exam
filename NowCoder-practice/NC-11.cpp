#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int m;
	string t;
	vector<string> v;
	v.clear();
	cin >> m;
	while(m --) {
		cin >> t;
		v.push_back(t);
		int len = v.size();
		if(len > 4) {
			for(int i = len - 1, j = 1 ; j <= 4 ; i --, j ++) {
				cout << j << "=" << v[i] << " ";
			}
		}
		else {
			for(int i = len - 1, j = 1 ; i >= 0 ; i-- , j ++) {
				cout << j << "=" << v[i] << " ";
			}
		}
		cout << endl;
	}
	return 0;
}