/*
	日志排序
	学习sscanf
*/
#include <bits/stdc++.h>
using namespace std;
#define N 10001

struct T {
	char row[100];
	char name[20];
	char date[20];
	char time[20];
	double t;
	bool operator < (const T &a) const {
		if(t != a.t) return t < a.t;
		if(strcmp(date, a.date) != 0) return strcmp(date, a.date) < 0;
		return strcmp(time, a.time) < 0;
	}
} task[N];

int num = 0;

int main(void) {
	while(gets(task[num].row)) {
		if(strcmp(task[num].row, "") == 0) break;
		sscanf(task[num].row, "%s%s%s%lf(s)", task[num].name, task[num].date, task[num].time, &task[num].t);
		num ++;
	}
	sort(task, task + num);
	for(int i = 0 ; i < num ; i ++) {
		printf("%s\n", task[i].row);
	}
	return 0;
}