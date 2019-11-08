/*
	注意节点分配loc每次循环置0
*/
#include <bits/stdc++.h>
using namespace std;
#define N 110

struct Node {
	char val;
	Node* left;
	Node* right;
} tree[N];

int loc;
char pre[N];
char in[N];

Node* create() {
	tree[loc].left = tree[loc].right = NULL;
	return &tree[loc ++];
}

void postOrder(Node* t) {
	if(t->left != NULL) {
		postOrder(t->left);
	}
	if(t->right != NULL) {
		postOrder(t->right);
	}
	printf("%c", t->val);
}

Node* build(int s1, int e1, int s2, int e2) {
	Node* ret = create();
	ret -> val = pre[s1];
	int rootIdx;
	for(int i = s2 ; i <= e2 ; i ++) {
		if(in[i] == ret -> val) {
			rootIdx = i;
			break;
		}
	}

	if(rootIdx != s2) {
		ret -> left = build(s1 + 1, s1 + (rootIdx - s2), s2, rootIdx - 1);
	}
	if(rootIdx != e2) {
		ret -> right = build(s1 + (rootIdx - s2) + 1, e1, rootIdx + 1, e2);
	}

	return ret;

}


int main(void) {
	while(scanf("%s", pre) != EOF) {
		scanf("%s", in);
		loc = 0;
		int l1 = strlen(pre);
		int l2 = strlen(in);
		Node* t = build(0, l1 - 1, 0, l2 - 1);
		postOrder(t);
		printf("\n");
	}
	return 0;
}