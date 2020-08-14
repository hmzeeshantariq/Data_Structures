#ifndef LIST_CPP
#define LIST_CPP
#include "singlyLinkedList.h"

template <class T>
List<T>::List() {
	head = nullptr;
}

template <class T>
void List<T>::print() {
	Node<T>* ptr = head;
	while (ptr) {
		cout << ptr->val;
		ptr = ptr->next;
	}
	cout << "\n";
}

template <class T>
void List<T>::insertAtHead(T v) {
	Node<T>* ptr = createNode(v);

	if (isEmpty()) 
		head = ptr;
	else {
		ptr->next = head;
		head = ptr;
	}
}

template <class T>
int List<T>::getCount() {
	int count = 0;
	Node<T>* ptr = head;
	while (ptr) {
		count++;
		ptr = ptr->next;
	}
	return count;
}

template <class T>
void List<T>::reverseList() {
	Node<T>* curr, *next, *prev = nullptr;
	curr = next = head;

	while (curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
}

template <class T>
Node<T>* List<T>::createNode(T v) {
	Node<T>* ptr = new Node<T>();
	ptr->val = v;
	ptr->next = nullptr;
	return ptr;
}

template <class T>
void List<T>::insertAt(int pos, T val) {
	int count = getCount();

	if (pos < 1) cout << "Invalid Insert at Position\n";
	else if(pos == 1) insertAtHead(val);
	else if (pos <= count)
	{
		Node<T>* newNode = createNode(val);
		int index = 1;
		Node<T>* ptr = head;

		while (index < pos - 1) {
			index++;
			ptr = ptr->next;
		}
		newNode->next = ptr->next;
		ptr->next = newNode;
	}
}

template <class T>
void List<T>::recursiveReverse(Node<T>* h) {
	if(!head) return;
	if (h->next == NULL) {
		head = h;
		return;
	}
	recursiveReverse(h->next);
	Node<T>* temp = h->next;
	temp->next = h;
	h->next = nullptr;
}

template <class T>
void List<T>::recursiveReverse() {
	Node<T>* ptr = head;
	recursiveReverse(ptr);
}

template <class T>
void List<T>::printReverse(Node<T>* h) {
	if (!h) return;
	printReverse(h->next);
	cout << h->val << " ";
}

template <class T>
void List<T>::printReverse() {
	Node<T>* ptr = head;
	printReverse(ptr);
	cout << "\n";
}

template <class T>
void List<T>::deleteAt(int pos) {
	int count = getCount();
	Node<T>* ptr = head;
	Node<T>* del = nullptr;

	if(pos > count || pos < 1) cout << "Invalid Index, Deletion not performed!\n";
	else if (pos == 1) {
		del = ptr;
		ptr = ptr->next;
		head = ptr;
		delete del;
	}
	else {
		int index =  1;

		while (index < pos - 1) {
			ptr = ptr->next;
			index++;
		}

		del = ptr->next;
		ptr->next = ptr->next->next;
		delete del;
	}
	del = nullptr;
	ptr = nullptr;
}

template <class T>
bool List<T>::isEmpty() {
	if(head) return false;
	return true;
}

template <class T>
List<T>::~List() {
	Node<T>* ptr;
	while (head) {
		ptr = head;
		head = head->next;
		delete ptr;
	}
}

#endif