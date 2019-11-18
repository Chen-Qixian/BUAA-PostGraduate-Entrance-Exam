#include <bits/stdc++.h>
using namespace std;
int m[6][6], tmp[4][4];
int op, len, x, y;

bool input() {
	for(int i = 0; i < 5; i ++) {
		for(int j = 0 ; j < 5 ; j ++) {
			if(scanf("%d", &m[i][j]) == EOF) return false;
		}
	}
	scanf("%d%d%d%d", &op, &len, &x, &y);
	return true;
}

void clockk() {
	for(int i = 0 ; i < len ; i ++) {
		for(int j = 0 ; j < len ; j ++) {
			tmp[i][j] = m[x + len - 2 - j][y - 1 + i];
		}
	}
}

void counterClock() {
	for(int i = 0 ; i < len ; i ++) {
		for(int j = 0 ; j < len ; j ++) {
			tmp[i][j] = m[j + x - 1][len - 2 - i + y];
		}
	}
}

void replace() {
	for(int i = 0 ; i < len ; i ++) {
		for(int j = 0 ; j < len ; j ++) {
			m[x + i - 1][y + j - 1] = tmp[i][j];
		}
	}
}




void output() {
	for(int i = 0 ; i < 5 ; i ++) {
		for(int j = 0 ; j < 5 ; j ++) {
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
}

int main(void) {
	while(true) {
		if(input() == false) break;
		if(op == 1) {
			clockk();
		}
		else {
			counterClock();
		}
		replace();
		output();
	}
	return 0;
}