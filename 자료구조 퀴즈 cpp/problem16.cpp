#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node {
public:
	int data;
	Node* parent;
	Node* child;
	vector<Node*> chi;
	Node(int e) {
		this->data = e;
		this->parent = NULL;
		this->child = NULL;
	}
	~Node() {
	}
};

class Tree {
public:
	vector<Node*> list;
	Node* root;
	Tree() {
		this->root = NULL;
	}
	Tree(int e) {
		root = new Node(e);
		list.push_back(root);
	}
	~Tree() {
	}

	void Insert(int P, int C) {
		Node* newNode = new Node(C);
		Node* par = findNode(P);
		if (par == NULL) {
			cout << -1 << endl;
		}
		else {
			par->child = newNode;
			newNode->parent = par;
			par->chi.push_back(newNode);
			list.push_back(newNode);
		}
	}

	void printChild(int X) {
		int size = findNode(X)->chi.size();
		Node* findChild = findNode(X);
		if (findChild == NULL) {
			cout << -1 << endl;
		}
		else if(findChild->child==NULL){
			cout << 0 << endl;
		}
		else {
			for (int i = 0; i < size; i++) {
				cout << findNode(X)->chi[i]->data << " ";
			}
			cout << endl;
		}
	}

	Node* findNode(int e) {
		Node* find = NULL;
		int size = list.size();
		for (int i = 0; i < size; i++) {
			if (e == list[i]->data) {
				find = list[i];
				break;
			}
		}
		return find;
	}

	void printDepth(int e) {
		int count = 0;
		Node* findDepth = findNode(e);
		if (findDepth == NULL) {
			cout << -1 << endl;
		}
		else {
			while (findDepth != NULL) {
				findDepth = findDepth->parent;
				count++;
			}
			cout << count - 1 << endl;
		}
		delete findDepth;
	}
};

int main() {
	int much;
	int P;
	int C;
	string tmp;
	Tree tree(1);
	cin >> much;
	for (int i = 0; i < much; i++) {
		cin >> tmp;
		if (tmp == "insert") {
			cin >> P;
			cin >> C;
			tree.Insert(P, C);
		}
		else if (tmp == "printChild") {
			cin >> P;
			tree.printChild(P);
		}
		else if (tmp == "printDepth") {
			cin >> P;
			tree.printDepth(P);
		}
	}
	return 0;
}