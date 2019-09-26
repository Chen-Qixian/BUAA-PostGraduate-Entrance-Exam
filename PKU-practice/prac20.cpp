/*
    位操作练习
*/
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    unsigned short m, n;
    while(scanf("%d%d", &m, &n) != EOF) {
        for(int i = 0 ; i < 16 ; i ++) {
            if(m == n) {
                printf("YES\n");
                break;
            }
            if(i == 15) {
                printf("NO\n");
                break;
            }
            else {
                m = m << 1 | (m >> 15 & 1);
            }
        }
    }
    return 0;
}