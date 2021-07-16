#include "header.h"

// Worse approach for checking if a tree is a binary search tree

//bool isSubtreeLesser(BstNode* root, int value) {
//	if(root == NULL) return true;
//	if(root->data <= value
//		&& isSubtreeLesser(root->left, value)
//		&& isSubtreeLesser(root->right, value))
//		return true;
//	else
//		return false;
//}
//bool isSubtreeGreater(BstNode* root, int value) {
//	if(root == NULL) return true;
//	if(root->data > value
//		&& isSubtreeGreater(root->left, value)
//		&& isSubtreeGreater(root->right, value))
//		return true;
//	else
//		return false;
//}
//
//bool isBstWorst(BstNode* root) {
//	if (root == NULL) return true;
//	if (isSubtreeLesser(root->left, root->data)
//		&& isSubtreeGreater(root->right, root->data)
//		&& isBstWorst(root->left)
//		&& isBstWorst(root->right))
//			return true;
//	else 
//		return false;
//}

// Best approach for checking if a tree is a binary search tree

bool isBstUtil(BstNode* root, int minValue, int maxValue) {
	// this function checks if a tree is a binary search tree, using recursion
	if (root == NULL) return true;
	if (root->data >= minValue
		&& root->data < maxValue
		&& isBstUtil(root->left, minValue, root->data)
		&& isBstUtil(root->right, root->data, maxValue))
			return true;
	else 
		return false;
}


bool isBst(BstNode* root) {
	// this function calls and returns the value of isBstUtil
	return isBstUtil(root, INT_MIN, INT_MAX);
}
