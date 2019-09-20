/*
	最短路径
*/
#include <bits/stdc++.h>
#define N 110
#define SIZE 1010
#define L 100000
using namespace std;

struct bigInt {
	int digit[SIZE];
	int size;

	void init() {
		size = 0;
		for(int i = 0 ; i < SIZE ; i ++) {
			digit[i] = 0;
		}
	}

	void set(int x) {
		init();
		do {
			digit[size ++] = x % L;
			x /= L;
		} while(x != 0);
	}

	void output() {
		printf("%d\n", digit[0]);
	}

	bigInt operator * (int x) const {
		bigInt ret;
		int carry = 0;
		ret.init();
		for(int i = 0 ; i < size ; i ++) {
			int tmp = digit[i] * x + carry;
			carry = tmp / L;
			tmp %= L;
			ret.digit[ret.size ++] = tmp;
		}
		if(carry != 0) {
			ret.digit[ret.size ++] = carry;
		}
		return ret;
	}

	bigInt operator + (bigInt &x) const {
		bigInt ret;
		int carry = 0;
		ret.init();
		for(int i = 0 ; i < size || i < x.size ; i ++) {
			int tmp = digit[i] + x.digit[i] + carry;
			carry = tmp / L;
			tmp %= L;
			ret.digit[ret.size ++] = tmp;
		}
		if(carry != 0) {
			ret.digit[ret.size ++] = carry;
		}
		return ret;
	}

	bool operator < (bigInt &x) const {
		if(size != x.size) return size < x.size;
		for(int i = size - 1 ; i >= 0 ; i --) {
			if(digit[i] != x.digit[i]) return digit[i] < x.digit[i];
		}
		return false;
	}
} k, ans[N][N];


int main(void) {
	int n, m;
	int a, b;
	while(scanf("%d%d", &n, &m) != EOF) {
		k.set(1);
		for(int i = 0 ; i < n ; i ++) {
			for(int j = 0 ; j < n ; j ++) {
				ans[i][j].set(-1);
			}
			ans[i][i].set(0);
		}
		while(m --) {
			scanf("%d%d", &a, &b);
			ans[a][b] = ans[b][a] = k;
			k = k * 2;
		}
		for(int l = 0 ; l < n ; l ++) {
			for(int i = 0 ; i < n ; i ++) {
				for(int j = 0 ; j < n ; j ++) {
					if(ans[i][l].digit[0] == -1 || ans[l][j].digit[0] == -1) {
						continue;
					}
					if(ans[i][j].digit[0] == -1 || ans[i][l] + ans[l][j] < ans[i][j]) {
						ans[i][j] = ans[i][l] + ans[l][j];
					}
				}
			}
		}
		for(int i = 1 ; i < n ; i ++) {
			ans[0][i].output();
		}
	}
	return 0;
}















