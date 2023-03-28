#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
	int data;
	Node* par;
	vector<Node*> chi;

	Node()
	{
		this->data = NULL;
		this->par = NULL;
	}
	Node(int e)
	{
		this->data = e;
		this->par = NULL;
	}
	~Node() {
	}
	void insertChild(Node* chi)
	{
		this->chi.push_back(chi);
		return;
	}
	void delChild(Node* chi)
	{
		for (int i = 0; i < this->chi.size(); i++)
		{
			if (this->chi[i] == chi)
			{
				this->chi.erase(this->chi.begin() + i);
				break;
			}
		}
		return;
	}
};

class GeneralTree
{
private:
	Node* root;
	vector<Node*> nodeList;

public:
	GeneralTree()
	{
		root = NULL;
	}
	GeneralTree(int data)
	{
		root = new Node(data);
		this->nodeList.push_back(root);
	}
	~GeneralTree() {
	}
	void setRoot(int data)
	{
		root = new Node(data);
	}
	Node* getRoot()
	{
		return root;
	}
	void insertNode(int parent_data, int data)
	{
		Node* newNode = new Node(data);
		Node* parNode = this->findNode(parent_data);

		if (parNode == NULL)
			cout << "-1" << endl;
		else
		{
			parNode->insertChild(newNode);
			newNode->par = parNode;
			this->nodeList.push_back(newNode);
		}

	}
	Node* findNode(int data)
	{
		int size = nodeList.size();
		for (int i = 0; i < size; i++)
			if (nodeList[i]->data == data)
				return nodeList[i];
		return NULL;
	}
	void printChild(int data)
	{
		Node* tmp = this->findNode(data);

		if (tmp == NULL)
			cout << "-1" << endl;
		else
		{
			int size = tmp->chi.size();
			if (size == 0)
				cout << "0" << endl;
			else
			{
				for (int i = 0; i < size; i++)
					cout << tmp->chi[i]->data << " ";
				cout << endl;
			}
		}
	}
	int countDepth(int data)
	{
		int depth = 0;
		Node* tmp = this->findNode(data);
		if (tmp == NULL) {
			return -1;
		}
		else {
			int depth = 0;
			while (tmp->par != NULL)
			{
				tmp = tmp->par;
				depth++;
			}
			return depth;
		}
	}
	/*void delNode(int data)
	{
	   Node* tmp = this->findNode(data);
	   int size = tmp->chi.size();

	   for (int i = 0; i < size; i++)
	   {
		  tmp->chi[i]->par = tmp->par;
		  tmp->par->insertChild(tmp->chi[i]);
		  tmp->delChild(tmp->chi[i]);
	   }
	   tmp->par->delChild(tmp);
	   delete tmp;
	}
	void preorder(Node* node)
	{
	   cout << node->data << " ";

	   if (node->chi.size() != 0)
	   {
		  for (int i = 0; i < node->chi.size(); i++)
		  {
			 preorder(node->chi[i]);
		  }
	   }
	   else
		  return;
	   return;
	}
	void postorder(Node* node)
	{
	   if (node->chi.size() != 0)
	   {
		  for (int i = 0; i < node->chi.size(); i++)
		  {
			 postorder(node->chi[i]);
		  }
		  cout << node->data << " ";
	   }
	   else
	   {
		  cout << node->data << " ";
		  return;
	   }
	   return;
	}*/
};

int main()
{
	GeneralTree newTree(1);

	int cmdNum;
	//cout << "처리할 명령어의 갯수를 입력하십시오 : ";
	cin >> cmdNum;
	//cout << "명령어 : insert x y , delete x, printChild x, printDepth x, preorder x" << endl;

	string cmd;

	while (cmdNum--)
	{
		cin >> cmd;
		//cout <<"명령어를 입력해주십시오 : ";

		if (cmd == "insert")
		{
			int input1, input2;
			cin >> input1 >> input2;
			newTree.insertNode(input1, input2);
		}

		else if (cmd == "printChild")
		{
			int input;
			cin >> input;
			newTree.printChild(input);
		}

		else if (cmd == "printDepth")
		{
			int input;
			cin >> input;
			cout << newTree.countDepth(input) << endl;
		}

		/*else if (cmd == "delete")
		{
		   int input;
		   cin >> input;
		   newTree->delNode(input);
		}

		else if (cmd == "preorder")
		{
		   int input;
		   cin >> input;
		   newTree->preorder(newTree->findNode(input));
		   cout << endl;
		}

		else if (cmd == "postorder")
		{
		   int input;
		   cin >> input;
		   newTree->postorder(newTree->findNode(input));
		   cout << endl;
		}*/
	}
	return 0;
}