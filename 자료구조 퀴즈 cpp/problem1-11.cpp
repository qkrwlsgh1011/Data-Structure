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

class Queue {
public:
	Node* head;
	Node* tail;
	int queueCount = 0;

	Queue() {
		this->head = NULL;
		this->tail = NULL;
	}

	void enqueue(int X) {
		Node* newQueue = new Node(X);
		if (head == NULL) {
			head = tail = newQueue;
			queueCount++;
		}
		else {
			tail->next = newQueue;
			tail = newQueue;
			queueCount++;
		}
	}

	void dequeue() {
		if (head == NULL) {
			cout << "Empty" << endl;
		}
		else {
			int tmp;
			tmp = head->data;
			head = head->next;
			cout << tmp << endl;
			queueCount--;
		}
	}

	void size() {
		cout << queueCount << endl;
	}

	void isEmpty() {
		if (head == NULL) {
			cout << "1" << endl;
		}
		else {
			cout << "0" << endl;
		}
	}

	void front() {
		if (head == NULL) {
			cout << "Empty" << endl;
		}
		else {
			cout << head->data << endl;
		}
	}

	void rear() {
		if (head == NULL) {
			cout << "Empty" << endl;
		}
		else {
			cout << tail->data << endl;
		}
	}
};

int main() {
	Queue q;
	int idxmuch;
	cin >> idxmuch;
	int much;
	cin >> much;
	string tempt;
	for (int i = 0; i < much; i++) {
		cin >> tempt;
		if (tempt == "enqueue") {
			int idx;
			cin >> idx;
			if (idxmuch > q.queueCount) {
				q.enqueue(idx);
			}
			else {
				cout << "Full" << endl;
			}
		}
		else if (tempt == "dequeue") {
			q.dequeue();
		}
		else if (tempt == "size") {
			q.size();
		}
		else if (tempt == "isEmpty") {
			q.isEmpty();
		}
		else if (tempt == "front") {
			q.front();
		}
		else if (tempt == "rear") {
			q.rear();
		}
	}
	return 0;
}