/*
    skew 数
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
    char s[100];
    while(scanf("%s", s) != EOF) {
        int len = strlen(s);
        int ans = 0;
        for(int i = len - 1 , j = 1; i >= 0 ; i --, j ++) {
            ans += (s[i] -'0') * (pow(2, j) - 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}