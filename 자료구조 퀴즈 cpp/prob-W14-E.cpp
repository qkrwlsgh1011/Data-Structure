#include<iostream>
#include<string>
#include<vector>
using namespace std;

class DoublyEdgeLinkedList;

class vertex {									//vertex class�� ���Ͽ�	
public:
	DoublyEdgeLinkedList* incidentEdgeList;     //������ ��� vertex A�� A�� incident �� ��� edge���� ���߸�ũ�帮��Ʈ�� ������ �ִ�.
	int degree = 0;		//vertex A�� ����
	int data;			//vertex A�� ������ȣ
	bool visited;       //vertex A�� �湮 �Ǿ����� ����
	vertex* prev;       //vertex �Ѱ��� ���߿��Ḯ��Ʈ(vertexLinkedList)�� �����ϴ� �ϳ��� ���� ���� �ֱ� ����
	vertex* next;		//���� ������ ����
	vertex(int data);
	void increase_degree() {	//vertex A�� ������ 1����
		this->degree++;
	}
	void decrease_degree() {	//vertex A�� ������ 1����
		this->degree--;
	}
};

class edge {
public:
	edge* prev;			//edge �Ѱ��� ���߿��Ḯ��Ʈ(edgeLinkedList)�� �����ϴ� �ϳ��� ���� ���� �ֱ� ����
	edge* next;			//���� ������ ����
	edge* myself_InFisrt_incidentEdge;	//������ vertex A�� incident�� edge E�� �ִٰ� ����. �̶� E�� A.incidentEdgeList���� ����(E1)�ϰ�, �׷��� ��ü���� �����ϴ� TotalEdgeLinkedList(E2)���� �����Ѵ�. 
	edge* myself_InSecond_incidentEdge;	//�� ��, E1�� E2�� �ٷ� O(1)�ð��� ���� �����Ҽ��ְ� �����͸� �����Ѵ�. 13�����ǽ� ���ǳ�Ʈ 21���������� ȸ������ ��������� ǥ���� ������� ���� ��Ȳ�� ȭ��ǥ : myself_InTotal_EdgeList, 
	edge* myself_InTotal_EdgeList;		//��������� ǥ���� �������� ȸ�������� ������  �ΰ��� ��Ȳ�� ȭ��ǥ : myself_InFisrt_incidentEdge, myself_InSecond_incidentEdge
	vertex* source;						//������ �����ϴ� source, destination �ΰ��� vertex
	vertex* destination;
	bool discovery;						//�ش� ������ discovery edge����
	bool back;							//�Ǵ� �ش� ������ back edge����
	edge(vertex* a, vertex* b) {
		this->source = a;
		this->destination = b;
		this->myself_InFisrt_incidentEdge = NULL;
		this->myself_InSecond_incidentEdge = NULL;
		this->myself_InTotal_EdgeList = NULL;
		this->discovery = false;
		this->back = false;
	}
};

class DoublyEdgeLinkedList {		//������� �̷���� ���߿��Ḯ��Ʈ(�ǽ� 3������ ������. )
public:
	edge* head;
	edge* tail;
	int size;
	DoublyEdgeLinkedList() {
		this->head = NULL;
		this->tail = NULL;
		this->size = 0;
	}
	void insert(edge* insertEdge) {
		if (this->head == NULL) {
			head = insertEdge;
			tail = insertEdge;
		}
		else {
			tail->next = insertEdge;
			insertEdge->prev = tail;
			tail = insertEdge;
		}
		this->size++;
	}
	void remove(edge* delEdge) {

		if (delEdge == head || delEdge == tail) {
			if (delEdge == head && delEdge != tail) {
				edge* temp = head;
				head = head->next;
				head->prev = NULL;
				delete temp;

			}
			else if (delEdge == tail && delEdge != head) {
				edge* temp = tail;
				tail = tail->prev;
				tail->next = NULL;
				delete temp;

			}
			else { head = tail = NULL; }
		}
		else {
			delEdge->prev->next = delEdge->next;
			delEdge->next->prev = delEdge->prev;
			delete delEdge;
		}
		this->size--;
	}
};

vertex::vertex(int data) {
	this->degree = 0;
	this->data = data;
	this->visited = false;
	vertex* prev = NULL;
	vertex* next = NULL;
	this->incidentEdgeList = new DoublyEdgeLinkedList();
}

