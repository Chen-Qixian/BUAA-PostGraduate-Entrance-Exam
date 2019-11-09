#include <bits/stdc++.h>
using namespace std;


struct N {
	string s;
	int t;
};

set<string> strs;
queue<N> Q;

bool isInSet(string s) {
	if(strs.find(s) == strs.end()) {
		strs.insert(s);
		return false;
	}
	return true;
}

bool isSolve(string s) {
	return s.find("2012", 0) != string::npos;
}

void BFS(int n) {
	while(!Q.empty()) {
		N now = Q.front();
		Q.pop();
		string tmp;
		for(int i = 0 ; i < n - 1 ; i ++) {
			tmp = now.s;
			swap(tmp[i], tmp[i+1]);
			if(isInSet(tmp)) continue;
			if(isSolve(tmp)) {
				cout << now.t + 1 << endl;
				return;
			}
			N newn;
			newn.s = tmp;
			newn.t = now.t + 1;
			Q.push(newn);
		}
	}
	cout << -1 << endl;
}

int main(void) {
	int n;
	string str;
	while(cin >> n) {
		strs.clear();
		while(!Q.empty()) Q.pop();
		cin >> str;
		if(isSolve(str)) {
			cout << 0 << endl;
		}
		else {
			strs.insert(str);
			N f;
			f.s = str;
			f.t = 0;
			Q.push(f);
			BFS(n);
		}
	}
	return 0;
}