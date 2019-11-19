#include <bits/stdc++.h>
using namespace std;

bool judge(int n) {
	if(n == 1) return false;
	int bound = (int) (sqrt(n) + 1);
	int t, q;
	for(int i = 2 ; i < bound ; i ++) {
		if(n % i == 0) {
			t = (int) (sqrt(i));
			if(t * t == i) {
				return true;
			}
			q = n / i;
			t = (int) (sqrt(q));
			if(t * t == q){
				return true;
			}
		}	
	}
	t = (int) sqrt(n);
	if(t * t == n) {
		return true;
	}
	return false;
}

int main(void) {
	int n;
	while(scanf("%d", &n) != EOF) {
		printf("%s\n", judge(n) ? "Yes" : "No");
	}
	return 0;
}