/*

1)Given a BST ,Find its Maximum Height

Height of a NULL BST is 0

Height of a BST which has only one node is 1

Ex Input :

10
/\
5 80
/  /
2  50
\
4

Height of above Tree is 4

Ex Output : Return the Height of the Tree , -1 if Invalid

2) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 11
get_sum_left for 80 returns 0
Return -1 for invalid inputs

3) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 130
get_sum_left for 80 returns 0
Return -1 for invalid inputs

*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};


int get_height(struct node *root){
	if (root == NULL)
		return 0;
	else
	{
		int l, r;
		struct node *ro;
		ro = root;
		for (ro, l = 1; ro->left != NULL; ro = ro->left, l++);
		for (ro = root, r = 1; ro->right != NULL; ro = ro->right, r++);
		if (l > r)
			return l;
		else
			return r;
	}

}

int get_left_subtree_sum(struct node *root){
	if (root == NULL || root->left == NULL)
		return 0;
	int sum = 0;
	struct node *r;
		r = root->left;
		for (r; r != NULL; r = r->left){
			sum += r->data;
		}
		r = root->left->right;
		for (r; r != NULL; r = r->right){
			sum += r->data;
		}
		return sum;
}

int get_right_subtree_sum(struct node *root){
	if (root == NULL||root->right==NULL)
		return 0;
	int sum = 0;
	struct node *r;
	r = root->right->left;
	for (r; r != NULL; r = r->left){
		sum += r->data;
	}
	r = root->right;
	for (r; r != NULL; r = r->right){
		sum += r->data;
	}
	return sum;
}
