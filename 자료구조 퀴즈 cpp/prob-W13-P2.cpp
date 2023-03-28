#include<iostream>
#include<string>

using namespace std;

#define MappingSize 501

class vertex
{
public:
    vertex* prev;            //vertex�� doublylinkedlist�� ����
    vertex* next;            //���� vertex�� ���� vertex�� ����Ű�� ������
    int degree;               //����� edge�� ���� degree
    int data;               //vertex�� ���� ��
    vertex(int data)
    {
        this->degree = 0;
        this->data = data;
    }
    void increase_degree()
    {
        this->degree++;
    }
    void decrease_degree()
    {
        this->degree--;
    }
};

class edge {
public:
    edge* prev;                        //edge�� doublylinkedlist�� ����
    edge* next;                        //���� edge�� ���� edge�� ����Ű�� ������
    vertex* source;                     //edge�� ���� vertex ������
    vertex* destination;               //edge�� ���� vertex ������
    string data;                     //edge�� ���� ��
    edge(vertex* a, vertex* b, string data)
    {
        this->source = a;
        this->destination = b;
        this->data = data;
    }
};

class DoublyVertexLinkedList
{
public:
    vertex* head;
    vertex* tail;
    DoublyVertexLinkedList()
    {
        this->head = NULL;
        this->tail = NULL;
    }
    void insert(vertex* insertVertex)      //vertex�� list�� �������� ����
    {
        if (this->head == NULL)
        {
            head = insertVertex;
            tail = insertVertex;
        }
        else
        {
            tail->next = insertVertex;      //tail�� ���� ��ġ�� ����
            insertVertex->prev = tail;      //���Ե� vertex�� prev �� �Ҵ�
            tail = insertVertex;         //tail�̵�
        }
    }
    void remove(vertex* delVertex)                        //list���� vertex����
    {
        if (delVertex == head || delVertex == tail)            //vertex�� head�� tail�� ���
        {
            if (delVertex == head && delVertex != tail)         //head���
            {
                vertex* temp = head;                     //���� head ����
                head = head->next;                        //head �̵�
                head->prev = NULL;                        //���ο� head�� ���� head ���� ����
                delete temp;                           //���� head ����
            }
            else if (delVertex == tail && delVertex != head)   //tail�̶��
            {
                vertex* temp = tail;                     //���� tail ����
                tail = tail->prev;                        //tail �̵�
                tail->next = NULL;                        //���ο� tail�� ���� tail ���� ����
                delete temp;                           //���� tail ����
            }
            else
            {
                head = tail = NULL;                        //list�� ���Ұ� �ϳ����ٸ�
            }
        }
        else                                       //vertex�� head�� tail �� �ƴ� ���
        {
            delVertex->prev->next = delVertex->next;         //�����Ϸ��� vertex�� ���� vertex�� 
            delVertex->next->prev = delVertex->prev;         //���� vertex ����
            delete delVertex;                           //vertex ����
        }
    }
};

class DoublyEdgeLinkedList
{
public:
    edge* head;
    edge* tail;
    DoublyEdgeLinkedList()
    {
        this->head = NULL;
        this->tail = NULL;
    }
    void insert(edge* insertEdge)
    {
        if (this->head == NULL)
        {
            head = insertEdge;
            tail = insertEdge;
        }
        else
        {
            tail->next = insertEdge;
            insertEdge->prev = tail;
            tail = insertEdge;
        }
    }
    void remove(edge* delEdge)
    {
        if (delEdge == head || delEdge == tail)
        {
            if (delEdge == head && delEdge != tail)
            {
                edge* temp = head;
                head = head->next;
                head->prev = NULL;
                delete temp;
            }
            else if (delEdge == tail && delEdge != head)
            {
                edge* temp = tail;
                tail = tail->prev;
                tail->next = NULL;
                delete temp;
            }
            else
            {
                head = tail = NULL;
            }
        }
        else
        {
            delEdge->prev->next = delEdge->next;
            delEdge->next->prev = delEdge->prev;
            delete delEdge;
        }
    }
};

class graph
{
public:
    edge*** edgeMatrix;                              //Adjacency Matrix
    DoublyVertexLinkedList* VertexList;                  //vertex list
    DoublyEdgeLinkedList* EdgeList;                     //edge list         
    int vertexSize;                                 //vertex ����
    int mappingTable[MappingSize];                     //vertex�� �Է� ������ mapping
    int edgeSize;

