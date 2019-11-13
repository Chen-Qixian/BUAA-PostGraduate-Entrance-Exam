#include <bits/stdc++.h>
using namespace std;

int main(void) {
	char s1[202],s2[110];
	while(scanf("%s%s", s1, s2) != EOF) {
		char res[202];
		strcat(s1, s2);
		printf("%s\n", s1);
	}
}