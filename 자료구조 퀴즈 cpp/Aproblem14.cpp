#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int e) {
		this->next = NULL;
		this->data = e;
	}
};

class Game {
public:
	int point;
	Node* head;
	Node* tail;

	Game() {
		this->point = 0;
		this->head = NULL;
		this->tail = NULL;
	}

	void input(int stamina) {
		Node* Put = new Node(stamina);
		if (head == NULL) {
			head = tail = Put;
		}
		else {
			tail->next = Put;
			tail = Put;
		}
	}

	int out() {
		int tmp;
		if (head == NULL) {
			return 0;
		}
		else {
			Node* p = head;
			tmp = head->data;
			head = head->next;
			delete p;
			return tmp;
		}
	}

	int getpoint() {
		return point++;
	}

};

int main() {
	int test;
	cin >> test;
	int round;
	int stamina;
	int Xsta;
	int Ysta;
	int BonusX=0;
	int BonusY=0;
	for (int i = 0; i < test; i++) {
		Game X;
		Game Y;
		cin >> round;
		for (int j = 0; j < round; j++) {
			cin >> stamina;
			X.input(stamina);
		}
		for (int j = 0; j < round; j++) {
			cin >> stamina;
			Y.input(stamina);
		}
		for (int i = 0; i < round; i++) {
			Xsta = X.out();
			Ysta = Y.out();
			Xsta += BonusX;
			Ysta += BonusY;
			if (Xsta > Ysta) {
				X.getpoint();
				BonusX = Xsta - Ysta - 1;
				BonusY = 0;
			}
			else if (Ysta > Xsta) {
				Y.getpoint();
				BonusY = Ysta - Xsta - 1;
				BonusX = 0;
			}
			else {
				BonusX = 0;
				BonusY = 0;
			}
		}
		BonusX = 0;
		BonusY = 0;

		if (X.point > Y.point) {
			cout << 1 << endl;
		}
		else if (X.point < Y.point) {
			cout << 2 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
	return 0;
}