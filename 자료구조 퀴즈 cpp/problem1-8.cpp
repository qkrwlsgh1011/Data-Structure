#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	Node* next;
	int data;

	Node(int e) {
		this->data = e;
		this->next = NULL;
	}
};

class Stack {
public:
	Node* head;
	Node* tail;
	int stackCount;

	Stack() {
		head = NULL;
		tail = NULL;
		stackCount = 0;
	}

	void empty() {
		if (head == NULL) {
			cout << "1" << endl;
		}
		else {
			cout << "0" << endl;
		}
	}

	void top() {
		if (head == NULL) {
			cout << "-1" << endl;
		}
		else {
			cout << head->data << endl;
		}
	}

	void push(int X) {
		Node* newStack = new Node(X);
		if (head == NULL) {
			head = tail = newStack;
			stackCount++;
		}
		else {
			newStack->next = head;
			head = newStack;
			stackCount++;
		}
	}

	void pop() {
		if (head == NULL) {
			cout << "-1" << endl;
		}
		else {
			int tempt;
			tempt = head->data;
			head = head->next;
			cout << tempt << endl;
			stackCount--;
		}
	}

	void size() {
		if (stackCount <= 0) {
			cout << "0" << endl;
		}
		else
			cout << stackCount << endl;
	}
};

int main() {
	int much;
	cin >> much;
	string tmp;
	Stack stack;
	for (int i = 0; i < much; i++) {
		cin >> tmp;
		if (tmp == "empty") {
			stack.empty();
		}
		else if (tmp == "top") {
			stack.top();
		}
		else if (tmp == "push") {
			int idx;
			cin >> idx;
			stack.push(idx);
		}
		else if (tmp == "pop") {
			stack.pop();
		}
		else if (tmp == "size") {
			stack.size();
		}
	}
	return 0;
}