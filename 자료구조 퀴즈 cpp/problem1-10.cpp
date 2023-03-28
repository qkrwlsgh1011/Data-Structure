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

	int pop() {
		if (head == NULL) {
			cout << "-1" << endl;
		}
		else {
			int tempt;
			tempt = head->data;
			head = head->next;
			return tempt;
			stackCount--;
		}
	}
};

int main() {
	int much;
	cin >> much;
	string tmp;
	int size;
	Stack stack;
	for (int i = 0; i < much; i++) {
		cin >> tmp;
		size = tmp.size();
		for (int j = 0; j < size; j++) {
			if (tmp.at(j) == '+') {
				int cal1 = stack.pop();
				int cal2 = stack.pop();
				int cal = cal1 + cal2;
				stack.push(cal);
			}
			else if (tmp.at(j) == '*') {
				int cal1 = stack.pop();
				int cal2 = stack.pop();
				int cal = cal1 * cal2;
				stack.push(cal);
			}
			else if (tmp.at(j) == '-') {
				int cal1 = stack.pop();
				int cal2 = stack.pop();
				int cal = cal2 - cal1;
				stack.push(cal);
			}
			else {
				int a = tmp[j] - '0';
				stack.push(a);
			}
		}
		cout << stack.pop() << endl;
	}
	return 0;
}