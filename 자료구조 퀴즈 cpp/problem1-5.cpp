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
	Node* h;
	Node* t;

	SlinkedList() {
		h = NULL;
		t = NULL;
	}

	void front() {
		if (h == NULL) {
			cout << "-1" << endl;
		}
		else {
			cout << h->data << endl;
		}
	}

	void addFront(int X) {
		Node* newNode = new Node(X);
		if (h == NULL) {
			h = t = newNode;
		}
		else {
			newNode->next = h;
			h = newNode;
		}
	}

	void removeFront(){
		if (h == NULL) {
			cout << "-1" << endl;
		}
		else {
			int tmp;
			tmp = h->data;
			h = h->next;
			cout << tmp << endl;
		}
	}

	void empty() {
		if (h == NULL) {
			cout << "1" << endl;
		}
		else
			cout << "0" << endl;
	}
};

int main() {
	int much;
	cin >> much;
	SlinkedList linkedList;
	for (int i = 0; i < much; i++) {
		string tempt;
		cin >> tempt;
		if (tempt == "addFront") {
			int X;
			cin >> X;
			linkedList.addFront(X);
		}
		else if (tempt == "removeFront") {
			linkedList.removeFront();
		}
		else if (tempt == "front") {
			linkedList.front();
		}
		else if (tempt == "empty") {
			linkedList.empty();
		}
	}
	return 0;
}