#include "header.h"

BstNode* GetNewNode(int data) {
	// this function allocates space in memory for a new node, and its used when the insert function is called
    BstNode* new_node = new BstNode();
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

BstNode* Delete(BstNode* root, int data) {
	// this function deletes an element from the tree, while maintaining its BST properties
	if (root == NULL) return root;
	// Find node
	if (root->data > data)
		root->left = Delete(root->left, data);
	else if (root->data < data)
		root->right = Delete(root->right, data);
	else {  // Node found
		// case of leaf node
		if(root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		// case of one children
		else if(root->right == NULL) {
			BstNode* temp = root;
			root = root->left;
			delete temp;
		}
		// case of one children
		else if(root->left == NULL) {
			BstNode* temp = root;
			root = root->right;
			delete temp;
		}
		// case of two children
		else {
			BstNode* temp {};
			temp->data = findMinRe(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}
	
	return root;
}

BstNode* GetSuccesor(BstNode* root, int data) {
	// this function gets the succesor of a certain value of a tree as the form of data
	if(root == NULL) return NULL;
	// Find node and set it to be equal to data
	BstNode* current = Find(root, data);
	// If the node is not found
	if(current == NULL) return NULL;
	// Case 1: node has a right child - succesor is node with minimum value of right subtree
	else if(current->right != NULL) {
		BstNode* succesor = findMinNode(current->right);
		return succesor;
	}
	// Case 2: node does not have a right child - succesor is the nearest ancestor for which the given node is in its left subtree
	else {
		BstNode* succesor = NULL;
		BstNode* ancestor = root;
		while(ancestor->data != current->data) {
			if(current->data < ancestor->data) {
				succesor = ancestor;
				ancestor = ancestor->left;
			}
			else {
				ancestor = ancestor->right;
			}
		}
		return succesor;
	}
	
}