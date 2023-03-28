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
	int depth;
	Tree() {
		this->root = NULL;
		this->depth = NULL;
	}
	Tree(int e) {
		root = new Node(e);
		list.push_back(root);
		this->depth = 0;
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
		Node* findChild = findNode(X);
		if (findChild == NULL) {
			cout << -1 << endl;
		}
		else {
			int size = findNode(X)->chi.size();
			if (size == 0) {
				cout << 0 << endl;
			}
			else {
				for (int i = 0; i < size; i++) {
					cout << findNode(X)->chi[i]->data << " ";
				}
				cout << endl;
			}
		}
	}

	Node* findNode(int e) {
		int size = list.size();
		for (int i = 0; i < size; i++) {
			if (e == list[i]->data) {
				return list[i];
			}
		}
		return NULL;
	}

	void printDepth(int e) {
		int count = 0;
		Node* findDepth = findNode(e);
		if (findDepth == NULL) {
			cout << -1 << endl;
		}
		else {
			while (findDepth->parent != NULL) {
				findDepth = findDepth->parent;
				count++;
			}
			cout << count << endl;
		}
		delete findDepth;
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

	void preorder(int e) {
		Node* pre = findNode(e);
		cout << pre->data << " ";
		if (pre->child == NULL) {
			return;
		}
		else {
			int size = pre->chi.size();
			for (int i = 0; i < size; i++) {
				preorder(pre->chi[i]->data);
			}
			return;
		}
	}

	void postorder(int e) {
		Node* post = findNode(e);
		int size = post->chi.size();
		for (int i = 0; i < size; i++) {
			postorder(post->chi[i]->data);
		}
		cout << post->data << " ";
	}

};

int main() {
	int much;
	int P;
	int C;
	int treemany;
	cin >> much;
	for (int i = 0; i < much; i++) {
		Tree* tree = new Tree(1);
		cin >> treemany;
		for (int j = 0; j < treemany; j++) {
			cin >> P >> C;
			tree->Insert(P, C);
		}
		tree->preorder(1);
		cout << endl;
		tree->postorder(1);
		cout << endl;
		delete tree;
	}
	return 0;
}