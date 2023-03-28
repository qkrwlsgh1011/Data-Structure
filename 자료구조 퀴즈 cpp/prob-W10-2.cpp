#include <iostream>
using namespace std;

class Node {
public:
	Node* left;
	Node* right;
	Node* parrent;
	int data;
	Node(int e) {
		this->data = e;
		this->left = NULL;
		this->right = NULL;
		this->parrent = NULL;
	}
	~Node() {

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
		this->destroyTree(this->root);
	}

	void insertNode(int data) {
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
			if (par->data < data) {
				par->right = newNode;
				newNode->parrent = par;
			}
			else {
				par->left = newNode;
				newNode->parrent = par;
			}
			if (this->height < height) {
				this->height = height;
			}
		}
	}

	void deleteNode(int data) {
		Node* tmp = findNode(data);
		Node* reptmp = NULL;
		if (tmp == NULL) {									//tmp�� ��ã��
			return;
		}
		else if (tmp->left == NULL && tmp->right == NULL) {	//�ڽ��� �Ѵپ���
			if (tmp->parrent != NULL) {						//�θ� ���� ��(root�� �ƴ� ��)
				if (tmp->parrent->left == tmp) {				//�ڱⰡ ���ʿ� ���� ��
					tmp->parrent->left = NULL;				//������ ����
				}
				else {										//�ڱⰡ �����ʿ� ���� ��
					tmp->parrent->right = NULL;				//�������� ����
				}
			}
			if (tmp == this->root) {						//��������ϴ°��� root�϶�
				this->root = NULL;							//�� ��Ʈ�ϳ��ۿ�������
			}
			delete(tmp);
			return;
		}
		else if ((tmp->left != NULL && tmp->right == NULL) || (tmp->left == NULL && tmp->right != NULL)) {
			//�� �߿� �ϳ��� �ڽ� ���� ��
			if (tmp == this->root) {		//tmp�� ��Ʈ�϶�
				if (tmp->left != NULL) {	//tmp�� ��Ʈ�̰� �����ڽĸ� ���� ��
					this->root = tmp->left;	//��Ʈ�� tmp�� ����
					tmp->left->parrent = NULL;//��Ʈ�� �θ� NULL�� ����
				}
				else {
					this->root = tmp->right;
					tmp->right->parrent = NULL;
				}
			}
			else {							//tmp�� ��Ʈ�� �ƴҶ�
				if (tmp->left != NULL) {	//���� �ڽĸ� ���� ��
					tmp->left->parrent = tmp->parrent;	//tmp�� ���� �ڽ��� �θ�� �θ�
					if (tmp == tmp->parrent->left) {	//tmp�� �θ��� ���ʿ� ���� ��
						tmp->parrent->left = tmp->left;	//tmp�� �θ��� ���� �ڽ��� �����ڽ�
					}
					else{								//tmp�� �θ��� �����ʿ� ���� ��
						tmp->parrent->right = tmp->left;//tmp�� �θ��� ������ �ڽ��� ���� �ڽ�
					}
				}
				else {						//������ �ڽĸ� ���� ��
					tmp->right->parrent = tmp->parrent;
					if (tmp == tmp->parrent->left) {	//tmp�� �θ��� ���ʿ� ���� ��
						tmp->parrent->left = tmp->right;	//tmp�� �θ��� ���� �ڽ��� �������ڽ�
					}
					else {								//tmp�� �θ��� �����ʿ� ���� ��
						tmp->parrent->right = tmp->right;//tmp�� �θ��� ������ �ڽ��� ������ �ڽ�
					}
				}
			}
			delete(tmp);
			return;
		}
		else {								//�Ѵ� �ڽ��� ����
			reptmp = findMinimum(tmp);		//���� �ּڰ� ã��
			if (reptmp->parrent->left == reptmp) {//reptmp�� ���� �ڽ��̶��
				reptmp->parrent->left = reptmp->right;//reptmp�� �����ʰ� ��������ش�.
			}
			else {									//������ �ڽ��̶��
				reptmp->parrent->right = reptmp->right;//reptmp�� ������ �ڽ��� ��������ش�.
			}
			if (reptmp->right != NULL) {			//reptmp�� ������ �ڽ��� �����Ѵٸ�
				if (reptmp->parrent != tmp) {		//reptmp�� �θ� tmp�� �ƴѰ��
					reptmp->right->parrent = reptmp->parrent;//reptmp�� �����ʰ� �θ�� ��������ش�.
				}
			}

			reptmp->parrent = tmp->parrent;			//reptmp�� tmp�� �ٲ��ش�.
			if (tmp->parrent != NULL) {				//tmp�� �θ� �����Ҷ�(��Ʈ�� �ƴҶ�)
				if (tmp == tmp->parrent->left) {	//tmp�� ���ʿ� ���� ��
					tmp->parrent->left = reptmp;
				}
				else {								//tmp�� �����ʿ� ���� ��
					tmp->parrent->right = reptmp;
				}
			}

			reptmp->left = tmp->left;				//������ ���������
			if (tmp->left != NULL) {				//������ �����Ҷ�
				tmp->left->parrent = reptmp;		//���ʿ���
			}
			reptmp->right = tmp->right;
			if (tmp->right != NULL) {
				tmp->right->parrent = reptmp;
			}

			if (tmp == this->root) {				//tmp�� ��Ʈ�ΰ��
				this->root = reptmp;
			}
			delete(tmp);
			return;
		}
	}

	Node* findMinimum(Node* node) {
		Node* tmp = node;
		if (tmp->right == NULL) {	//������ �ڽ��� ���ٸ�
			return NULL;
		}
		else {
			tmp = tmp->right;		//���������� �ѹ�����
			while (tmp->left != NULL) {	//���� ���� �ϴܱ��� ��������
				tmp = tmp->left;
			}
		}
		return tmp;
	}

	Node* findNode(int data) {
		Node* tmp = root;
		while (tmp != NULL) {
			if (tmp->data == data) {
				return tmp;
			}
			else {
				if (tmp->data > data) {
					tmp = tmp->left;
				}
				else
					tmp = tmp->right;
			}
			return NULL;
		}
	}

	void printNode(Node* root) {
		if (this->root == NULL) {
			cout << 0;
			return;
		}
		cout << root->data << " ";
		if (root->left != NULL) {
			this->printNode(root->left);
		}
		if (root->right != NULL) {
			this->printNode(root->right);
		}
	}

	void destroyTree(Node* root) {
		if (root = NULL) {
			return;
		}
		if (root->left != NULL) {
			this->destroyTree(root->left);
		}
		if (root->right != NULL) {
			this->destroyTree(root->right);
		}
		delete(root);
	}

	Node* findRoot() {
		return this->root;
	}
};

int main() {
	int much=0;
	int many=0;
	int data=0;
	int node=0;
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
		bst->printNode(bst->findRoot());
	}
	return 0;
}