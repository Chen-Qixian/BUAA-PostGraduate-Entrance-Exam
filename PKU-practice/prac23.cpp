/*
    学分绩点
*/
#include <bits/stdc++.h>
using namespace std;

double getGPA(int x) {
    if(x >= 90 && x <= 100) return 4.0;
    if(x >= 85 && x <= 89) return 3.7;
    if(x >= 82 && x <= 84) return 3.3;
    if(x >= 78 && x <= 81) return 3.0;
    if(x >= 75 && x <= 77) return 2.7;
    if(x >= 72 && x <= 74) return 2.3;
    if(x >= 68 && x <= 71) return 2.0;
    if(x >= 64 && x <= 67) return 1.5;
    if(x >= 60 && x <= 63) return 1.0;
    return 0.0;
}

int main(void) {
    int n, x;
    double a[20], b[20], p, q;
    while(scanf("%d", &n) != EOF) {
        p = 0.0;
        q = 0.0;
        for(int i = 0 ; i < n ; i ++) {
            scanf("%lf", &a[i]);
            q += a[i];
        }
        for(int i = 0 ; i < n ; i ++) {
            scanf("%d", &x);
            p += (getGPA(x) * a[i]);
        }
        printf("%.2lf\n", p / q);
    }
    return 0;
}