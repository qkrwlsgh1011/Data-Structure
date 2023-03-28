#include<iostream>
#include<vector>

using namespace std;

class Node {
public:
	int data;
	Node* parrent;
	Node* rChild;
	Node* lChild;

	// ������
	Node() {
		this->data = NULL;
		this->parrent = NULL;
		this->rChild = NULL;
		this->lChild = NULL;
	}
	Node(int data) {
		this->data = data;
		this->parrent = NULL;
		this->rChild = NULL;
		this->lChild = NULL;
	}
	// �Ҹ���
	~Node() {
	}
	// ���� �ڽĿ� �߰�
	void insertlChild(Node* lChild) {
		this->lChild = lChild;
		lChild->parrent = this;
	}
	// ������ �ڽĿ� �߰�
	void insertrChild(Node* rChild) {
		this->rChild = rChild;
		rChild->parrent = this;
	}
	// �ش� ����� �ڽ� �� ���
	void printDegree() {
		int lChild = 0;
		int rChild = 0;
		// lChi, rChi �ִ��� Ȯ��
		if (this->lChild != NULL)
			lChild = 1;
		if (this->rChild != NULL)
			rChild = 1;
		cout << lChild + rChild << ' ';
	}
	// �ش� ����� ���� ���
	void printDepth() {
		int depth = 0;
		Node* tmp = this;
		while (tmp->parrent != NULL) {
			depth++;
			tmp = tmp->parrent;
		}
		cout << depth << endl;
	}
};

class BST {
public:
	Node* root;			// root ���
	int height;			// Ʈ���� ����
	// ������
	BST() {
		root = NULL;
		height = 0;
	}
	// �Ҹ���
	~BST() {
		this->treeDestructor(this->root);
	}
	// ��� ���� ���� (Ʈ���� ���̸� �Բ� ���)
	void insertNode(int data) {
		int height = 0;
		if (root == NULL) {
			root = new Node(data);
		}
		else {
			Node* tmp = root;
			Node* par = NULL;
			while (tmp != NULL) {
				if (tmp->data == data)
					return;
				else {
					par = tmp;
					if (tmp->data < data)
						tmp = tmp->rChild;
					else
						tmp = tmp->lChild;
					height++;
				}
			}
			if (par->data < data)
				par->insertrChild(new Node(data));
			else
				par->insertlChild(new Node(data));
			// Handling height
			if (this->height < height)
				this->height = height;
		}
	}
	// ��� Ž�� ����
	Node* findNode(int data) {
		Node* tmp = root;
		while (tmp != NULL) {
			if (tmp->data == data)
				return tmp;
			else {
				if (tmp->data < data)
					tmp = tmp->rChild;
				else
					tmp = tmp->lChild;
			}
		}
		return NULL;
	}
	// Ʈ���� ���� ���
	void printHeight() {
		cout << this->height << endl;
	}
	// ��� ���� ����
	void deleteNode(int data) {
		Node* tmp = findNode(data);
		Node* repTmp = NULL;
		if (tmp == NULL)
			return;
		// Leaf node
		else if (tmp->lChild == NULL && tmp->rChild == NULL) {
			if (tmp->parrent != NULL) {
				if (tmp->parrent->lChild == tmp)
					tmp->parrent->lChild = NULL;
				else
					tmp->parrent->rChild = NULL;
			}
			if (tmp == this->root)
				this->root = NULL;
			delete(tmp);
			return;
		}
		else if ((tmp->lChild != NULL && tmp->rChild == NULL) || (tmp->lChild == NULL && tmp->rChild != NULL)) {
			if (tmp == this->root) {
				// If node has only left child
				if (tmp->lChild != NULL) {
					this->root = tmp->lChild;
					tmp->lChild->parrent = NULL;
				}

				// If node has only right child
				else {
					this->root = tmp->rChild;
					tmp->rChild->parrent = NULL;
				}
			}
			else {
				// If node has only left child
				if (tmp->lChild != NULL) {
					tmp->lChild->parrent = tmp->parrent;
					if (tmp == tmp->parrent->lChild)
						tmp->parrent->lChild = tmp->lChild;
					else
						tmp->parrent->rChild = tmp->lChild;
				}
				// If node has only right child
				else {
					tmp->rChild->parrent = tmp->parrent;
					if (tmp == tmp->parrent->lChild)
						tmp->parrent->lChild = tmp->rChild;
					else
						tmp->parrent->rChild = tmp->rChild;
				}
			}
			delete(tmp);
			return;
		}
		else {
			repTmp = findMinimum(tmp);
			// repTmp.child and repTmp.parrent
			if (repTmp->parrent->lChild == repTmp)
				repTmp->parrent->lChild = repTmp->rChild;
			else
				repTmp->parrent->rChild = repTmp->rChild;
			if (repTmp->rChild != NULL) {
				if (repTmp->parrent != tmp)
					repTmp->rChild->parrent = repTmp->parrent;
			}

			repTmp->parrent = tmp->parrent;
			if (tmp->parrent != NULL) {
				if (tmp == tmp->parrent->lChild)
					tmp->parrent->lChild = repTmp;
				else
					tmp->parrent->rChild = repTmp;
			}

			repTmp->lChild = tmp->lChild;
			if (tmp->lChild != NULL)
				tmp->lChild->parrent = repTmp;
			repTmp->rChild = tmp->rChild;
			if (tmp->rChild != NULL)
				tmp->rChild->parrent = repTmp;

			if (tmp == this->root)
				this->root = repTmp;
			delete(tmp);
		}
	}
	// node�� ������ �ڽĿ��� �ּڰ� Ž��
	Node* findMinimum(Node* node) {
		Node* tmp = node;
		// If there is no right sub-tree
		if (tmp->rChild == NULL)
			return NULL;
		else {
			tmp = tmp->rChild;
			while (tmp->lChild != NULL)
				tmp = tmp->lChild;
		}
		return tmp;
	}
	// ���� ��ȸ(pre-order traversal) ��� ���
	void printPreorderTraversal(Node* root) {
		if (this->root == NULL) {
			cout << 0;
			return;
		}
		cout << root->data << ' ';
		if (root->lChild != NULL)
			this->printPreorderTraversal(root->lChild);
		if (root->rChild != NULL)
			this->printPreorderTraversal(root->rChild);
	}
	// ���� ��ȸ(post-order traversal)�ϸ� Ʈ���� ��� ��� ���� (�Ҹ��ڿ��� ���)
	void treeDestructor(Node* root) {
		if (root == NULL)
			return;

		if (root->lChild != NULL)
			this->treeDestructor(root->lChild);
		if (root->rChild != NULL)
			this->treeDestructor(root->rChild);
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
		BST* bst = new BST();
		cin >> many;
		while (many--) {
			cin >> data;
			bst->insertNode(data);
		}
		cin >> many;
		while (many--) {
			cin >> node;
			bst->deleteNode(node);
		}
		bst->printPreorderTraversal(bst->root);
		delete bst;
	}
	return 0;
}