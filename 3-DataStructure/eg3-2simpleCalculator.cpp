/*
	简单计算器
*/
#include <bits/stdc++.h>
using namespace std;

stack<double> num;
stack<char> op;

int main(void) {
	char str[220];
	while(gets(str)) {
		if(str[0] == '0' && str[1] == 0) break;
		while(!num.empty()) num.pop();
		while(!op.empty()) op.pop();
		int tmp = 0;
		bool isnum = true;
		double a, b;
		for(int i = 0 ; str[i] != 0 ; i ++) {
			if(str[i] == ' '){
				if(isnum) {
					isnum = false;
					num.push(tmp);
				}
				else {
					isnum = true;
				}
				tmp = 0;
			}
			else if(str[i] == '+' || str[i] == '-') {
                while(!op.empty()) {
                    if(op.top() == '+') {
                        a = num.top();
                        num.pop();
                        a += num.top();
                        num.pop();
                        num.push(a);
                        op.pop();
                    }
                    else if(op.top() == '-') {
                        a = num.top();
                        num.pop();
                        b = num.top();
                        num.pop();
                        num.push(b - a);
                        op.pop();
                    }
                    else if(op.top() == '*') {
                        a = num.top();
                        num.pop();
                        a *= num.top();
                        num.pop();
                        num.push(a);
                        op.pop();
                    }
                    else if(op.top() == '/') {
                        a = num.top();
                        num.pop();
                        b = num.top();
                        num.pop();
                        num.push(b / a);
                        op.pop();
                    }
                }				
                op.push(str[i]);
			}
			else if(str[i] == '*' || str[i] == '/') {
                while(!op.empty() && op.top() != '+' && op.top() != '-') {
                    if(op.top() == '*') {
                        a = num.top();
                        num.pop();
                        a *= num.top();
                        num.pop();
                        num.push(a);
                        op.pop();
                    }
                    else if(op.top() == '/') {
                        a = num.top();
                        num.pop();
                        b = num.top();
                        num.pop();
                        num.push(b / a);
                        op.pop();
                    }
                }
                op.push(str[i]);
			}
			else {
				tmp *= 10;
				tmp += str[i] - '0';
			}
		}
		num.push(tmp);
		while(!op.empty()) {
			a = num.top();
			num.pop();
			char c = op.top();
			op.pop();
			switch(c) {
				case '+':{
					a += num.top();
					break;
				}
				case '-':{
					b = num.top();
					a = b - a;
					break;
				}
				case '*':{
					a *= num.top();
					break;
				}
				case '/':{
					b = num.top();
					a = b / a;
					break;
				}
			} 
			num.pop();
			num.push(a);
		}
		printf("%.2lf\n", num.top());
	}
	return 0;
}