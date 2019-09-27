/*
	坠落的蚂蚁
*/
#include <bits/stdc++.h>
using namespace std;
int n, ptr, A, _time;
bool flag;

struct Ant {
	int pos;
	int dir;
} ant[100];


int main(void) {
	while(scanf("%d", &n) != EOF) {
		flag = true;
		_time = 0;
		int q[210];
		bool e[210];
		for(int i = 0 ; i <= 200 ; i ++) {
			q[i] = 0;
		}
		for(ptr = 0 ; ptr < n ; ptr ++) {
			scanf("%d%d", &ant[ptr].pos, &ant[ptr].dir);
			ant[ptr].pos *= 2;
			if(ant[ptr].dir == 0) {
				A = ptr;
			}
			q[ant[ptr].pos] ++;
			e[ptr] = false;
		}
		while(n > 1) {
			for(int i = 0 ; i < ptr ; i ++) {
				if(e[i]) continue;
				q[ant[i].pos] --;
				ant[i].pos += ant[i].dir;
				if(ant[i].pos == 0 || ant[i].pos == 200) {
					n --;
					e[i] = true;
					if(i == A) {
						flag = false;
						break;
					}
				}
				q[ant[i].pos] ++;
			}
			if(!flag) break;
			for(int i = 0 ; i <= 200 ; i ++) {
				if(q[i] > 1) {
					vector<int> tmp;
					tmp.clear();
					for(int j = 0 ; j < ptr ; j ++) {
						if(ant[j].pos == i) {
							tmp.push_back(j);
						}
					}
					if(tmp.size() == 2) {
						int tmpdir = ant[tmp[0]].dir;
						ant[tmp[0]].dir = ant[tmp[1]].dir;
						ant[tmp[1]].dir = tmpdir;
					}
					else if(tmp.size() == 3) {
						for(int i = 0 ; i < 3 ; i ++)
							ant[tmp[i]].dir = -ant[tmp[i]].dir;
					}
				}
			}
			_time ++;
		}
		if(flag) {
			if(ant[A].dir == 0) {
				printf("Cannot fall!\n");
			}
			else if(ant[A].dir == 1){
				_time += (200 - ant[A].pos);
				printf("%d\n", _time / 2);
			}
			else {
				_time += ant[A].pos;
				printf("%d\n", _time / 2);
			}

		}	
		else {
			printf("%d\n", (_time + 1)/ 2);
		}
	}
	return 0;
}