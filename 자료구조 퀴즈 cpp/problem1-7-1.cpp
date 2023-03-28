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
	Node* findNodeh;
	Node* findNodet;
	Node* findNodeA;
	Node* findNodeB;
	int count;

	SlinkedList() {
		h = NULL;
		t = NULL;
		findNodeh = NULL;
		findNodet = NULL;
		findNodeA = NULL;
		findNodeB = NULL;
		stNode = NULL;
		count = 10;
	}
	void addBack(int X) {
		Node* newNode = new Node(X);
		if (t == NULL) {
			h = t = newNode;
		}
		else {
			t->next = newNode;
			t = newNode;
		}
	}

	void showList() {
		for (int i = 0; i < 7; i++) {
			cout << h->data << " ";
			h = h->next;
		}
	}

	void nodeDelete(int X) {
		findNodeh = h;
		findNodet = t;
		t->next = h;
		if (X == 0) {
			h = h->next;
			count--;
		}
		else if (X == 1) {
			findNodeB = h->next;
			h->next = findNodeB->next;
			count--;
		}
		else {
			for (int i = 0; i <= X; i++) {
				findNodeh = findNodeh->next;
			}
			findNodeA = findNodeh;
			findNodeh = h;
			for (int j = 1; j < X; j++) {
				findNodeh = findNodeh->next;
			}
			findNodeB = findNodeh;
			findNodeB->next = findNodeA;
			count--;
		}
	}
};

int main() {
	int much;
	cin >> much;
	string _delete;
	for (int i = 0; i < much; i++) {
		SlinkedList linkedList;
		for (int j = 0; j < 10; j++) {
			int tmp;
			cin >> tmp;
			linkedList.addBack(tmp);
		}
		cin >> _delete;
		if (_delete == "Delete") {
			int bund;
			cin >> bund;
			linkedList.nodeDelete(bund);
		}
		cin >> _delete;
		if (_delete == "Delete") {
			int bund;
			cin >> bund;
			linkedList.nodeDelete(bund);
		}
		cin >> _delete;
		if (_delete == "Delete") {
			int bund;
			cin >> bund;
			linkedList.nodeDelete(bund);
		}
		linkedList.showList();
		cout << endl;
	}
	return 0;
}