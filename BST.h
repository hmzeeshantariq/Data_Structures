#ifndef BST_H
#define BST_H
#include <queue>
#include <iostream>
using namespace std;

struct BstNode {
	int val;
	BstNode* left;
	BstNode* right;
};

class BST {
private:
	BstNode* root;
	BstNode* createNode(int val);
	void deleteTree(BstNode* node);
	bool recursiveSearch(BstNode* node, int data);
	int recursiveHeight(BstNode* node);
	void preOrder(BstNode* node);
	void inOrder(BstNode* node);
	void postOrder(BstNode* node);
	BstNode* findMin(BstNode* node);
	BstNode* recursiveDelete(BstNode* node, int data);
public:
	BST();
	void insert(int val);
	BstNode* recursiveInsert(BstNode*, int);
	void levelOrderTraversal();
	bool search(int data);
	bool recursiveSearch(int data);
	int min();
	BstNode* getRoot();
	int getHeight();
	void preOrder();
	void inOrder();
	void postOrder();
	void deleteNode(int val);
	~BST();
};

#endif
