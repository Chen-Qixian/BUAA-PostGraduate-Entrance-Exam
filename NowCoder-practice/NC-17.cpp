#include <bits/stdc++.h>
using namespace std;

struct I {
	int ori;
	int trs;
	void reverse() {
		trs = 0;
		int tmp = ori;
		while(tmp) {
			trs *= 10;
			trs += (tmp % 10);
			tmp /= 10;
		}
	}
} arr[20];

int main(void) {
	int t, i;
	for(i = 0 ; i < 10 ; i ++) {
		scanf("%d", &t);
		if(t == 0) break;
		arr[i].ori = t;
		arr[i].reverse();
	}
	for(int j = 0 ; j < i ; j ++) {
		printf("%d %d\n", arr[j].ori, arr[j].trs);
	}
	return 0;	
}