/*
	Head of a Gang
	并查集的加强版，重点练习！
*/
#include <bits/stdc++.h>
#define SIZE 1010
using namespace std;

int sum[SIZE];
char namelist[SIZE][5];
int num = 0;

struct Person{
	char name[5];
	int parent;
	int weight;
} p[SIZE];

struct Gang{
	char head[5];
	int size;
	bool operator < (const Gang &a) const {
		int tmp = strcmp(head, a.head);
		return tmp < 0;
	}
} g[SIZE];

int findRoot(int x) {
	if(p[x].parent < 0) return x;
	int tmp = findRoot(p[x].parent);
	p[x].parent = tmp;
	return tmp;
}

int getId(char *s) {
	for(int i = 0; i < num ; i ++) {
		if(strcmp(s, namelist[i]) == 0){
			return i;
		}
	}
	strcpy(namelist[num ++], s);
	return num - 1;
}

int main(void) {
	int n, k;
	while(scanf("%d%d", &n, &k) != EOF) {
		char a[5], b[5];
		int time, x, y, ans;
		for(int i = 0 ; i < SIZE ; i ++) {
			p[i].parent = -1;
			p[i].weight = 0;
			g[i].size = 0;
			sum[i] = 0;
		}
		while(n --) {
			scanf("%s%s%d", a, b, &time);
			x = getId(a);
			y = getId(b);
			strcpy(p[x].name, a);
			strcpy(p[y].name, b);
			p[x].weight += time;
			p[y].weight += time;
			x = findRoot(x);
			y = findRoot(y);
			if(x != y) {
				p[x].parent += p[y].parent;
				p[y].parent = x;
				sum[x] += sum[y];
			}
			sum[x] += time;
		}
		ans = 0;
		for(int i = 0; i < num ; i ++) {
			if(p[i].parent < -2 && sum[i] > k){
				g[ans].size = -p[i].parent;
				int idx = i, _max = p[i].weight;
				for(int j = 0 ; j < num ; j ++) {
					if(findRoot(j) == i && p[j].weight > _max) {
						idx = j;
						_max = p[j].weight;
					}
				}
				strcpy(g[ans].head, p[idx].name); 
				ans ++;
			}
		}
		sort(g, g + ans);
		printf("%d\n", ans);
		for(int i = 0; i < ans ; i ++) {
			printf("%s %d\n", g[i].head, g[i].size);
		}
	}
	return 0;
}