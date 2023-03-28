#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
public:
	vector<Node*> chi;
	Node* parent;
	int data;
	Node(int X) {
		this->data = X;
		this->parent = NULL;
	}
};

class Tree {
public:
	vector<Node*> list;
	Node* root;
	Tree(int X) {
		root = new Node(X);
		list.push_back(root);
	}

	void insert(int X, int Y) {
		Node* newNode = new Node(Y);
		Node* par = findNode(X);
		if (par == NULL) {
			cout << -1 << endl;
		}
		else {
			newNode->parent = par;
			par->chi.push_back(newNode);
			list.push_back(newNode);
		}
	}

	Node* findNode(int X) {
		int size = list.size();
		for (int i = 0; i < size; i++) {
			if (list[i]->data == X) {
				return list[i];
			}
		}
		return NULL;
	}

	void printChild(int X) {
		Node* find = findNode(X);
		if (find == NULL) {
			cout << -1 << endl;
		}
		else {
			int size = find->chi.size();
			if (size == 0) {
				cout << 0 << endl;
			}
			else {
				for (int i = 0; i < size; i++) {
					cout << find->chi[i]->data << " ";
				}
				cout << endl;
			}
		}
	}

	void printDepth(int X) {
		Node* findD = findNode(X);
		if (findD == NULL) {
			cout << -1 << endl;
		}
		else {
			int count = 0;
			while (findD->parent!=NULL) {
				findD = findD->parent;
				count++;
			}
			cout << count << endl;
		}
	}
};

int main() {
	int much=0;
	int parX=0;
	int chiY=0;
	string tmp;
	cin >> much;
	Tree tree(1);
	for (int i = 0; i < much; i++) {
		cin >> tmp;
		if (tmp == "insert") {
			cin >> parX;
			cin >> chiY;
			tree.insert(parX, chiY);
		}
		else if (tmp == "printChild") {
			cin >> chiY;
			tree.printChild(chiY);
		}
		else if (tmp == "printDepth") {
			cin >> chiY;
			tree.printDepth(chiY);
		}
	}
	return 0;
}