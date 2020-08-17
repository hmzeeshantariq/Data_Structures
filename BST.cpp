#include "BST.h"

BST::BST() {
	root = nullptr;
}

BstNode* BST::findMin(BstNode* node) {
	BstNode* parent, * child;
	parent = child = node;
	while (child) {
		parent = child;
		child = child->left;
	}
	return parent;
}

BstNode* BST::recursiveDelete(BstNode* node, int data) {
	if (node == NULL) return nullptr;
	if (data > node->val) node->right = recursiveDelete(node->right, data);
	else if (data < node->val) node->left = recursiveDelete(node->left, data);
	else {  // found !!!
		if (!node->left && !node->right) { // case 1: NO child
			delete node;
			node = nullptr;
		}
		else if (!node->right) { // case 2: Single child
			BstNode* del = node;
			node = node->left;
			delete del;
		}
		else if (!node->left) {
			BstNode* del = node;
			node = node->right;
			delete del;
		}
		else { // case 3: Both childs
			BstNode* del = findMin(node->right);
			node->val = del->val;
			node->right = recursiveDelete(node->right, del->val);
		}
	}
	return node;
}

void BST::deleteNode(int data) {
	root = recursiveDelete(root, data);
}

void BST::postOrder(BstNode* node) {
	if(node == NULL) return;
	postOrder(node->left);
	postOrder(node->right);
	cout << node->val << " ";
}

void BST::postOrder() {
	postOrder(root);
}

int BST::min() {
	if(!root) return INT_MIN;
	BstNode* ptr = root;
	while (ptr->left) ptr = ptr->left;
	return ptr->val;
}

void BST::inOrder(BstNode* node) {
	if(node == NULL) return;
	inOrder(node->left);
	cout << node->val << " ";
	inOrder(node->right);
}

void BST::inOrder() {
	inOrder(root);
}

void BST::preOrder(BstNode* node) {
	if(!node) return;
	cout << node->val << " ";
	preOrder(node->left);
	preOrder(node->right);
}

void BST::preOrder() {
	preOrder(root);
}

BstNode* BST::getRoot() { return root; }

int BST::getHeight() {
	return recursiveHeight(root);
}

int BST::recursiveHeight(BstNode* node) {
	int lTree = 0;
	int rTree = 0;
	if(!node) return -1;
	if(node->right) {
		rTree = 1 + recursiveHeight(node->right);
		return rTree;
	}
	if (node->left) {
		lTree = 1 + recursiveHeight(node->left);
		return lTree;
	}

	if(lTree > rTree) return (lTree + 1);
	else return (rTree + 1);
}

bool BST::recursiveSearch(int data) {
	return recursiveSearch(root, data);
}

bool BST::recursiveSearch(BstNode* node, int data) {
	if (!node) return false;
	if (node->val == data) return true;
	else if (data > node->val) return recursiveSearch(node->right, data);
	else { return recursiveSearch(node->left, data); }
}

bool BST::search(int data) {
	BstNode* ptr = root;
	while (ptr) {
		if (ptr->val == data) return true;
		else if (data > ptr->val) 
			ptr = ptr->right;
		else
			ptr = ptr->left;
	}
	return false;
}

void BST::deleteTree(BstNode* node) {
	if(node == NULL) return;
	deleteTree(node->left);
	deleteTree(node->right);
	delete node;
}

BstNode* BST::createNode(int val) {
	BstNode* node = new BstNode();
	node->val = val;
	node->left = node->right = nullptr;
	return node;
}

void BST::levelOrderTraversal() {
	BstNode* ptr = root;
	if (ptr) {
		queue<BstNode*> Q;
		Q.push(ptr);
		while (!Q.empty()) {
			ptr = Q.front();

			if (ptr->left) Q.push(ptr->left);
			
			if (ptr->right) Q.push(ptr->right);
			
			cout << ptr->val << " ";
			Q.pop();
		}
	}
}

BstNode* BST::recursiveInsert(BstNode* node, int data) {
	if(!node) node = createNode(data);
	else if (data > node->val) {
		node->right = recursiveInsert(node->right, data);
	}
	else {
		node->left = recursiveInsert(node->left, data);
	}
	return node;
}

void BST::insert(int val) {
	root = recursiveInsert(root, val);
}

BST::~BST() {
	BstNode* ptr = root;
	deleteTree(ptr);
}