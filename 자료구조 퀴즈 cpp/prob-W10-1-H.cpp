#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	Node* next;
	Node* left;
	Node* right;
	Node* parrent;
	int data;
	Node(int e) {
		this->data = e;
		this->next = NULL;
		this->left = NULL;
		this->right = NULL;
		this->parrent = NULL;
	}
	void printDegree() {
		int lChild = 0;
		int rChild = 0;
		// lChi, rChi 있는지 확인
		if (this->left != NULL)
			lChild = 1;
		if (this->right != NULL)
			rChild = 1;
		cout << lChild + rChild;
	}
	// 해당 노드의 깊이 출력
	int printDepth() {
		int depth = 0;
		Node* tmp = this;
		while (tmp->parrent != NULL) {
			depth++;
			tmp = tmp->parrent;
		}
		return depth;
	}
};

class BST {
public:
	Node* root;
	int height;
	BST() {
		this->root = NULL;
		this->height = 0;
	}
	~BST() {
		this->treeDestructor(this->root);
	}

	void insert(int data) {
		int height = 0;
		Node* newNode = new Node(data);
		if (root == NULL) {
			root = newNode;
		}
		else {
			Node* tmp = root;
			Node* par = NULL;
			while (tmp != NULL) {
				if (tmp->data == data) {
					return;
				}
				else {
					par = tmp;
					if (tmp->data > data) {
						tmp = tmp->left;
					}
					else {
						tmp = tmp->right;
					}
					height++;
				}
			}
			if (par->data < data) {	//입력된 값이 크다면
				par->right = newNode;
				newNode->parrent = par;
			}
			else {					//입력된 값이 작다면
				par->left = newNode;
				newNode->parrent = par;
			}
			if (this->height < height) {
				this->height = height;
			}
		}
	}

	void printHeight() {
		cout << this->height << endl;
	}

	Node* findNode(int data) {
		Node* tmp = root;
		while (tmp != NULL) {
			if (tmp->data == data)
				return tmp;
			else {
				if (tmp->data < data)
					tmp = tmp->right;
				else
					tmp = tmp->left;
			}
		}
		return NULL;
	}

	void treeDestructor(Node* root) {
		if (root == NULL)
			return;

		if (root->left != NULL)
			this->treeDestructor(root->left);
		if (root->right != NULL)
			this->treeDestructor(root->right);
		delete(root);
	}
};

int main() {
	int much = 0;
	int many = 0;
	int data = 0;
	int node = 0;
	cin >> much;
	while (much--) {
		BST* bst=new BST();					//객체 생성

		cin >> many;				//자연수 수 입력
		while (many--) {
			cin >> data;			//노드 입력
			bst->insert(data);		//이진탐색트리에 입력
		}
		bst->printHeight();
		delete bst;
	}
	return 0;
}