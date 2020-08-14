#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
#include <iostream>
using namespace std;

template <typename T>
struct Node {
	T val;
	Node* next;
	Node* prev;
};

template <class T>
class DoublyList {
private:
	Node<T>* head;
	int getCount();
	Node<T>* createNode(T v);
public:
	DoublyList();
	void insertAtHead(T v);
	bool isEmpty();
	void print();
	void insertAt(int pos, T val);
	void deleteAt(int pos);
	void printReverse();
	~DoublyList();
};

#include "doublyLinkedList.cpp"

#endif