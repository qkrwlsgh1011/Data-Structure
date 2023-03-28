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
		if (tmp == NULL) {									//tmp를 못찾음
			return;
		}
		else if (tmp->left == NULL && tmp->right == NULL) {	//자식이 둘다없음
			if (tmp->parrent != NULL) {						//부모가 있을 때(root가 아닐 때)
				if (tmp->parrent->left == tmp) {				//자기가 왼쪽에 있을 때
					tmp->parrent->left = NULL;				//왼쪽을 지움
				}
				else {										//자기가 오른쪽에 있을 때
					tmp->parrent->right = NULL;				//오른쪽을 지움
				}
			}
			if (tmp == this->root) {						//지우고자하는것이 root일때
				this->root = NULL;							//즉 루트하나밖에없을때
			}
			delete(tmp);
			return;
		}
		else if ((tmp->left != NULL && tmp->right == NULL) || (tmp->left == NULL && tmp->right != NULL)) {
			//둘 중에 하나만 자식 있을 때
			if (tmp == this->root) {		//tmp가 루트일때
				if (tmp->left != NULL) {	//tmp가 루트이고 왼쪽자식만 있을 때
					this->root = tmp->left;	//루트는 tmp의 왼쪽
					tmp->left->parrent = NULL;//루트의 부모 NULL로 연결
				}
				else {
					this->root = tmp->right;
					tmp->right->parrent = NULL;
				}
			}
			else {							//tmp가 루트가 아닐때
				if (tmp->left != NULL) {	//왼쪽 자식만 있을 때
					tmp->left->parrent = tmp->parrent;	//tmp의 왼쪽 자식의 부모는 부모
					if (tmp == tmp->parrent->left) {	//tmp가 부모의 왼쪽에 있을 때
						tmp->parrent->left = tmp->left;	//tmp의 부모의 왼쪽 자식은 왼쪽자식
					}
					else{								//tmp가 부모의 오른쪽에 있을 때
						tmp->parrent->right = tmp->left;//tmp의 부모의 오른쪽 자식은 왼쪽 자식
					}
				}
				else {						//오른쪽 자식만 있을 때
					tmp->right->parrent = tmp->parrent;
					if (tmp == tmp->parrent->left) {	//tmp가 부모의 왼쪽에 있을 때
						tmp->parrent->left = tmp->right;	//tmp의 부모의 왼쪽 자식은 오른쪽자식
					}
					else {								//tmp가 부모의 오른쪽에 있을 때
						tmp->parrent->right = tmp->right;//tmp의 부모의 오른쪽 자식은 오른쪽 자식
					}
				}
			}
			delete(tmp);
			return;
		}
		else {								//둘다 자식이 있음
			reptmp = findMinimum(tmp);		//넣을 최솟값 찾기
			if (reptmp->parrent->left == reptmp) {//reptmp가 왼쪽 자식이라면
				reptmp->parrent->left = reptmp->right;//reptmp의 오른쪽과 연결시켜준다.
			}
			else {									//오른쪽 자식이라면
				reptmp->parrent->right = reptmp->right;//reptmp의 오른쪽 자식을 연결시켜준다.
			}
			if (reptmp->right != NULL) {			//reptmp의 오른쪽 자식이 존재한다면
				if (reptmp->parrent != tmp) {		//reptmp의 부모가 tmp가 아닌경우
					reptmp->right->parrent = reptmp->parrent;//reptmp의 오른쪽과 부모와 연결시켜준다.
				}
			}

			reptmp->parrent = tmp->parrent;			//reptmp와 tmp를 바꿔준다.
			if (tmp->parrent != NULL) {				//tmp의 부모가 존재할때(루트가 아닐때)
				if (tmp == tmp->parrent->left) {	//tmp가 왼쪽에 있을 때
					tmp->parrent->left = reptmp;
				}
				else {								//tmp가 오른쪽에 있을 때
					tmp->parrent->right = reptmp;
				}
			}

			reptmp->left = tmp->left;				//왼쪽을 연결시켜줌
			if (tmp->left != NULL) {				//왼쪽이 존재할때
				tmp->left->parrent = reptmp;		//왼쪽연결
			}
			reptmp->right = tmp->right;
			if (tmp->right != NULL) {
				tmp->right->parrent = reptmp;
			}

			if (tmp == this->root) {				//tmp가 루트인경우
				this->root = reptmp;
			}
			delete(tmp);
			return;
		}
	}

	Node* findMinimum(Node* node) {
		Node* tmp = node;
		if (tmp->right == NULL) {	//오른쪽 자식이 없다면
			return NULL;
		}
		else {
			tmp = tmp->right;		//오른쪽으로 한번가고
			while (tmp->left != NULL) {	//왼쪽 제일 하단까지 내려가기
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