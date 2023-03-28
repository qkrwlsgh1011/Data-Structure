#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
	int data;
	Node* next;

	Node(int e)
	{
		this->data = e;
		this->next = NULL;
	}
};

class LinkedList
{
public:
	Node* f;
	Node* r;
	int score;
	int life;

	LinkedList()
	{
		this->f = NULL;
		this->r = NULL;
		this->score = 0;
		this->life = 0;
	}

	void addEnd(int data)
	{
		Node* newNode = new Node(data);
		if (f == NULL)
		{
			f = r = newNode;
		}
		else
		{
			r->next = newNode;
			r = newNode;
		}
	}

	void isEmpty()
	{
		if (f == NULL)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}

	void front()
	{
		if (f == NULL)
		{
			cout << "Empty" << endl;
		}
		else
			cout << f->data << endl;
	}

	void rear()
	{
		if (f == NULL)
		{
			cout << "Empty" << endl;
		}
		else
			cout << r->data << endl;
	}

	// ------------------------

	int pop()
	{
		if (f == NULL)
		{
			return 0;
		}
		else
		{
			int tmp = f->data;
			Node* tmpNode = f;
			f = f->next;
			delete tmpNode;
			return tmp;
		}
	}

	void getScore()
	{
		this->score++;
	}
};

int main()
{
	int N = 0;
	cin >> N;
	string cmd;
	int data;
	int round;
	int charX;
	int charY;
	while (N--)
	{
		cin >> round;
		LinkedList* X = new LinkedList();
		LinkedList* Y = new LinkedList();

		for (int i = 0; i < round; i++) // make X
		{
			cin >> data;
			X->addEnd(data);
		}
		for (int j = 0; j < round; j++) // make Y
		{
			cin >> data;
			Y->addEnd(data);
		}
		for (int k = 0; k < round; k++) // play
		{
			charX = X->pop();
			charY = Y->pop();
			if (charX > charY)
			{
				X->getScore();
			}
			else if (charX < charY)
			{
				Y->getScore();
			}
		}
		if (X->score > Y->score)
			cout << 1 << endl;
		else if (X->score < Y->score)
			cout << 2 << endl;
		else
			cout << 0 << endl;

		delete X;
		delete Y;
	}
	return 0;
}