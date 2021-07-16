#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <queue>

using namespace std;

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

// insert_search.cpp
BstNode* Insert(BstNode* root, int data);
bool Search(BstNode* root, int data);

// find.cpp
int findMin(BstNode* root);
int findMinRe(BstNode* root);
BstNode* findMinNode(BstNode* root);
int findMax(BstNode* root);
int findMaxRe(BstNode* root);
int findHeight(BstNode* root);
BstNode* Find(BstNode* root, int data);

// order.cpp
void LevelOrder (BstNode* root);
void Preorder(BstNode* root);
void Inorder(BstNode* root);
void Postorder(BstNode* root);

// isBST.cpp
//bool isSubtreeLesser(BstNode* root, int value);
//bool isSubtreeGreater(BstNode* root, int value);
//bool isBstWorst(BstNode* root);
bool isBstUtil(BstNode* root, int minValue, int maxValue);
bool isBst(BstNode* root);

// others.cpp
BstNode* GetNewNode(int data);
BstNode* Delete(BstNode* root, int data);
BstNode* GetSuccesor(BstNode* root, int data);



#endif