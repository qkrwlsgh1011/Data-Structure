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

	int a_idx = 0;
	int b_idx = 0;
	int a_p = 0;
	int b_p = 0;
	for (int i = 0; i < much; i++) {
		Queue* q1=new Queue();
		Queue* q2=new Queue();
		int Cardmuch;
		cin >> Cardmuch;
		for (int j = 0; j < Cardmuch; j++) {
			int idx;
			cin >> idx;
			q1->enqueue(idx);
		}
		for (int k = 0; k < Cardmuch; k++) {
			int idx;
			cin >> idx;
			q2->enqueue(idx);
		}
		for (int l = 0; l < Cardmuch; l++) {
			a_idx = q1->dequeue();
			b_idx = q2->dequeue();
			if (a_idx > b_idx) {
				a_p++;
			}
			else if (a_idx < b_idx) {
				b_p++;
			}
		}
		if (a_p < b_p) {
			cout << 2 << endl;
		}
		else if (a_p == b_p) {
			cout << 0 << endl;
		}
		else
			cout << 1 << endl;
		delete q1;
		delete q2;
	}
	return 0;
}