#include "header.h"

int main()
{
	// all BST functions are tested here
    // set root to be null so the tree is empty
    BstNode* root = NULL;

	// add elements to the tree
    root = Insert(root,15);
	root = Insert(root,10);
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);

	// find min value in the tree
	cout << "Min: " << findMin(root) << " " << findMinRe(root) << endl;
	// find max value in the tree
	cout << "Max: " << findMax(root) << " " << findMaxRe(root) << endl;
	// find height of the tree
	cout << "Height: " << findHeight(root) << endl;
	// Ask user to enter a number.
	int number;
	cout << "Enter number to be searched: ";
	cin >> number;
	// If number is found, print "FOUND", else print "NOT FOUND"
	if(Search(root,number) == true) cout<<"Found\n";
	else cout<<"Not Found\n";
	
	// print order of elements in the tree by using different strategies
	cout << "Level order (breadth-first): ";
	LevelOrder(root);
	cout << "\n";
	cout << "Pre order (depth-first): ";
	Preorder(root);
	cout << "\n";
	cout << "In order (depth-first): ";
	Inorder(root);
	cout << "\n";
	cout << "Post order (depth-first): ";
	Postorder(root);
	cout << "\n";
	
	// check if the tree is a binary search tree
	if(isBst(root))
		cout << "The tree is a binary search tree" << endl;
	else
		cout << "Not a binary search tree" << endl;
		
	Delete(root, 25);
	// Ask user to enter a number.
	cout<<"Enter number and find its succesor: ";
	cin>>number;
	// If the number is in the tree, display its succesor
	if(GetSuccesor(root, number) == NULL)
		cout << "Number not found in tree" << endl;
	else {
		BstNode* succesor = GetSuccesor(root, number);
		cout << "The succesor of " << number << " is " << succesor->data << endl;
	}
}
