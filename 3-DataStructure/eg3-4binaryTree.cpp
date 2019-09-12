/*
	二叉树遍历
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
	Node *left;
	Node *right;
	char c;
} Tree[50];

int loc;

Node *creat() {
	Tree[loc].left = Tree[loc].right = NULL;
	return &Tree[loc ++];
}

char str1[30], str2[30];

void postOrder(Node *t) {
	if(t -> left) {
		postOrder(t -> left);
	}
	if(t -> right) {
		postOrder(t -> right);
	}
	printf("%c", t -> c);
}

Node *build(int s1, int e1, int s2, int e2) {
	Node *ret = creat();
	ret -> c = str1[s1];
	int rootIdx;
	for(int i = s2 ; i <= e2 ; i ++) {
		if(str2[i] == str1[s1]) {
			rootIdx = i;
			break;
		}
	}
	if(rootIdx != s2) {
		ret -> left = build(s1 + 1, s1 + (rootIdx - s2), s2 , rootIdx - 1);
	}
	if(rootIdx != e2) {
		ret -> right = build(s1 + (rootIdx - s2) + 1, e1 , rootIdx + 1, e2);
	}
	return ret;
}

int main(void) {
	while(scanf("%s", str1) != EOF) {
		scanf("%s", str2);
		int l1 = strlen(str1);
		int l2 = strlen(str2);
		Node *t = build(0, l1 - 1, 0 , l2 - 1);
		postOrder(t);
		printf("\n");
	}
	return 0;
}