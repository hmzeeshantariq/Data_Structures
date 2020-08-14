#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H
#include <iostream>
using namespace std;


template <typename T>
struct Node {
	T val;
	Node* next;
};

template <class T>
class List {
private:	
	Node<T>* head;
	int getCount();
	Node<T>* createNode(T v);
	void printReverse(Node<T>* h);
	void recursiveReverse(Node<T>* h);
public:
	List();
	void insertAtHead(T v);
	bool isEmpty();
	void print();
	void insertAt(int pos, T val);
	void deleteAt(int pos);
	void reverseList();
	void recursiveReverse();
	void printReverse();
	~List();
};

#include "singlyLinkedList.cpp"

#endif