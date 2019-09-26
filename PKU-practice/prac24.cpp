/*
    买房子
*/
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, cnt;
    double k , p;
    bool flag = true;
    while(scanf("%d%lf", &n, &k) != EOF) {
        k /= 100;
        p = 200.0;
        cnt = 1;
        flag = true;
        while(cnt <= 21) {
            if(n * cnt >= p) {
                printf("%d\n", cnt);
                flag = false;
                break;
            }
            cnt ++;
            p *= (1 + k);
        }
        if(flag) {
            printf("Impossible\n");
        }
    }
    return 0;
}