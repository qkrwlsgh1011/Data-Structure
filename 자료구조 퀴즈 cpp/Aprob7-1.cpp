#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* prev;
	Node(int e) {
		this->data = e;
		this->next = NULL;
		this->prev = NULL;
	}
};

class Double {
public:
	Node* head;
	Node* tail;
	Node* curNode;
	int many;

	Double() {
		this->head = NULL;
		this->tail = NULL;
		this->curNode = NULL;
		this->many = 10;
	}

	void input(int X) {
		Node* newNode = new Node(X);
		if (head == NULL) {
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
	}

	void del(int X) {
		curNode = head;
		for (int i = 0; i < X; i++) {
			if (curNode == tail) {
				curNode->next = head;
			}
			curNode = curNode->next;
		}
		if (curNode == head) {
			head = head->next;
			tail->next = head;
		}
		else if (curNode == tail) {
			tail = tail->prev;
			tail->next = head;
		}
		else
		{
			curNode->prev->next = curNode->next;
			curNode->next->prev = curNode->prev;
		}
		many--;
	}

	void print() {
		for (int i = 0; i < many; i++) {
			cout << head->data << " ";
			head = head->next;
		}
		cout << endl;
	}
};

int main() {
	int count;
	int _del;
	int idx;
	string d;
	cin >> count;
	for (int i = 0; i < count; i++) {
		Double* D=new Double();
		for (int j = 0; j < 10; j++) {
			cin >> idx;
			D->input(idx);
		}
		cin >> d;
		if (d == "Delete") {
			cin >> _del;
			D->del(_del);
		}
		cin >> d;
		if (d == "Delete") {
			cin >> _del;
			D->del(_del);
		}
		cin >> d;
		if (d == "Delete") {
			cin >> _del;
			D->del(_del);
		}
		D->print();
		delete D;
	}
	return 0;
}