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
	Node* stNode;
	int manyNode;

	SlinkedList() {
		h = NULL;
		t = NULL;
		stNode = NULL;
		manyNode = 0;
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
		manyNode++;
	}

	void removeFront() {
		if (h == NULL) {
			cout << "-1" << endl;
		}
		else {
			int tmp;
			tmp = h->data;
			h = h->next;
			cout << tmp << endl;
			manyNode--;
		}
	}

	void empty() {
		if (h == NULL) {
			cout << "1" << endl;
		}
		else
			cout << "0" << endl;
	}

	void showList() {
		if (h == NULL) {
			cout << "-1" << endl;
		}
		else {
			stNode = h;
			while (stNode != NULL) {
				cout << stNode->data << " ";
				stNode = stNode->next;
			}
			cout << endl;
		}
	}

	void addBack(int X) {
		Node* newNode = new Node(X);
		t->next = newNode;
		t = newNode;
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
		else if (tempt == "showList") {
			linkedList.showList();
		}
		else if (tempt == "addBack") {
			int Y;
			cin >> Y;
			linkedList.addBack(Y);
		}
	}
	return 0;
}