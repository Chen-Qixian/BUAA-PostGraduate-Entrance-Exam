/*
    abc
*/
#include <stdio.h>
using namespace std;

int main(void) {
    for(int i = 0 ; i < 10 ; i ++) {
        for(int j = 0 ; j < 10 ; j ++) {
            for(int k = 0 ; k < 10 ; k ++) {
                if(i * 100 + j * 10 + k + j * 100 + k * 11 == 532) {
                    printf("%d %d %d\n", i, j, k);
                }
            }
        }
    }
    return 0;
}