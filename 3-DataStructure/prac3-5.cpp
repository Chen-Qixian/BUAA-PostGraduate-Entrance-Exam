/*
	二叉排序树2
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
	Node *left;
	Node *right;
	int val;
} Tree[110];

int loc, parent;

Node *creat() {
	Tree[loc].left = Tree[loc].right = NULL;
	return &Tree[loc ++];
}

Node *insert(Node *t, int v) {
	if(t == NULL) {
		t = creat();
		t -> val = v;
		printf("%d\n", parent);
		return t;
	}
	else if(v < t -> val) {
		parent = t -> val;
		t -> left = insert(t -> left , v);
	}
	else if(v > t -> val) {
		parent = t -> val;
		t -> right = insert(t -> right, v);
	}	
	return t;
}


int main(void) {
	int n, x;
	while(scanf("%d", &n) != EOF) {
		loc = 0;
		Node *r = NULL;
		parent = -1;
		for(int i = 0 ; i < n ; i ++) {
			scanf("%d", &x);
			r = insert(r, x);
		}
	}
	return 0;
}