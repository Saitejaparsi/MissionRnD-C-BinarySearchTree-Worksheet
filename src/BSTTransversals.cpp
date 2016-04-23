/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task :
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

void inorder1(struct node *root, int *arr, int *i);
void inorder1(struct node *root, int *arr, int *i)
{
	if (root == NULL)
		return;
	else{
		inorder1(root->left, arr, i);
		arr[*i] = root->data;
		(*i)++;
		inorder1(root->right, arr, i);
	}
}
void inorder(struct node *root, int *arr){
	if (root == nullptr || arr == NULL)
		return;
	else{
		int i = 0;
		struct node *r = root;
		inorder1(r, arr, &i);
	}
}
void preorder1(struct node *root, int *arr, int *i);
void preorder1(struct node *root, int *arr, int *i)
{
	if (root == NULL)
		return;
	else{
		arr[*i] = root->data;
		(*i)++;
		preorder1(root->left, arr, i);
		preorder1(root->right, arr, i);
	}
}
void preorder(struct node *root, int *arr){
	if (root == nullptr || arr == NULL)
		arr = NULL;
	else{
		int i = 0;
		struct node *r = root;
		preorder1(r, arr, &i);
	}
}
void postorder1(struct node *root, int *arr, int *i);
void postorder1(struct node *root, int *arr, int *i){
	if (root == NULL)
		return;
	else{

		postorder1(root->left, arr, i);
		postorder1(root->right, arr, i);
		arr[*i] = root->data;
		(*i)++;
	}
}
void postorder(struct node *root, int *arr){
	if (root == nullptr || arr == NULL)
		arr = NULL;
	else{
		int i = 0;
		struct node *r = root;
		postorder1(r, arr, &i);
	}
}