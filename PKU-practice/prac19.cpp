/*
    与7无关的数
*/
#include <bits/stdc++.h>
using namespace std;
int buf[101];

bool judge(int x) {
    if(x % 7 == 0) return false;
    while(x) {
        if(x % 10 == 7) return false;
        x /= 10;
    }
    return true;
}

void init() {
    for(int i = 0 ; i < 100 ; i ++) {
        buf[i] = 0;
    }
    for(int i = 1 ; i < 100 ; i ++) {
        if(judge(i)) {
            buf[i] = buf[i - 1] + i * i;
        }
        else {
            buf[i] = buf[i - 1];
        }
    }
}


int main(void) {
    int n;
    init();
    while(scanf("%d", &n) != EOF) {
        printf("%d\n", buf[n]);
    }
    return 0;
}