class DoublyVertexLinkedList {		//vertex��� �̷���� ���߿��Ḯ��Ʈ(�ǽ� 3������ ������. )
public:
	vertex* head;
	vertex* tail;
	int size;
	DoublyVertexLinkedList() {
		this->head = NULL;
		this->tail = NULL;
		this->size = 0;
	}
	void insert(vertex* insertVertex) {
		if (this->head == NULL) {
			head = insertVertex;
			tail = insertVertex;
		}
		else {
			tail->next = insertVertex;
			insertVertex->prev = tail;
			tail = insertVertex;
		}
		this->size++;
	}
	void remove(vertex* delVertex) {
		if (delVertex == head || delVertex == tail) {
			if (delVertex == head && delVertex != tail) {
				vertex* temp = head;
				head = head->next;
				head->prev = NULL;
				delete temp;
			}
			else if (delVertex == tail && delVertex != head) {
				vertex* temp = tail;
				tail = tail->prev;
				tail->next = NULL;
				delete temp;
			}
			else { head = tail = NULL; }
		}
		else {
			delVertex->prev->next = delVertex->next;
			delVertex->next->prev = delVertex->prev;
			delete delVertex;
		}
		this->size--;
	}
};

class graph {
public:
	DoublyVertexLinkedList* TotalvertexList;			//�׷����� �����ϴ� ��� vertex�� �����ϴ� ���߿��Ḯ��Ʈ
	DoublyEdgeLinkedList* TotaledgeList;				//�׷����� �����ϴ� ��� edge�� �����ϴ� ���߿��Ḯ��Ʈ
	int vertexSize;		//���� vertex �� ����
	graph() {
		this->vertexSize = 0;
		this->TotalvertexList = new DoublyVertexLinkedList();
		this->TotaledgeList = new DoublyEdgeLinkedList();
	}
	bool isFindVertex(int data) {		//������ȣ�� data�� vertex�� VertexLinkedList�� �����ϴ��� ���� ��ȯ
		vertex* tempVertex;
		bool flag = false;
		tempVertex = TotalvertexList->head;
		while (tempVertex != NULL) {
			if (tempVertex->data == data)
			{
				flag = true; break;
			}
			tempVertex = tempVertex->next;
		}
		return flag;
	}
	vertex* findVertex(int data) {			//������ȣ�� data�� vertex�� VertexLinkedList�� �����ϸ� �ش� vertex�� �ּҰ� ��ȯ
		vertex* tempVertex;
		tempVertex = TotalvertexList->head;
		while (tempVertex != NULL) {
			if (tempVertex->data == data)
			{
				break;
			}
			tempVertex = tempVertex->next;
		}
		return tempVertex;
	}
	bool isFindEdge(int source, int destination) {	//������ȣ�� source�� destination�� vertex�� ������� edge�� edgeLinkedList�� �����ϴ��� ���� ��ȯ
		edge* tempEdge;
		bool flag = false;
		tempEdge = TotaledgeList->head;
		while (tempEdge != NULL) {
			if (tempEdge->source->data == source && tempEdge->destination->data == destination ||
				tempEdge->source->data == destination && tempEdge->destination->data == source)
			{
				flag = true; break;
			}
			tempEdge = tempEdge->next;
		}
		return flag;
	}

	edge* findEdge(int source, int destination) {	//������ȣ�� source�� destination�� vertex�� ������� edge�� edgeLinkedList�� �����Ѵٸ� �ش� edge�ּ� ��ȯ
		edge* tempEdge;
		tempEdge = TotaledgeList->head;
		while (tempEdge != NULL) {
			if (tempEdge->source->data == source && tempEdge->destination->data == destination ||
				tempEdge->source->data == destination && tempEdge->destination->data == source)
			{
				break;
			}
			tempEdge = tempEdge->next;
		}
		return tempEdge;
	}

	void insert_vertex(int n) {						//������ȣ�� n�� vertex�� �׷����� ����
		if (vertexSize != 0) {
			if (isFindVertex(n) == true)return;
			else {
				vertex* newVertex = new vertex(n);
				TotalvertexList->insert(newVertex);
				this->vertexSize++;
			}
		}
		else {
			vertex* newVertex = new vertex(n);
			TotalvertexList->insert(newVertex);
			this->vertexSize++;
		}
	}

