#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
public:
	vector<Node*> chi;
	Node* parent;
	Node* child;
	int data;
	Node(int X) {
		this->data = X;
		this->parent = NULL;
		this->child = NULL;
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
			par->child = newNode;
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

	int printDepth(int X) {
		Node* findD = findNode(X);
		if (findD == NULL) {
			return -1;
		}
		else {
			int count = 0;
			while (findD->parent != NULL) {
				findD = findD->parent;
				count++;
			}
			return count;
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

	void printheight() {
		int size = list.size();
		int max = 0;
		for (int i = 0; i < size; i++) {
			if (max < printDepth(list[i]->data)){
				max = printDepth(list[i]->data);
			}
		}
		cout << max << endl;
	}
};

int main() {
	int much = 0;
	int parX = 0;
	int chiY = 0;
	int many = 0;
	string tmp;
	cin >> much;
	for (int i = 0; i < much; i++) {
		Tree tree(1);
		cin >> many;
		for (int j = 0; j < many; j++) {
			cin >> parX;
			cin >> chiY;
			tree.insert(parX, chiY);
		}
		tree.preorder(1);
		cout << endl;
		tree.postorder(1);
		cout << endl;
		tree.printheight();
	}
	return 0;
}