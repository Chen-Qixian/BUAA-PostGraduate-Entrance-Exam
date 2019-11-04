#include <bits/stdc++.h>
using namespace std;

int main(void) {
	for(int i = 0 ; i <= 9 ; i ++) {
		for(int j = 0 ; j <= 9 ; j ++) {
			for(int k = 0 ; k <= 9 ; k ++) {
				if(i * 100 + j * 110 + k * 12 == 532) {
					printf("%d %d %d\n", i, j, k);
				} 
			}
		}
	}
	return 0;
}