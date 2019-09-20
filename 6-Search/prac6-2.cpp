/*
    Old bill
*/
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    int x, y ,z;
    while(scanf("%d", &n) != EOF) {
        scanf("%d%d%d", &x, &y, &z);
        int num = x * 1000 + y * 100 + z * 10;
        int cur;
        bool flag = true;
        for(int i = 9 ; i >= 1 ; i --) {
            for(int j = 9 ; j >= 0 ; j --) {
                cur = num + i * 10000 + j;
                if(cur % n == 0){
                    printf("%d %d %d\n", i, j, cur / n);
                    flag = false;
                    break;
                }
            }
            if(!flag) {
                break;
            }
        }
        if(flag) {
            printf("0\n");
        }
    }
    return 0;
}