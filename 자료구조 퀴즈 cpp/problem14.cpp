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

	int dequeue() {
		if (head == NULL) {
			cout << "Empty" << endl;
			return 0;
		}
		else {
			Node* tmpNode = head;
			int tmp;
			tmp = head->data;
			head = head->next;
			delete tmpNode;
			queueCount--;
			return tmp;
		}
	}
};

int main() {
	int much;
	cin >> much;
	Queue q1;
	Queue q2;
	int a_idx = 0;
	int b_idx = 0;
	int plusA = 0;
	int plusB = 0;
	int a_p = 0;
	int b_p = 0;
	for (int i = 0; i < much; i++) {
		int Cardmuch;
		cin >> Cardmuch;
		for (int j = 0; j < Cardmuch; j++) {
			int idx;
			cin >> idx;
			q1.enqueue(idx);
		}
		for (int k = 0; k < Cardmuch; k++) {
			int idx;
			cin >> idx;
			q2.enqueue(idx);
		}
		for (int l = 0; l < Cardmuch; l++) {
			a_idx = q1.dequeue();
			a_idx += plusA;
			b_idx = q2.dequeue();
			b_idx += plusB;
			if (a_idx > b_idx) {
				plusA = a_idx - b_idx - 1;
				a_p++;
			}
			else if (a_idx < b_idx) {
				plusB = b_idx - a_idx - 1;
				b_p++;
			}
		}
		if (a_p < b_p) {
			cout << "2" << endl;
		}
		else if (a_p == b_p) {
			cout << "0" << endl;
		}
		else
			cout << "1" << endl;
	}
	return 0;
}