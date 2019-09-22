/*
	数字求和
*/
#include <stdio.h>
using namespace std;

int main(void) {
	int a[10];
	int n;
	while(scanf("%d", &n) != EOF) {
		int ans = 0;
		for(int i = 0 ; i < 5 ; i ++) {
			scanf("%d", &a[i]);
			if(a[i] < n) {
				ans += a[i];
			}
		}
		printf("%d", ans);
	}
	return 0;
}