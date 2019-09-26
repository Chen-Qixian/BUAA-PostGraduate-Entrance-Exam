#include <bits/stdc++.h>
using namespace std;

int solve(int m, int n) {
    if(m == 0) return 1;
    if(n == 1) return 1;
    if(m < n) return solve(m, m);
    else return solve(m, n - 1) + solve(m - n, n);
}

int main(void) {
    int m, n;
    while(scanf("%d%d", &m, &n) != EOF) {
        printf("%d\n", solve(m, n));
    }
    return 0;
}