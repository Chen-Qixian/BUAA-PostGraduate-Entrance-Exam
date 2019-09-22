/*
	字符串排序
*/
#include <bits/stdc++.h>
using namespace std;
#define N 110

bool cmp(string a, string b) {
	return a.size() < b.size();
}

int main(void) {
	int n;
	while(scanf("%d", &n) != EOF) {
		string s[n];
		char str[N];
		getchar();
		for(int i = 0 ; i < n ; i ++) {
			gets(str);
			s[i] = str;
			if(s[i] == "stop") {
				n = i;
				break;
			}
		}
		sort(s, s + n, cmp);
		for(int i = 0 ; i < n ; i ++) {
			cout << s[i] << endl;
		}
	}	
	return 0;
}