/*
    神奇的口袋
*/
#include <bits/stdc++.h>
using namespace std;
#define N 40
int a[30];
int n;

int count(int c, int w) {
    if(w == 0) return 1;
    if(c == n || w < 0) return 0;
    return count(c + 1, w - a[c]) + count(c + 1, w);
} 

int main(void) {
    while(scanf("%d", &n) != EOF) {
        for(int i = 0 ; i < n ; i ++) {
            scanf("%d", &a[i]);
        }
        printf("%d\n", count(0, 40));
    } 
    return 0;
}