#ifndef DOUBLY_LINKED_LIST_CPP
#define DOUBLY_LINKED_LIST_CPP
#include "doublyLinkedList.h"

template <class T>
DoublyList<T>::DoublyList() {
	head = nullptr;
}

template <class T>
int DoublyList<T>::getCount() {
	Node<T>* ptr = head;
	int count = 0;
	while (ptr) {
		count++;
		ptr = ptr->next;
	}
	return count;
}

template <class T>
Node<T>* DoublyList<T>::createNode(T v) {
	Node<T>* node = new Node<T>();
	node->val = v;
	node->next = node->prev = nullptr;
	return node;
}

template <class T>
void DoublyList<T>::insertAtHead(T v) {
	if (!head) {
		head = createNode(v);
	}
	else {
		Node<T>* ptr = createNode(v);
		ptr->next = head;
		head->prev = ptr;
		head = ptr;
	}
}

template <class T>
bool DoublyList<T>::isEmpty() {
	if(head) return false;
	return true;
}

template <class T>
void DoublyList<T>::print() {
	Node<T>* ptr = head;
	while (ptr) {
		cout << ptr->val << " ";
		ptr = ptr->next;
	}
	cout << "\n";
}

template <class T>
void DoublyList<T>::insertAt(int pos, T val) {
	int count = getCount();
	if(pos > count || pos < 1) cout << "Invalid Index for insertion\n";
	else {
		Node<T>* node = createNode(val);
		if (pos == 1) {
			node->next = head;
			head->prev = node;
			head = node;
		}
		else {
			Node<T>* ptr = head;
			int index = 1;

			while (index < pos - 1) {
				ptr = ptr->next;
				index++;
			}
			node->next = ptr->next;
			ptr->next->prev = node;
			ptr->next = node;
			node->prev = ptr;
		}
		node = nullptr;
	}
}

template <class T>
void DoublyList<T>::deleteAt(int pos) {
	int count = getCount();
	if(pos > count || pos < 1) cout << "Invalid index for Deletion\n";
	else {
		Node<T>* ptr = head;
		if (pos == 1) {
			head = ptr->next;
			head->prev = nullptr;
		}
		else {
			int count = 1;
			Node<T>* del = nullptr;
			while (count < pos - 1) {
				ptr = ptr->next;
				count++;
			}
			del = ptr->next;
			ptr->next = del->next;
			del->next->prev = ptr;
			ptr = del;
		}
		delete ptr;
		ptr = nullptr;
	}
}

template <class T>
void DoublyList<T>::printReverse() {
	Node<T>* temp = head;
	while(temp->next != NULL)
		temp = temp->next;
	while (temp != NULL) {
		cout << temp->val << " ";
		temp = temp->prev;
	}
	cout << "\n";
}

template <class T>
DoublyList<T>::~DoublyList() {
	Node<T>* del;
	while (head) {
		del = head;
		head = head->next;
		delete del;
	}
	del = nullptr;
}

#endif