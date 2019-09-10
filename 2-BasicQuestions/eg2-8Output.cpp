#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int buf[82][82];
	char a, b;
	int n;
	bool first = true;

	while(scanf("%d %c %c", &n, &a, &b) != EOF) {
		if(first) {
			first = false;
		}
		else {
			printf("\n");
		}

		for(int i = 1, j = 1; i <= n ; i += 2, j ++) {
			int x = n / 2 + 1 , y = x;
			x -= (j - 1);
			y -= (j - 1);
			char c = (j % 2 == 1) ? a : b;
			for(int k = 1; k <= i ; k ++) {
				buf[x + k - 1][y] = c;
				buf[x][y + k - 1] = c;
				buf[x + i - 1][y + k - 1] = c;
				buf[x + k - 1][y + i - 1] = c;
			}
		}

		if(n != 1) {
			buf[1][1] = ' ';
			buf[n][1] = ' ';
			buf[1][n] = ' ';
			buf[n][n] = ' ';
		}

		for(int i = 1 ; i <= n ; i ++) {
			for(int j = 1 ; j <= n ; j ++) {
				printf("%c", buf[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}