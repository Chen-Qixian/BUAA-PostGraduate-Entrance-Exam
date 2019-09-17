/*
	二叉搜索树
*/
#include <bits/stdc++.h>
using namespace std;

char ori[20], tar[20];
char src_pre[20], dst_pre[20], src_in[20], dst_in[20];

struct Node {
	Node *left;
	Node *right;
	char val;
} Tree[110];

int loc, ptr;

Node *creat() {
	Tree[loc].left = Tree[loc].right = NULL;
	return &Tree[loc ++];
}

Node *insert(Node *t, char v) {
	if(t == NULL) {
		t = creat();
		t -> val = v;
		return t;
	}
	else if(v < t -> val) {
		t -> left = insert(t -> left, v);
	}
	else if(v > t -> val) {
		t -> right = insert(t -> right , v);
	}
	return t;
}

void preOrder(Node *t, char *s) {
	s[ptr ++]= t -> val;
	if(t -> left)
		preOrder(t -> left, s);
	if(t -> right)
		preOrder(t -> right, s);
}

void inOrder(Node *t, char *s) {
	if(t -> left) 
		inOrder(t -> left , s);
	s[ptr ++] = t -> val;
	if(t -> right)
		inOrder(t -> right, s);
}

int main(void) {
	int n;
	while(scanf("%d", &n) != EOF) {
		if(n == 0) break;
		loc = 0;
		scanf("%s", ori);
		Node *src = NULL;
		for(int i = 0 ; ori[i] != 0 ; i ++) {
			src = insert(src, ori[i]);
		}
		memset(src_pre, 0 , sizeof(src_pre));
		memset(src_in, 0, sizeof(src_in));
		ptr = 0;
		preOrder(src, src_pre);
		src_pre[ptr] = 0;
		ptr = 0;
		inOrder(src, src_in);
		src_in[ptr] = 0;
		for(int i = 0 ; i < n ; i ++) {
			Node *dst = NULL;
			scanf("%s", tar);
			for(int j = 0 ; tar[j] != 0 ; j ++) {
				dst = insert(dst, tar[j]);
			}
			memset(dst_pre, 0, sizeof(dst_pre));
			memset(dst_in, 0, sizeof(dst_in));
			ptr = 0;
			preOrder(dst, dst_pre);
			dst_pre[ptr] = 0;
			ptr = 0;
			inOrder(dst, dst_in);
			dst_in[ptr] = 0;
			if(strcmp(src_pre, dst_pre) == 0 && strcmp(src_in, dst_in) == 0) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
	}
	return 0;
}