    graph()
    {
        this->VertexList = new DoublyVertexLinkedList();
        this->EdgeList = new DoublyEdgeLinkedList();
        this->vertexSize = 0;
        this->edgeSize = 0;
        for (int i = 0; i < MappingSize; i++)            //mapping table �ʱ�ȭ
            mappingTable[i] = -1;
        this->edgeMatrix = new edge * *[1];               //edge�� �ּҸ� �����ϴ� �迭�� �迭
        this->edgeMatrix[0] = new edge * [1];            //edge�� �ּҸ� �����ϴ� �迭
        this->edgeMatrix[0][0] = NULL;                  //edge�� �ּ� �ʱ�ȭ
    }
    bool isfindVertex(int n)
    {
        bool flag = false;
        vertex* temp = VertexList->head;               //head���� Ž��
        while (temp != NULL)                        //tmp�� tail->next �� �� ����
        {
            if (temp->data == n)                     //tmp->data�� n�϶�
            {
                flag = true;                        //Ž�� ����
                break;
            }
            temp = temp->next;                        //tmp�̵�
        }
        return flag;
    }
    vertex* findVertex(int n)
    {
        vertex* temp = VertexList->head;
        while (temp != NULL)
        {
            if (temp->data == n)
            {
                break;
            }
            temp = temp->next;
        }
        return temp;
    }

    void insert_vertex(int n)                           //vertex ����
    {
        if (isfindVertex(n) == true)                     //vertex�� �̹� �ִٸ�
        {
            return;
        }

        else
        {
            edge*** tempMatrix = new edge * *[vertexSize + 1];  //���ο� �� ����
            for (int i = 0; i < vertexSize + 1; i++)
            {
                tempMatrix[i] = new edge * [vertexSize + 1];   //���ο� �� ����
                for (int j = 0; j < vertexSize + 1; j++)      //���� �ʱ�ȭ
                    tempMatrix[i][j] = NULL;
            }

            for (int i = 0; i < vertexSize; i++)            //��� copy
            {
                for (int j = 0; j < vertexSize; j++)
                    tempMatrix[i][j] = this->edgeMatrix[i][j];
            }

            this->edgeMatrix = tempMatrix;                  //��� �ٲٱ�

            vertex* newVertex = new vertex(n);               //���ο� vertex ����
            VertexList->insert(newVertex);                  //���ο� vertex ����
            this->vertexSize++;
            mappingTable[vertexSize - 1] = n;
        }
    }


    void erase_vertex(int n)
    {
        if (isfindVertex(n) == false || vertexSize == 0)            //�����Ϸ��� vertex�� ���ٸ�
        {
            cout << -1 << endl;
            return;
        }
        else
        {
            edge*** tempMatrix = new edge * *[vertexSize - 1];         //���ο� �� ����
            for (int i = 0; i < vertexSize - 1; i++)
            {
                tempMatrix[i] = new edge * [vertexSize - 1];         //���ο� �� ����
                for (int j = 0; j < vertexSize - 1; j++)            //���� �ʱ�ȭ
                    tempMatrix[i][j] = NULL;
            }

            int middleIdx = 0;                                 //mapping table���� vertex����
            for (int i = 0; i < vertexSize; i++)
            {
                if (mappingTable[i] == n)
                    middleIdx = i;
            }
            for (int i = middleIdx; i < vertexSize; i++)
                mappingTable[i] = mappingTable[i + 1];


            for (int i = 0; i < vertexSize; i++)                  //edgeList���� edge����
            {
                if (this->edgeMatrix[middleIdx][i] != NULL)
                {
                    EdgeList->remove(this->edgeMatrix[middleIdx][i]);
                    this->edgeSize--;
                }
            }

            for (int i = 0; i < vertexSize; i++)                  //matrix���� edge�ּ� ����
            {
                for (int j = 0; j < vertexSize; j++)
                {
                    if (i < middleIdx && j < middleIdx)
                        tempMatrix[i][j] = this->edgeMatrix[i][j];

                    else if (i > middleIdx&& j > middleIdx)
                        tempMatrix[i - 1][j - 1] = this->edgeMatrix[i][j];

                    else if (j > middleIdx)
                        tempMatrix[i][j - 1] = this->edgeMatrix[i][j];

                    else if (i > middleIdx)
                        tempMatrix[i - 1][j] = this->edgeMatrix[i][j];
                }
            }
            this->edgeMatrix = tempMatrix;                        //��� �ٲٱ�
            VertexList->remove(findVertex(n));                     //vertex ����
            this->vertexSize--;

            cout << this->edgeSize << " ";

            edge* tmp = EdgeList->head;
            while (tmp != NULL)
            {
                cout << tmp->data << " ";
                tmp = tmp->next;
            }
            cout << endl;
        }
    }

