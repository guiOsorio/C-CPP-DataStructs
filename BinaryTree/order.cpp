#include "header.h"

void LevelOrder (BstNode* root) {
	// this function prints the values in a tree in level-order traversal,
	// meaning it prints the values/data in the tree by level,
	// starting from the root and printing each value in the subsequent level from left to right
	if(root == NULL) return;
	queue<BstNode*> Q;
	Q.push(root);
	while(!Q.empty()) {
		BstNode* current = Q.front();
		cout << current->data << " ";
		if(current->left != NULL) Q.push(current->left);
		if(current->right != NULL) Q.push(current->right);
		Q.pop();
	}
}

void Preorder(BstNode* root) {
	// this function prints the values in a tree in pre-order traversal using recursion,
	// meaning it prints the value/data of the node as soon as the node is reached,
	// and by printing the left subtree before the right
	if(root == NULL) return;
	cout << root->data << " ";
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(BstNode* root) {
	// this function prints the values in a tree in in-order traversal using recursion,
	// meaning it prints the value/data of the node only after its left subtree has been traversed and printed
	if(root == NULL) return;
	Inorder(root->left);
	cout << root->data << " ";
	Inorder(root->right);
}

void Postorder(BstNode* root) {
	// this function prints the values in a tree in post-order traversal using recursion,
	// meaning it prints the value/data of the node only after its left and right subtree have been traversed and printed
	if(root == NULL) return;
	Postorder(root->left);
	Postorder(root->right);
	cout << root->data << " ";
}
