/*
    首字母大写
*/
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    char s[110];
    while(gets(s)) {
        int len = strlen(s);
        bool flag = true;
        for(int i = 0 ; i < len ; i ++) {
            if(s[i] == ' ' || s[i] == '\t' || s[i] == '\r' || s[i] == '\n') {
                flag = true;
                continue;
            }
            if(flag) {
                flag = false;
                if(s[i] >= 'a' && s[i] <= 'z')  {
                    s[i] -= 0x20;
                }
            }
        }
        printf("%s\n", s);
    }
    return 0;
}