	void insert_edge(int source, int destination) {
		if (isFindVertex(source) == true && isFindVertex(destination) == true) {
			vertex* srcVertex = findVertex(source);
			vertex* dstVertex = findVertex(destination);
			edge* newEdge = new edge(srcVertex, dstVertex);		//totaledgelist�� �߰��� ���ο� edge (E1)

			TotaledgeList->insert(newEdge);

			edge* tempEdge1 = new edge(srcVertex, dstVertex);		//src.incidentedges �� �߰��� ���ο� edge (E2) 
			edge* tempEdge2 = new edge(srcVertex, dstVertex);		//destination.incidentedges�� �߰��� ���ο� edge(E3)
			tempEdge1->myself_InTotal_EdgeList = newEdge;			//E1,E2�� E3�� �ּҰ���ü�� �ٸ����� ���� ������ �ִ� ��� field���� ����. 
			tempEdge2->myself_InTotal_EdgeList = newEdge;			//�ǽ����ǳ�Ʈ 21���������� ��� ��Ȳ�� ȭ��ǥ���� E1,E2,E3�� �ش�Ǵ��� �����Ͻø� �˴ϴ�.

			srcVertex->incidentEdgeList->insert(tempEdge1);
			dstVertex->incidentEdgeList->insert(tempEdge2);
			newEdge->myself_InFisrt_incidentEdge = tempEdge1;
			newEdge->myself_InSecond_incidentEdge = tempEdge2;

			srcVertex->increase_degree();
			dstVertex->increase_degree();
		}
		else {
			return;
		}
	}
	void erase_edge(int source, int destination) {
		if (isFindEdge(source, destination) == false)return;
		else {
			edge* delEdge = findEdge(source, destination);
			vertex* srcVertex = findVertex(source);
			vertex* dstVertex = findVertex(destination);

			srcVertex->incidentEdgeList->remove(delEdge->myself_InFisrt_incidentEdge);
			dstVertex->incidentEdgeList->remove(delEdge->myself_InSecond_incidentEdge);

			srcVertex->decrease_degree();
			dstVertex->decrease_degree();

			TotaledgeList->remove(delEdge);
		}
	}

	bool isAdj(int temp1, int temp2) {			//������ȣ temp1, temp2�� ���� vertex�� ���� �������� ���� check!!

		bool flag = false;
		vertex* start = findVertex(temp1);
		edge* temp = start->incidentEdgeList->head;
		for (int i = 0; i < start->incidentEdgeList->size; i++, temp = temp->next) {
			if (temp->destination->data == temp2 || temp->source->data == temp2) { flag = true; break; }
		}
		return flag;
	}

	vertex* oppositevertex(int search, edge* incidented) {
		vertex* start = findVertex(search);
		edge* incident = start->incidentEdgeList->head;
		while (incident != NULL) {
			if (incident == incidented) {
				break;
			}
			incident = incident->next;
		}

		if (incident->destination->data == start->data) {
			return incident->source;
		}
		else {
			return incident->destination;
		}
	}

	void DFS(int idx) {
		vertex* start = findVertex(idx);
		if (start->visited == true) {
			return;
		}
		else {
			cout << start->data << " ";
			start->visited = true;
			edge* temp = start->incidentEdgeList->head;
			while (temp != NULL) {
				vertex* end = oppositevertex(idx, temp);
				if (temp->back == true || temp->discovery == true) {
					temp=temp->next;
				}
				else {
					if (end->visited == true) {
						temp->back = true;
						temp = temp->next;
					}
					else {
						temp->discovery = true;
						DFS(end->data);
					}
				}
			}
		}
	}
};

int main() {
	int N, M, K;
	int temp1, temp2;
	cin >> N >> M >> K;

	graph* g = new graph();

	for (int i = 0; i < N; i++) {
		cin >> temp1;
		g->insert_vertex(temp1);

	}

	for (int i = 0; i < M; i++) {
		cin >> temp1 >> temp2;
		if (g->isAdj(temp1, temp2) == true)cout << -1 << endl;
		else g->insert_edge(temp1, temp2);
	}

	g->DFS(K);
}