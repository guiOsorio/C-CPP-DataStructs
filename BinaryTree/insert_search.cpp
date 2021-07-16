#include "header.h"

BstNode* Insert(BstNode* root, int data) {
	// this function inserts a new node element of a certain value in a tree
    if(root == NULL) {
        root = GetNewNode(data);
    }
    else if(data <= root->data) {
        root->left = Insert(root->left, data);
    }
    else if(data > root->data) {
        root->right = Insert(root->right, data);
    }
    return root;
}

bool Search(BstNode* root, int data) {
	// this function searches a node with a certain value in a tree, 
	// returning true if a corresponding node is found and false if not
    if(root == NULL) {
        return false;
    }
    else if(data < root->data) {
        return Search(root->left, data);
    }
    else if(data > root->data) {
        return Search(root->right, data);
    }
    else if(data == root->data) {
        return true;
    }
    return false;
}