    void insert_edge(int indirectSource, int IndirectDestination, string data)
    {
        if (isfindVertex(indirectSource) == false || isfindVertex(IndirectDestination) == false)         //��߰� ���� vertex�� ���ٸ�
        {
            cout << -1 << endl;
            return;
        }

        int destination = -1;
        int source = -1;
        for (int i = 0; i <= vertexSize; i++)                                                //mapping table���� ��߰� ���� vertex�� ���� ���� Ž��
        {
            if (mappingTable[i] == IndirectDestination)
                destination = i;
            if (mappingTable[i] == indirectSource)
                source = i;
            if (source != -1 && destination != -1)
                break;
        }

        if (edgeMatrix[source][destination] != NULL || edgeMatrix[destination][source] != NULL)            //�����Ϸ��� edge�� �̹� �ִٸ�
        {
            cout << -1 << endl;
            return;
        }

        edge* newEdge = new edge(findVertex(indirectSource), findVertex(IndirectDestination), data);      //���ο� edge ����
        edgeMatrix[source][destination] = newEdge;                                             //��Ŀ� edge�� �ּҰ� �Ҵ�
        edgeMatrix[destination][source] = newEdge;

        findVertex(indirectSource)->increase_degree();                                          //��߰� ���� vertex�� degree ����
        findVertex(IndirectDestination)->increase_degree();

        EdgeList->insert(newEdge);                                                         //edgeList�� edge ����
        this->edgeSize++;
    }

    void erase_edge(int indirectSource, int IndirectDestination)
    {
        int destination = -1;
        int source = -1;
        for (int i = 0; i <= vertexSize; i++)                                                //mapping table���� ��߰� ���� vertex�� ���� ���� Ž��
        {
            if (mappingTable[i] == IndirectDestination)
                destination = i;
            if (mappingTable[i] == indirectSource)
                source = i;
            if (source != -1 && destination != -1)
                break;
        }

        if (edgeMatrix[source][destination] == NULL || edgeMatrix[destination][source] == NULL)            //�����Ϸ��� edge�� ���ٸ�
            return;
        findVertex(indirectSource)->decrease_degree();                                          //��߰� ���� vertex�� degree ����
        findVertex(IndirectDestination)->decrease_degree();

        edge* delEdge = edgeMatrix[source][destination];                                       //edgeList���� edge ����
        EdgeList->remove(delEdge);

        edgeMatrix[source][destination] = NULL;                                                //��Ŀ��� edge�� �ּڰ� ����
        edgeMatrix[destination][source] = NULL;
        this->edgeSize--;
    }

    void isAdjacentTo(int indirectSource, int IndirectDestination)
    {
        if (isfindVertex(indirectSource) == false || isfindVertex(IndirectDestination) == false)         //Ž���Ϸ��� vertex�� ���ٸ�
        {
            cout << -1 << endl;
            return;
        }

        int destination = -1;
        int source = -1;
        for (int i = 0; i <= vertexSize; i++)                                                //mapping table���� ��߰� ���� vertex�� ���� ���� Ž��
        {
            if (mappingTable[i] == IndirectDestination)
                destination = i;
            if (mappingTable[i] == indirectSource)
                source = i;
            if (source != -1 && destination != -1)
                break;
        }

        if (edgeMatrix[source][destination] != NULL || edgeMatrix[destination][source] != NULL)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
};

int main()
{
    graph* newGraph = new graph();

    int n, m, k;
    cin >> n >> m >> k;

    while (n--)
    {
        int i;
        cin >> i;
        newGraph->insert_vertex(i);
    }

    while (m--)
    {
        int s, d;
        string u;
        cin >> s >> d >> u;
        newGraph->insert_edge(s, d, u);
    }

    cout << newGraph->vertexSize << " " << newGraph->edgeSize << endl;

    while (k--)
    {
        int l;
        cin >> l;
        newGraph->erase_vertex(l);
    }


    return 0;
}