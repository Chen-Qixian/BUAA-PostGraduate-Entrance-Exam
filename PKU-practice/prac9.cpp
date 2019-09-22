/*
	日志排序
*/
#include <bits/stdc++.h>
using namespace std;
#define N 10001

struct T {
	int s1,s2,s3,s4,s5;
	char name[100];
	char date[100];
	char time[100];
	double t;
	bool operator < (const T &a) const {
		if(t != a.t) return t < a.t;
		if(strcmp(date, a.date) != 0) return strcmp(date, a.date) < 0;
		return strcmp(time, a.time) < 0;
	}
} task[N];

int num = 0;

int main(void) {
	char s[1000];
	while(gets(s)) {
		if(strcmp(s, "") == 0) break;
		task[num].s1 = task[num].s2 = task[num].s3 = task[num].s4 = task[num].s5 = 0;
		int len = strlen(s);
		int i = 0;
		while(s[i] == ' ') {
			task[num].s1 ++;
			i ++;
		}
		int j = 0;
		while(s[i] != ' ') {
			task[num].name[j ++] = s[i];
			i ++;
		}
		task[num].name[j] = 0;
		while(s[i] == ' ') {
			task[num].s2 ++;
			i ++;
		}
		j = 0;
		while(s[i] != ' ') {
			task[num].date[j ++] = s[i];
			i ++;
		}
		task[num].date[j] = 0;
		while(s[i] == ' ') {
			task[num].s3 ++;
			i ++;
		}
		j = 0;
		while(s[i] != ' ') {
			task[num].time[j ++] = s[i];
			i ++;
		}
		task[num].time[j] = 0;
		while(s[i] == ' ') {
			task[num].s4 ++;
			i ++;
		}
		char tmp[20];
		j = 0;
		while(s[i] != ' ' && s[i] != 0) {
			tmp[j ++] = s[i];
			i ++;
		}
		tmp[j] = 0;
		double co = 0.001, T = 0;
		for(int k = j - 4; k >= 0 ; k --) {
			if(tmp[k] == '.') continue;
			T += ((tmp[k] - '0') * co);
			co *= 10;
		}
		task[num].t = T;
		while(s[i] == ' ') {
			task[num].s5 ++;
			i ++;
		}
		num ++;
	}
	sort(task, task + num);
	for(int i = 0 ; i < num ; i ++) {
		for(int j = 0 ; j < task[i].s1 ; j ++) {
			printf(" ");
		}
		printf("%s", task[i].name);
		for(int j = 0 ; j < task[i].s2 ; j ++) {
			printf(" ");
		}
		printf("%s", task[i].date);
		for(int j = 0 ; j < task[i].s3 ; j ++) {
			printf(" ");
		}
		printf("%s", task[i].time);
		for(int j = 0 ; j < task[i].s4 ; j ++) {
			printf(" ");
		}
		printf("%.3lf(s)", task[i].t);
		for(int j = 0 ; j < task[i].s5 ; j ++) {
			printf(" ");
		}
		printf("\n");
	}
	return 0;
}