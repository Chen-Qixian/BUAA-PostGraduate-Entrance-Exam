/*
	二叉排序树
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
	Node *left;
	Node *right;
	int val;
} Tree[110];

int loc;

Node *creat() {
	Tree[loc].left = Tree[loc].right = NULL;
	return &Tree[loc ++];
}

void preOrder(Node *t) {
	printf("%d ", t -> val);
	if(t -> left)
		preOrder(t -> left);
	if(t -> right)
		preOrder(t -> right);
}

void inOrder(Node *t) {
	if(t -> left) {
		inOrder(t -> left);
	}
	printf("%d ", t -> val);
	if(t -> right) {
		inOrder(t -> right);
	}
}

void postOrder(Node *t) {
	if(t -> left)
		postOrder(t -> left);
	if(t -> right)
		postOrder(t -> right);
	printf("%d ", t -> val);
}

Node *insert(Node *t, int v) {
	if(t == NULL) {
		t = creat();
		t -> val = v;
		return t;
	}
	else if(v > t -> val) {
		t -> right = insert(t -> right, v);
	}
	else if(v < t -> val) {
		t -> left = insert(t -> left, v);
	}
	return t;
}

int main(void) {
	int n, x;
	while(scanf("%d", &n) != EOF) {
		loc = 0;
		Node *r = NULL;
		for(int i = 0 ; i < n ; i ++) {
			scanf("%d", &x);
			r = insert(r, x);
		}
		preOrder(r);
		printf("\n");
		inOrder(r);
		printf("\n");
		postOrder(r);
		printf("\n");
	}
	return 0;
}