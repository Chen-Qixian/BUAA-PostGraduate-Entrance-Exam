/*
	二叉树遍历（2）
	注意创建二叉树的build方法
	注意边界和空树的判断
*/
#include <bits/stdc++.h>
using namespace std;

char s[110];

struct Node {
	Node *left;
	Node *right;
	char c;
} Tree[1000];

int loc;
int ptr;

Node *creat() {
	Tree[loc].left = Tree[loc].right = NULL;
	return &Tree[loc ++];
}

void inOrder(Node *t) {
	if(t -> left) {
		inOrder(t -> left);
	}
	printf("%c ", t -> c);
	if(t -> right) {
		inOrder(t -> right);
	}
}

Node *build() {
	if(s[ptr] == 0) return NULL;
	Node *ret = creat();
	if(s[ptr] != ' ') {
		ret -> c = s[ptr ++];
	}
	else {
		ptr ++;
		return NULL;
	}
	ret -> left = build();
	ret -> right = build();
	return ret;
}

int main(void) {
	while(gets(s)) {
		loc = 0;
		ptr = 0;
		Node *t = build();
		inOrder(t);
		printf("\n");
	}
	return 0;
}