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
private:
	vector<Node*> list;
	Node* root;
public:
	Tree() {
		root = NULL;
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
			newNode->parent = par;
			par->chi.push_back(newNode);
			list.push_back(newNode);
		}
	}

	void printChild(int X) {
		Node* findChild = findNode(X);
		if (findChild == NULL) {
			cout << -1 << endl;
		}
		else {
			int size = findChild->chi.size();
			if (size == 0)
				cout << 0 << endl;
			else {
				for (int i = 0; i < size; i++) {
					cout << findChild->chi[i]->data << " ";
				}
				cout << endl;
			}
		}
	}

	Node* findNode(int e) {
		int size = list.size();
		for (int i = 0; i < size; i++) {
			if (list[i]->data==e) {
				return list[i];
			}
		}
		return NULL;
	}

	int countDepth(int data)
	{
		Node* tmpNode = findNode(data);
		if (tmpNode == NULL)
			return -1;
		else
		{
			int depth = 0;
			while (tmpNode->parent != NULL)
			{
				tmpNode = tmpNode->parent;
				depth++;
			}
			return depth;
		}
	}

};

int main() {
	int much;
	int P;
	int C;
	string tmp=" ";
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
			cout << tree.countDepth(P) << endl;
		}
	}
	return 0;
}