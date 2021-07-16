#include "header.h"

int findMin(BstNode* root) {
	// this function finds the minimum value in a tree
    if(root == NULL) {
        cout << "Tree is empty\n";
        return 1;
    }
    else {
        while(root->left != NULL) {
            root = root->left;
        }
        return root->data;
    }
}

int findMinRe(BstNode* root) {
	// this function finds the minimun value in a tree recursively
    if(root == NULL) {
        cout << "The tree is empty\n";
        return 1;
    }
    else if(root->left == NULL) {
        return root->data;
    }
        return findMinRe(root->left);
}

BstNode* findMinNode(BstNode* root) {
	// this function finds the struct where the minimum value of a tree is stored
    if(root == NULL) {
        cout << "Tree is empty\n";
        return NULL;
    }
    else {
        while(root->left != NULL) {
            root = root->left;
        }
        return root;
    }
}

int findMax(BstNode* root) {
	// this function finds the maximum value in a tree
    if(root == NULL) {
        cout << "Tree is empty\n";
        return 1;
    }
    else {
        while(root->right != NULL) {
            root = root->right;
        }
        return root->data;
    }
}

int findMaxRe(BstNode* root) {
	// this function finds the maximum value in a tree recursively
    if(root == NULL) {
        cout << "The tree is empty\n";
        return 1;
    }
    else if(root->right == NULL) {
        return root->data;
    }

    return findMaxRe(root->right);
}

int findHeight(BstNode* root) {
	// this function finds the height of a tree
    if(root == NULL) {
        return -1;
    }

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

BstNode* Find(BstNode* root, int data) {
	// this function finds the struct where a certain value (data) is stored
    if(root == NULL) {
        return NULL;
    }
    else if(data < root->data) {
        return Find(root->left, data);
    }
    else if(data > root->data) {
        return Find(root->right, data);
    }
    else if(data == root->data) {
        return root;
    }
    return NULL;
}