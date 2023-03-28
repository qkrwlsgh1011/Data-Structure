#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int e) {
		this->data = e;
		this->next = NULL;
	}
};

class SlinkedList {
public:
	Node* head;
	Node* tail;

	SlinkedList() {
		head = NULL;
		tail = NULL;
	}

	int front() {
		return head->data;
	}

	void addFront(int e) {
		Node* newNode = new Node(e);
		if (head == NULL) {
			head = tail = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
	}
};