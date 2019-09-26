/*
    二叉树
*/
#include <bits/stdc++.h>
using namespace std;

int solve(int x, int y) {
    if(x == y) return x;
    if(x > y) {
        return solve(x / 2, y);
    }
    return solve(x, y / 2);
}

int main(void) {
    int x, y;
    while(scanf("%d%d", &x, &y) != EOF) {
        printf("%d\n", solve(x, y));
    }
    return 0;
}