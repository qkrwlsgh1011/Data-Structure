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
	int score;

	Queue() {
		this->head = NULL;
		this->tail = NULL;
		this->score = 0;
	}

	void enqueue(int X) {
		Node* newQueue = new Node(X);
		if (head == NULL) {
			head = tail = newQueue;
		}
		else {
			tail->next = newQueue;
			tail = newQueue;
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
			return tmp;
		}
	}

	void getScore() {
		this->score++;
	}
};

int main() {
	int much;
	cin >> much;

	int a_idx = 0;
	int b_idx = 0;
	int idx;
	int Cardmuch;
	int PlusA = 0;
	int PlusB = 0;
	for (int i = 0; i < much; i++) {
		Queue* q1 = new Queue();
		Queue* q2 = new Queue();
		cin >> Cardmuch;
		for (int j = 0; j < Cardmuch; j++) {
			cin >> idx;
			q1->enqueue(idx);
		}
		for (int k = 0; k < Cardmuch; k++) {
			cin >> idx;
			q2->enqueue(idx);
		}
		for (int l = 0; l < Cardmuch; l++) {
			a_idx = q1->dequeue();
			a_idx += PlusA;
			b_idx = q2->dequeue();
			b_idx += PlusB;
			if (a_idx > b_idx) {
				q1->getScore();
				PlusA = a_idx - b_idx - 1;
				PlusB = 0;
			}
			else if (a_idx < b_idx) {
				q2->getScore();
				PlusB = b_idx - a_idx - 1;
				PlusA = 0;
			}
		}
		if (q1->score > q2->score) {
			cout << 1 << endl;
		}
		else if (q1->score < q2->score) {
			cout << 2 << endl;
		}
		else
			cout << 0 << endl;
		delete q1;
		delete q2;
	}
	return 0;
}