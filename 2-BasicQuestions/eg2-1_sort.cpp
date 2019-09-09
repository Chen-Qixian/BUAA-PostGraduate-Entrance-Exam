#include <bits/stdc++.h>
#define SIZE 110
using namespace std;

int main (void) {
    int n;
    int buf[SIZE];
    while(scanf("%d", &n) != EOF) {
        for(int i = 0 ; i < n ; i ++) {
            scanf("%d", &buf[i]);
        }
        sort(buf, buf + n);
        for(int i = 0 ; i < n ; i ++) {
            printf("%d ", buf[i]);
        }
        printf("\n");
    }
    return 0;
}